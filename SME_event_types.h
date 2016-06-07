/* 
 * File:   SME_event_types.h
 * Author: Sam
 *
 * Created on 22 May 2016, 01:08
 */

#ifndef SME_EVENT_TYPES_H
#define	SME_EVENT_TYPES_H

#include "SME_keys.h"


namespace SME { namespace Events {
    typedef enum EventType {
        SME_WINDOW,                 /**< Generic window event*/
        SME_WINDOW_CLOSE,
        SME_WINDOW_MAXIMISE,
        SME_WINDOW_MINIMISE,
        SME_WINDOW_RESIZE,
        
        SME_MOUSE,                  /**< Generic mouse event*/
        SME_MOUSE_MOUSEUP,
        SME_MOUSE_MOUSEDOWN,
        SME_MOUSE_MOVE,
        SME_MOUSE_WHEEL,
        
        SME_KEYBOARD,               /**< Generic keyboard event*/
        SME_KEYBOARD_KEYDOWN,
        SME_KEYBOARD_KEYUP
    } EventType;
    
    typedef struct GenericEvent {
        EventType type;             /**< Type of event*/
        unsigned long time;         /**< Time the event was created*/
    } GenericEvent;
    typedef struct WindowEvent {
        EventType type;
        unsigned long time;
        EventType event;            /**< Type of window event*/
        int width;                  /**< New width (if resize)*/
        int height;                 /**< New height (if resize)*/
    } WindowEvent;
    typedef struct MouseEvent {
        EventType type;
        unsigned long time;
        EventType event;
        int x;                      /**< New x position of the cursor (if move)*/
        int y;                      /**< New y position of the cursor (if move)*/
        int xdelta;                 /**< Amount that the cursor has moved on the x axis (if move)*/
        int ydelta;                 /**< Amount that the cursor has moved on the y axis (if move)*/
        int scroll;                 /**< Amount that the mouse wheel has been scrolled. >0=Forward, <0=Backward (if scroll)*/
        int button;                 /**< Mouse button that has been pressed/released (if button)*/
    } MouseEvent;
    typedef struct KeyboardEvent {
        EventType type;
        unsigned long time;
        EventType event;
        bool repeated;              /**< True if key event is repeated*/
        SME::Keyboard::Key scancode;/**< Scancode of key pressed/released*/
        SME::Keyboard::Key keycode; /**< Keycode of key pressed/released*/
    } KeyboardEvent;
    typedef union Event {
        EventType type;
        GenericEvent genericEvent;
        WindowEvent windowEvent;
        MouseEvent mouseEvent;
        KeyboardEvent keyboardEvent;
    } Event;
}}

#endif	/* SME_EVENT_TYPES_H */

