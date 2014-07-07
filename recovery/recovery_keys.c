#include <linux/input.h>

#include "common.h"
#include "extendedcommands.h"
#include "recovery_ui.h"

int device_handle_key(int key_code, int visible) {
    if (visible) {
        switch (key_code) {
            case KEY_CAPSLOCK:
            case KEY_DOWN:
            case KEY_VOLUMEDOWN:
            case KEY_MENU:
                return SELECT_ITEM;

            case KEY_LEFTSHIFT:
            case KEY_UP:
            case KEY_VOLUMEUP:
            case KEY_HOME:
                if (!ui_root_menu) {
                    return GO_BACK;
                }
		return NO_ACTION;

            case KEY_POWER:
            case KEY_LEFTBRACE:
            case KEY_ENTER:
            case BTN_MOUSE:
            case KEY_CAMERA:
            case KEY_F21:
            case KEY_SEND:
            case KEY_HOMEPAGE:
            case KEY_SEARCH:
                return HIGHLIGHT_UP;

            case KEY_END:
            case KEY_BACKSPACE:
            case KEY_BACK:
                return HIGHLIGHT_DOWN;
        }
    }

    return NO_ACTION;
}
