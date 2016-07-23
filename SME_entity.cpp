#include "SME_entity.h"
#include <algorithm>

using namespace SME::Level::Entity;

glm::vec3 Entity::getPos() {
    return pos;
}

glm::vec3 Entity::getRot() {
    return rot;
}

glm::vec3 Entity::getVel() {
    return vel;
}

void Entity::setPos(glm::vec3 pos) {
    if (!glm::all(glm::equal(pos, this->pos))) { //if pos changed
        markDirty();
        
        for (Attachment *att : attachments) {
            att->onPosChanged(pos);
        }
    }
    
    this->pos = pos;
}

void Entity::setVel(glm::vec3 vel) {
    if (!glm::all(glm::equal(vel, this->vel))) { //if vel changed
        markDirty();
        
        for (Attachment *att : attachments) {
            att->onVelChanged(pos);
        }
    }

    this->vel = vel;
}

void Entity::setRot(glm::vec3 rot) {
    if (!glm::all(glm::equal(rot, this->rot))) { //if rot changed
        markDirty();
        
        for (Attachment *att : attachments) {
            att->onRotChanged(pos);
        }
    }

    this->rot = rot;
}

void Entity::update() {
    for (Attachment *att : attachments) {
        att->onUpdate();
    }
}

void Entity::markDirty() {
    dirty = true;
}

void Entity::addAttachment(Attachment *att) {
    attachments.push_back(att);
}

void Entity::removeAttachment(Attachment *att) {
    attachments.erase(std::remove(
            attachments.begin(),
            attachments.end(),
            att), attachments.end());
    delete att;
}

Entity::~Entity() {
    for (Attachment *att : attachments) {
        delete att;
    }
}

std::map<std::string, Entity*(*)() > declaredEntities;

void SME::Level::Entity::_declareEntityType(std::string uid, Entity*(* e)()) {
    declaredEntities[uid] = e;
}

Entity *SME::Level::Entity::spawnEntityByUID(std::string uid) {
    return declaredEntities.at(uid)();
}