module Styles = {
  open Css;

  let headerStyles =
    style([
      overflow(hidden),
      backgroundColor(dimgray),
      padding2(~v=px(20), ~h=px(10)),
    ]);

  let headerAnchorStyle =
    style([
      Css.float(`left),
      color(black),
      textAlign(center),
      padding(px(12)),
      lineHeight(px(25)),
      borderRadius(px(4)),
      textDecoration(none),
      fontSize(px(25)),
      fontStyle(oblique)
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