/* 
 * File:   SME_event_types.h
 * Author: Sam
 *
 * Created on 22 May 2016, 01:08
 */

#ifndef SME_EVENT_TYPES_H
#define	SME_EVENT_TYPES_H

#include "SME_scancodes.h"


namespace SME { namespace Events {
    typedef enum EventType {
        SME_WINDOW,
        SME_WINDOW_CLOSE,
        SME_WINDOW_MAXIMISE,
        SME_WINDOW_MINIMISE,
        SME_WINDOW_RESIZE,
        
        SME_MOUSE,
        SME_MOUSE_MOUSEUP,
        SME_MOUSE_MOUSEDOWN,
        SME_MOUSE_MOVE,
        
        SME_KEYBOARD,
        SME_KEYBOARD_KEYDOWN,
        SME_KEYBOARD_KEYUP
    } EventType;
    
    typedef struct GenericEvent {
        EventType type;
        unsigned long time;
    } GenericEvent;
    typedef struct WindowEvent {
        EventType type;
        unsigned long time;
        EventType event;
        int width;
        int height;
    } WindowEvent;
    typedef struct MouseEvent {
        EventType type;
        unsigned long time;
        EventType event;
        int x;
        int y;
        int xdelta;
        int ydelta;
        int dir;
        int button;
    } MouseEvent;
    typedef struct KeyboardEvent {
        EventType type;
        unsigned long time;
        EventType event;
        bool repeated;
        SME::Keyboard::Scancode scancode;
    } KeyboardEvent;
    typedef union Event {
        EventType type;
        GenericEvent genericEvent;
        WindowEvent windowEvent;
        MouseEvent clickEvent;
        KeyboardEvent keyboardEvent;
    } Event;
}}

#endif	/* SME_EVENT_TYPES_H */

