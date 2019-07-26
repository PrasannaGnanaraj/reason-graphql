let component = ReasonReact.statelessComponent("Users");
let str = ReasonReact.string;

type permission = {
  name:option(string),
  description:option(string)
}
type role = {
  id:string,
  name:option(string),
  description:option(string),
  permissions:option(array(option(permission)))
}
type user = {
  id: string,
  name: string,
  createdAt: option(string),
  roles:option(array(option(role)))
};
type users = List(user);

type roles = List(role);

type permissons = List(permission);

module Styles = {
  open Css;
  let styledList = style([listStyleType(none),margin(zero)]);
  let styledUl = style([padding(zero)]);
  let userContainer = style([padding(rem(2.0))]);
};

module ViewAll = [%graphql
  {|
    query findAll($appId:ID!){
      users(appId: $appId,where:{})@bsRecord
      {
        id
        name
        createdAt
        roles @bsRecord {
          id
          name
          description
          permissions @bsRecord{
            name
            description
          }
        }
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
let displayDetails = entity => <li className=Styles.styledList> {entity.name |> str} </li>;

let make = (~cls="", _children) => {
  ...component,
  render: _self => {
    let viewQuery = ViewAll.make(~appId="default", ());
    <div className=cls>
      <CreateNewMutationComponent>
      ...{
        (mutation,_)=>{
          let createNewMutation = CreateNew.make(~appId="deals",~name="Prasanna",~email="prasanna.gnanaraj@alphasights.com",());
          <div>
              // <button
              //   onClick={
              //     _mouseEvent =>
              //       mutation(
              //         ~variables=createNewMutation##variables,
              //         ~refetchQueries=[|"viewUsers"|],
              //         (),
              //       )
              //       |> ignore
              //   }>
              //   // {ReasonReact.string("Add User")}
              // </button>
            </div>;
        }
      }
      </CreateNewMutationComponent>
      <ViewQueryComponent variables=viewQuery##variables>
        ...{({result}) =>
          switch (result) {
          | Loading => <div> {"Loading users!" |> str} </div>
          | Error(error) => <div> {error##message |> str} </div>
          | Data(data) =>
            <div className=Styles.userContainer>
              <ul className=Styles.styledUl>
                {ReasonReact.array(Array.map(displayDetails, data##users))}
              </ul>
            </div>
          }
        }
      </ViewQueryComponent>

    </div>;
  },
};