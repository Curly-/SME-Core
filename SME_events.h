/* 
 * File:   SME_events.h
 * Author: Sam
 *
 * Created on 22 May 2016, 00:50
 */

#ifndef SME_EVENTS_H
#define	SME_EVENTS_H

#include "SME_event_types.h"

namespace SME { namespace Events {
    /*
     * Initialises events
     */
    void init();
    
    /*
     * Sets event to the next event in the deque and removes it
     * \return whether there are any more events to be returned
     */
    bool getEvent(Event &event);
    
    /*
     * Adds an event to the deque
     */
    void createEvent(Event event);
}}

#endif	/* SME_EVENTS_H */

