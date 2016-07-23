#include "SME_event.h"
#include <vector>
#include <map>

std::map<std::string, std::vector<SME::Event::EventListener *> > listeners;

void SME::Event::registerListener(EventListener *l, std::initializer_list<std::string> types) {
    for (std::string t : types) {
        listeners[t].push_back(l);
    }
}

void SME::Event::sendEvent(Event &event) {
    for (EventListener *l : listeners[event.getType()]) {
        l->onEvent(event);
    }
}

const std::string SME::Event::Event::getType() {
    return type;
}