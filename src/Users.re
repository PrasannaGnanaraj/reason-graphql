let component = ReasonReact.statelessComponent("Users");
let str = ReasonReact.string;
type user = {
  id: string,
  name: string,
  createdAt: option(string),
  permissions: option(array(string)),
};
type users =
  | List(user);
module ViewAll = [%graphql
  {|
    query viewUsers($appId:String!){
      users @bsRecord(appId: $appId)
      {
        id
        name
        createdAt
        permissions
      }
    }
  |}
];

module CreateNew = [%graphql
  {|
    mutation createUser($appId:String!,$name:String!,$email:String!) {
      createUser(data:{
        appId: $appId
        name:  $name
        email: $email
      }){
        id
        name
        email
      }
    }
  |}
];

module ViewQueryComponent = ReasonApollo.CreateQuery(ViewAll);
module CreateNewMutationComponent = ReasonApollo.CreateMutation(CreateNew);
let displayDetails = entity => <li> {entity.name |> str} </li>;

let make = (~cls="", _children) => {
  ...component,
  render: _self => {
    let viewQuery = ViewAll.make(~appId="deals", ());
    <div>
      <ViewQueryComponent variables=viewQuery##variables>
        ...{({result}) =>
          switch (result) {
          | Loading => <div className=cls> {"Loading users!" |> str} </div>
          | Error(error) => <div className=cls> {error##message |> str} </div>
          | Data(data) =>
            <div className=cls>
              <ul>
                {ReasonReact.array(Array.map(displayDetails, data##users))}
              </ul>
            </div>
          }
        }
      </ViewQueryComponent>
      <CreateNewMutationComponent>
      ...{
        (mutation,_)=>{
          let createNewMutation = CreateNew.make(~appId="deals",~name="Prasanna",~email="prasanna.gnanaraj@alphasights.com",());
          <div>
               <button
                 onClick={
                   _mouseEvent =>
                     mutation(
                       ~variables=createNewMutation##variables,
                       ~refetchQueries=[|"viewUsers"|],
                       (),
                     )
                     |> ignore
                 }>
                 {ReasonReact.string("Add User")}
               </button>
             </div>;
        }
      }
      </CreateNewMutationComponent>
    </div>;
  },
};