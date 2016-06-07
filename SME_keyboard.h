/* 
 * File:   SME_keyboard.h
 * Author: Sam
 *
 * Created on 24 May 2016, 19:10
 */

#ifndef SME_KEYBOARD_H
#define	SME_KEYBOARD_H

#include <SME_keys.h>

namespace SME { namespace Keyboard {
    bool KeyStates [sizeof(SME::Keyboard::OSScancodeTable) / sizeof(SME::Keyboard::Key::SME_KEY_UNKNOWN)] {
        false
    };
}}

#endif	/* SME_KEYBOARD_H */

