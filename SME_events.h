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
    void init();
    bool getEvent(Event &event);
    void createEvent(Event event);
}}

#endif	/* SME_EVENTS_H */

