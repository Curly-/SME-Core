#include "SME_events.h"
#include "SME_timer.h"
#include <deque>

std::deque<SME::Events::Event> events; //stores events in order of creation
SME::Timer eventTimer; //used to track when an event was created relative to when the game was started

void SME::Events::init() {
    eventTimer.reset();
    eventTimer.start();
}

bool SME::Events::getEvent(Event &event) {
    if (events.size() > 0) {
        event = events[0];
        events.pop_front();
        return true;
    }
    return false;
}

void SME::Events::createEvent(Event event) {
    event.genericEvent.time = eventTimer.getTime();
    events.push_back(event);
}