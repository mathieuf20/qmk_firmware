#include "lily58.h"

void print_hydra_logo(void) {
    static const char PROGMEM hydra_logo[] = {
        // 'heilhydra', 128x32px
        0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfc, 0x7c, 0x3e, 0x1e, 0x1f, 0x1e, 
        0x1e, 0x1e, 0x1e, 0x3e, 0x7c, 0xfc, 0xfc, 0xf8, 0xf0, 0xf0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xff, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0xff, 0x00, 0x00, 0x00, 0xe0, 0xf0, 
        0x90, 0x98, 0x98, 0xf0, 0xe0, 0x00, 0x00, 0xfb, 0xfb, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfc, 0x7c, 0x3e, 0x1e, 0x1f, 0x1e, 
        0x1e, 0x1e, 0x1e, 0x3e, 0x7c, 0xfc, 0xfc, 0xf8, 0xf0, 0xf0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0xf0, 0xfe, 0xc7, 0x83, 0x19, 0x39, 0x39, 0x79, 0x43, 0x07, 0x1c, 0x40, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x40, 0x1c, 0x07, 0x43, 0x79, 0x39, 0x39, 0x19, 0x83, 0xc7, 0xfe, 0xf0, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x03, 0x07, 
        0x0c, 0x08, 0x0c, 0x04, 0x06, 0x00, 0x00, 0x0f, 0x0f, 0x00, 0x00, 0x0f, 0x0f, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0xf0, 0xfe, 0xc7, 0x83, 0x19, 0x39, 0x39, 0x79, 0x43, 0x07, 0x1c, 0x40, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x40, 0x1c, 0x07, 0x43, 0x79, 0x39, 0x39, 0x19, 0x83, 0xc7, 0xfe, 0xf0, 0x00, 
        0x00, 0x0f, 0x7f, 0xf1, 0xc0, 0x18, 0x3c, 0x3e, 0x3e, 0x0c, 0x04, 0x88, 0xc0, 0xe0, 0xe4, 0x20, 
        0x22, 0xe4, 0xe1, 0xc0, 0x88, 0x04, 0x0c, 0x3e, 0x3e, 0x3c, 0x18, 0xc0, 0xf1, 0x7f, 0x0f, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 
        0x00, 0x00, 0x00, 0xc0, 0x80, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 
        0x80, 0x80, 0xf8, 0xf8, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x80, 0xc0, 0x00, 0x00, 0x80, 0xc0, 0xc0, 
        0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x0f, 0x7f, 0xf1, 0xc0, 0x18, 0x3c, 0x3e, 0x3e, 0x0c, 0x04, 0x88, 0xc0, 0xe0, 0xe4, 0x20, 
        0x22, 0xe4, 0xe1, 0xc0, 0x88, 0x04, 0x0c, 0x3e, 0x3e, 0x3c, 0x18, 0xc0, 0xf1, 0x7f, 0x0f, 0x00, 
        0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0e, 0x0e, 0x1e, 0x1c, 0x38, 0x31, 0x23, 0x63, 0x63, 0x70, 
        0x70, 0x73, 0x63, 0x33, 0x31, 0x38, 0x3c, 0x1e, 0x1e, 0x0e, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x7f, 
        0x00, 0x00, 0x00, 0x01, 0x0f, 0x7c, 0xf0, 0x7c, 0x0f, 0x01, 0x00, 0x00, 0x1f, 0x3f, 0x60, 0x60, 
        0x20, 0x31, 0x7f, 0x7f, 0x00, 0x00, 0x7f, 0x7f, 0x01, 0x00, 0x00, 0x00, 0x39, 0x7d, 0x64, 0x24, 
        0x24, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x63, 0x63, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0e, 0x0e, 0x1e, 0x1c, 0x38, 0x31, 0x23, 0x63, 0x63, 0x70, 
        0x70, 0x73, 0x63, 0x33, 0x31, 0x38, 0x3c, 0x1e, 0x1e, 0x0e, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(hydra_logo, sizeof(hydra_logo));
}

void print_sherweb_logo(void) {
    static const char PROGMEM sherweb_logo[] = {
        // 'sherweb', 128x32px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0xe0, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x80, 0xe0, 0xf0, 0xf8, 0x60, 0x04, 0x0e, 0x0e, 0x1f, 0x3e, 0x3e, 0x3c, 0x38, 0x38, 
        0x10, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xf0, 0x38, 0x38, 0x38, 0x38, 0x38, 0x70, 
        0x70, 0x20, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x70, 0x30, 0x38, 0x70, 0x70, 0xf0, 0xe0, 
        0x80, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0x70, 0x70, 0x30, 0x38, 0x30, 0x70, 0xf0, 0xe0, 0xe0, 
        0x80, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xe0, 0xe0, 0xe0, 0x70, 0x30, 0x00, 0x00, 0xf0, 0xf0, 0xe0, 
        0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0xf0, 0x80, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf0, 0x30, 0x00, 
        0x80, 0xe0, 0xe0, 0xf0, 0x70, 0x30, 0x38, 0x30, 0x70, 0x70, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 
        0xff, 0xff, 0xff, 0xe0, 0xf0, 0x70, 0x30, 0x38, 0x30, 0x70, 0x70, 0xf0, 0xe0, 0xc0, 0x80, 0x00, 
        0x00, 0x07, 0x1f, 0x1f, 0x4f, 0xc3, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x78, 0xfe, 
        0x7f, 0x3f, 0x0f, 0x06, 0x00, 0x00, 0x00, 0x83, 0x87, 0x87, 0x87, 0x0e, 0x0e, 0x0e, 0x0c, 0x9c, 
        0xfc, 0xf8, 0xf0, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 
        0xff, 0x00, 0x00, 0x3f, 0xff, 0xff, 0xde, 0x8c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x8c, 0xcf, 0xcf, 
        0x8f, 0x0e, 0x00, 0x00, 0xff, 0xff, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 
        0xfe, 0xf0, 0xf8, 0xff, 0x3f, 0x07, 0x1f, 0xff, 0xfc, 0xf0, 0xfc, 0xff, 0x3f, 0x01, 0x00, 0x1e, 
        0x7f, 0xff, 0xff, 0x8c, 0x8c, 0x0c, 0x0c, 0x0c, 0x0c, 0x8c, 0x8c, 0xcf, 0x8f, 0x0f, 0x00, 0x00, 
        0xff, 0xff, 0xff, 0xe1, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xf3, 0xff, 0x7f, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x03, 0x02, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
        0x03, 0x01, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 
        0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 
        0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00,
        0x03, 0x03, 0x03, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00
    };

    oled_write_raw_P(sherweb_logo, sizeof(sherweb_logo));
}