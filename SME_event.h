/* 
 * File:   SME_events.h
 * Author: Sam
 *
 * Created on 22 May 2016, 00:50
 */

#ifndef SME_EVENTS_H
#define	SME_EVENTS_H

#include <vector>
#include <string>
#include <initializer_list>

namespace SME { namespace Event {
    struct Event {
    private:
        const std::string type;
    public:
        Event(std::string type) : type(type) {}
        const std::string getType();
    };
    
    struct EventListener {
        virtual void onEvent(Event &event) = 0;
    };
    
    void registerListener(EventListener *l, std::initializer_list<std::string> types);
    
    void sendEvent(Event &event); //maybe pointers 
}}

#endif	/* SME_EVENTS_H */

