let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();
let httpLink =
  ApolloLinks.createHttpLink(
    ~uri="http://localhost:8080/graphql",
    (),
  );

  let headerContextLink = ApolloLinks.createContextLink(() => {
    "headers": {"x-admin-token": "secret"}
  });

let instance =
  ReasonApollo.createApolloClient(~link=ApolloLinks.from([|headerContextLink,httpLink|]), ~cache=inMemoryCache, ());

  let login = ()=>
  Js.Promise.(
      Axios.postData("http://localhost:8080/login",{"x-admin-token": "secret"})
      |> then_((response) => resolve(Js.log(response##data)))
      |> catch((error) => resolve(Js.log(error))));