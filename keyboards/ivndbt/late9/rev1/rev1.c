/* Copyright 2021 ivndbt
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "quantum.h"

// OLED logo
#ifdef OLED_ENABLE
bool oled_task_kb(void) {
    if (!oled_task_user()) { return false; }
        static const char PROGMEM rb_logo[] = {
            // ivndbt 128x32px
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xe0, 0x78, 0x78, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xe1, 0xe1, 0xf8, 0xf8, 
            0x00, 0x00, 0x80, 0x80, 0x06, 0x06, 0xff, 0xff, 0xff, 0xff, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x98, 0xcc, 0x00, 0x80, 0xc0, 0xe0, 
            0x00, 0x00, 0x00, 0xc0, 0xe0, 0x00, 0x80, 0xc0, 0xe0, 0x80, 0x40, 0x20, 0xe0, 0xe0, 0x00, 0x00, 
            0xc0, 0xe0, 0x20, 0x60, 0xc8, 0xfc, 0xfc, 0x00, 0x10, 0xf8, 0xfc, 0x80, 0x40, 0x60, 0xe0, 0xc0, 
            0x00, 0x50, 0xf8, 0xfc, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x20, 0x20, 0x60, 0xc0, 
            0xe0, 0x00, 0x80, 0xc0, 0x20, 0x60, 0xe0, 0xc0, 0x80, 0x00, 0x80, 0xc0, 0xe0, 0x80, 0x40, 0xe0, 
            0xe0, 0x80, 0x40, 0xe0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0xff, 0xff, 0xff, 0xff, 
            0x60, 0x60, 0x01, 0x01, 0x00, 0x00, 0x1f, 0x1f, 0x87, 0x87, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x1f, 0x1f, 0x08, 0x00, 0x07, 0x0f, 
            0x1c, 0x18, 0x08, 0x07, 0x03, 0x00, 0x00, 0x1f, 0x1f, 0x08, 0x00, 0x00, 0x1f, 0x1f, 0x08, 0x00, 
            0x07, 0x0f, 0x1c, 0x18, 0x08, 0x1f, 0x1f, 0x08, 0x00, 0x1f, 0x1f, 0x10, 0x10, 0x10, 0x0f, 0x07, 
            0x00, 0x00, 0x1f, 0x1f, 0x08, 0x04, 0x00, 0x18, 0x18, 0x00, 0x07, 0x0f, 0x1c, 0x18, 0x10, 0x10, 
            0x08, 0x00, 0x07, 0x0f, 0x1c, 0x18, 0x10, 0x0f, 0x07, 0x00, 0x00, 0x1f, 0x1f, 0x00, 0x00, 0x1f, 
            0x1f, 0x00, 0x00, 0x1f, 0x1f, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        };
    oled_write_raw_P(rb_logo, sizeof(rb_logo));
    return false;
}

#endif
