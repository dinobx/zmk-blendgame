#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/outputs.h>
#include "keys_de.h"

#define APT 0
#define NUM 1
#define NAV 2
#define SYM 3
#define DE 4

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

/ {
    combos {
        compatible = "zmk,combos";
/* usually on base layer */
        combo_q {
            timeout-ms = <40>;
            key-positions = <2 3>;
            bindings = <&kp Q>;
            layers = <APT>;
        };
        combo_z {
            timeout-ms = <40>;
            key-positions = <20 21>;
            bindings = <&kp DE_Z>;
        };
        combo_v {
            timeout-ms = <40>;
            key-positions = <1 2>;
            bindings = <&kp V>;
            layers = <APT>;
        };
        combo_b {
          timeout-ms = <40>;
          key-positions = <12 3>;
          bindings = <&kp B>;
          layers = <APT>;
        };
        combo_k {
          timeout-ms = <20>;
          key-positions = <12 13>;
          bindings = <&kp K>;
          layers = <APT>;
        };
        combo_x {
          timeout-ms = <20>;
          key-positions = <16 17>;
          bindings = <&kp X>;
          layers = <APT>;
        };
        combo_j {
            timeout-ms = <40>;
            key-positions = <6 17>;
            bindings = <&kp J>;
            layers = <APT>;
        };
        combo_sch {
            timeout-ms = <40>;
            key-positions = <11 13>;
            bindings = <&macro_sch>;
            layers = <APT>;
        };
        combo_sz {
          timeout-ms = <30>;
          key-positions = <30 11>;
          bindings = <&kp DE_SZ>;
        };
        combo_ue {
          timeout-ms = <30>;
          key-positions = <30 8>;
          bindings = <&kp DE_UE>;
        };
        combo_ae {
          timeout-ms = <30>;
          key-positions = <30 17>;
          bindings = <&kp DE_AE>;
        };
        combo_oe {
          timeout-ms = <30>;
          key-positions = <30 19>;
          bindings = <&kp DE_OE>;
        };
        combo_ent {
          timeout-ms = <40>;
          key-positions = <23 24>;
          bindings = <&kp ENTER>;
        };
        combo_esc {
            timeout-ms = <40>;
            key-positions = <21 22>;
            bindings = <&kp ESC>;
        };
/* parentheticals */
/* caps */
        combo_caps-word {
            timeout-ms = <40>;
            key-positions = <13 16>;
            bindings = <&caps_word>;
        };
        combo_capslock {
            timeout-ms = <40>;
            key-positions = <0 9>;
            bindings = <&kp CAPSLOCK>;
        };
/* deletion */
        combo_bspc {
            timeout-ms = <40>;
            key-positions = <6 7>;
            bindings = <&kp BSPC>;
        };
        combo_del {
            timeout-ms = <40>;
            key-positions = <7 8>;
            bindings = <&kp DEL>;
        };
        combo_delword {
            timeout-ms = <40>;
            key-positions = <6 8>;
            bindings = <&kp LC(BSPC)>;
        };
    };
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
            hold-trigger-key-positions = <5 6 7 8 9 15 16 17 18 19 23 24 25 26 27 28 29 30 31 32 33>;
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
            hold-trigger-key-positions = <0 1 2 3 4 10 11 12 13 14 20 21 22 27 28 29 30 31 32 33>;
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
            hold-trigger-key-positions = <0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33>;
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
