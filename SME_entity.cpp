#include "SME_entity.h"

glm::vec3 SME::Level::Entity::getPos() {
    return pos;
}

glm::vec3 SME::Level::Entity::getRot() {
    return rot;
}

glm::vec3 SME::Level::Entity::getVel() {
    return vel;
}

void SME::Level::Entity::setPos(glm::vec3 pos) {
    if (!glm::all(glm::equal(pos, this->pos))) { //if pos changed
        markDirty();
    }
    
    this->pos = pos;
}

void SME::Level::Entity::setVel(glm::vec3 vel) {
    if (!glm::all(glm::equal(vel, this->vel))) { //if vel changed
        markDirty();
    }
    
    this->vel = vel;
}

void SME::Level::Entity::setRot(glm::vec3 rot) {
    if (!glm::all(glm::equal(rot, this->rot))) { //if rot changed
        markDirty();
    }
    
    this->rot = rot;
}

void SME::Level::Entity::markDirty() {
    dirty = true;
}

std::map<std::string, SME::Level::Entity*(*)()> declaredEntities;

void SME::Level::_declareEntityType(std::string uid, Entity*(* e)()) {
    declaredEntities[uid] = e;
}

SME::Level::Entity *SME::Level::spawnEntityByUID(std::string uid) {
    return declaredEntities[uid]();
}