module Styles = {
  open Css;
  let sidenav =
    style([
      height(vh(100.0)),
      width(px(160)),
      left(zero),
      backgroundColor(black),
      overflowX(hidden),
      paddingTop(px(20)),
    ]);

  let anchorBase =
    style([
      padding4(~top=px(6), ~right=px(8), ~bottom=px(6), ~left=px(16)),
      textDecoration(none),
      fontSize(rem(1.4)),
      color(gray),
      display(block),
    ]);
  let anchorHover = style([hover([color(white)])]);

  let anchorStyle = merge([anchorBase, anchorHover]);
};
let component = ReasonReact.statelessComponent("Sidebar");

let anchorItem = (~anchorText,~style=Styles.anchorBase, ~href=?, ()) => {
  switch (href) {
  | None =>
    <a className=style key=anchorText href={"#" ++ anchorText}>
      {React.string(anchorText)}
    </a>
  | Some(link_) =>
    <a className=Styles.anchorStyle key=anchorText href=link_>
      {React.string(anchorText)}
    </a>
  };
};

let make = (~appOptions,_children) => {
  ...component,
  render: _self => {
    <div className=Styles.sidenav>
      {ReasonReact.array(
         Array.map(el => anchorItem(~anchorText=el,~style=Styles.anchorStyle, ()), appOptions),
       )}
    </div>;
  },
};