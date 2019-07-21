let str = ReasonReact.string;
let component = ReasonReact.statelessComponent("App");

module Styles = {
  open Css;
  let displayFlex =
    style([
      display(`flex),
      flexWrap(nowrap),
      justifyContent(spaceBetween),
      alignItems(stretch),
    ]);
  let flexCol = merge([displayFlex,style([flexDirection(column)])]);
  let flexRow = merge([displayFlex,style([flexDirection(row)])]);
  let flexOne = style([flex(`num(1.0))])
};

let appOptions = [|"Users", "Roles", "Permissions"|];

let make = _children => {
  ...component,
  render: _self => {
    <div className=Styles.flexCol>
      <Header />
      <div className=Styles.flexRow>
        <Sidebar appOptions=appOptions/>
        <Users cls=Styles.flexOne/>
      </div>
    </div>;
  },
};