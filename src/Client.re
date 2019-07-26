let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();
let httpLink =
  ApolloLinks.createHttpLink(
    ~uri="http://localhost:8080/graphql",
    (),
  );

  let headerContextLink = ApolloLinks.createContextLink(() => {
    "headers": {"X-Auth-Admin-Secret": "secret"}
  });

let instance =
  ReasonApollo.createApolloClient(~link=ApolloLinks.from([|headerContextLink,httpLink|]), ~cache=inMemoryCache, ());