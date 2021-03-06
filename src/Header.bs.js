// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Css = require("bs-css/src/Css.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Sidebar$ReactTemplate = require("./Sidebar.bs.js");

var headerStyles = Css.style(/* :: */[
      Css.overflow(Css.hidden),
      /* :: */[
        Css.backgroundColor(Css.white),
        /* :: */[
          Css.padding2(Css.rem(3.0), Css.rem(1.5)),
          /* :: */[
            Css.boxShadow(Css.px(0), Css.px(0), Css.rem(1.0), Css.rem(1.0), undefined, Css.rgba(53, 59, 72, 0.1)),
            /* [] */0
          ]
        ]
      ]
    ]);

var headerAnchorStyle = Css.style(/* :: */[
      Css.color(Css.hex("576574")),
      /* :: */[
        Css.textAlign(Css.center),
        /* :: */[
          Css.lineHeight(Css.px(25)),
          /* :: */[
            Css.borderRadius(Css.px(4)),
            /* :: */[
              Css.textDecoration(Css.none),
              /* :: */[
                Css.fontSize(Css.rem(2.0)),
                /* [] */0
              ]
            ]
          ]
        ]
      ]
    ]);

var Styles = /* module */[
  /* headerStyles */headerStyles,
  /* headerAnchorStyle */headerAnchorStyle
];

var component = ReasonReact.statelessComponent("Header");

function make(_children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (_self) {
              return React.createElement("div", {
                          className: headerStyles
                        }, Sidebar$ReactTemplate.anchorItem("Alphasights", headerAnchorStyle, undefined, /* () */0));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.Styles = Styles;
exports.component = component;
exports.make = make;
/* headerStyles Not a pure module */
