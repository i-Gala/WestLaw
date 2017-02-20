#include "../lib/stdafx.h"
#include "../include/input.h"

#include <conio.h>

Input::Input() {
    m_key = NULL;
}


Input::~Input() {}

bool Input::readKeyboard() {
    bool read = false;

    if (_kbhit()) {
        m_key = _getch();
        read = true;
    }

    return read;
}

const char Input::getKey() {
    char key = m_key;
    m_key = NULL;
    return static_cast<const char>(key);
}
