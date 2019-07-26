module Styles = {
  open Css;

  let headerStyles =
    style([
      overflow(hidden),
      backgroundColor(white),
      padding2(~v=rem(3.0),~h=rem(1.5)),
      boxShadow(~x=px(0),~y=px(0),~blur=rem(1.0),~spread=rem(1.0),rgba(53, 59, 72,0.1))
    ]);

  let headerAnchorStyle =
    style([
      color(hex("576574")),
      textAlign(center),
      lineHeight(px(25)),
      borderRadius(px(4)),
      textDecoration(none),
      fontSize(rem(2.0))
    ]);
};

let component = ReasonReact.statelessComponent("Header");

let make = _children => {
  ...component,
  render: _self => {
    <div className=Styles.headerStyles>
      {Sidebar.anchorItem(~anchorText="Alphasights",~style=Styles.headerAnchorStyle, ())}
    </div>;
  },
};