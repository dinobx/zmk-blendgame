#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/outputs.h>
#include "keys_de.h"

#define QWE 0
#define FUN 1
#define SYM 2
#define NAV 3

// &lt {
//     quick_tap_ms = <170>;
// };

// space invader key numbers
//  ____________________________________________________________
// /  0  |  1  |  2  |  3  |  4       5 |   6 |   7 |   8 |  9  \
// | 10  | 11  | 12  | 13  | 14      15 |  16 |  17 |  18 | 19  |
// | 20  | 21  | 22  | 23  | 24      25 |  26 |  27 |  28 | 29  |
// \ 30  |             31    32      33 |  34             | 35  /
//           --------------              --------------

&caps_word {
    continue-list = <UNDERSCORE MINUS BSPC LSHFT RSHFT>;
};


/ {
  macros {
  macro_sch:
    macro_sch {
      label = "Macro_sch";
      compatible = "zmk,behavior-macro";
      #binding-cells = <0>;
      bindings = <&macro_tap &kp S &macro_release &kp RSHIFT &macro_tap &kp C &kp H>;
    };
  };
};

#define COMBO(NAME, BINDINGS, KEYPOS) \
  combo_##NAME {                      \
    timeout-ms = <20>;                \
    bindings = <BINDINGS>;            \
    key-positions = <KEYPOS>;         \
  };

/ {

    behaviors {
        hl: homerow_mods_left {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods left";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <5 6 7 8 9 15 16 17 18 19 25 26 27 28 29 33 34 35>;
        };
        hr: homerow_mods_right {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods right";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <0 1 2 3 4 10 11 12 13 14 20 21 22 23 24 30 31 32>;
        };

        my_lt: my_layer_taps {
            compatible = "zmk,behavior-hold-tap";
            label = "my layer taps";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&mo &kp>, <&kp>;
            // non-thumb keys
            hold-trigger-key-positions = <0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35>;
        };

        dotcol: dot_colon {
            compatible = "zmk,behavior-mod-morph";
            label = "DOT_COL";
            #binding-cells = <0>;
            bindings = <&kp DOT>, <&kp COLON>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
        comsem: comma_semicolon {
            compatible = "zmk,behavior-mod-morph";
            label = "COM_SEM";
            #binding-cells = <0>;
            bindings = <&kp COMMA>, <&kp SEMI>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
    };
};
