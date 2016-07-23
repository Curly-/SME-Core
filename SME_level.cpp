#include "SME_level.h"

void SME::Level::Level::update() {
    for (Entity::Entity *e : entities) {
        e->update();
    }
}

SME::Level::Entity::Entity *SME::Level::Level::addEntity(std::string uid) {
    SME::Level::Entity::Entity *e = Entity::spawnEntityByUID(uid);
    addEntity(e);
    return e;
}

void SME::Level::Level::addEntity(Entity::Entity *entity) {
    entities.push_back(entity);
}

SME::Level::Level::Level() {
}

SME::Level::Level::~Level() {
    for (std::map<std::string, void *>::iterator it = parameters.begin(); it != parameters.end(); ++it) {
        free(it->second);
    }
    for (Entity::Entity *e : entities) {
        delete e;
    }
}