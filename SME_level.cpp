#include <SME_level.h>
#include <SME_core.h>

void SME::Level::Level::update() {
    for (Entity *e : entities) {
        e->update();
    }
}

void SME::Level::Level::addEntity(std::string uid) {
    addEntity(SME::Level::spawnEntityByUID(uid));
}

void SME::Level::Level::addEntity(Entity* entity) {
    entities.push_back(entity);
}

SME::Level::Level::Level() {
}

SME::Level::Level::~Level() {
    for (std::map<std::string, void *>::iterator it = parameters.begin(); it != parameters.end(); ++it) {
        free(it->second);
    }
    for (Entity *e : entities) {
        delete e;
    }
}