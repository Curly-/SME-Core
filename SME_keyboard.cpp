#include "SME_keyboard.h"

bool SME::Keyboard::KeyStates [sizeof (SME::Keyboard::OSScancodeTable) / sizeof (SME::Keyboard::Key::KEY_UNKNOWN)] {
    false
};
