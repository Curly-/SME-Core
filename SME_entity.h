/* 
 * File:   Entity.h
 * Author: Sam
 *
 * Created on 17 July 2016, 17:18
 */

#ifndef ENTITY_H
#define	ENTITY_H

#include <glm/glm.hpp>
#include <string>
#include <map>
#include <vector>

#include "SME_attachment.h"

namespace SME {
    namespace Level {
        class Level;
        namespace Entity {
            class Entity {
                friend class SME::Level::Level;
            private:
                glm::vec3 pos = glm::vec3(0.f, 0.f, 0.f);
                glm::vec3 vel = glm::vec3(0.f, 0.f, 0.f);
                glm::vec3 rot = glm::vec3(0.f, 0.f, 0.f);
                bool dirty = false;

                std::vector<Attachment *> attachments;
                
            public:
                void markDirty();

                glm::vec3 getPos();
                glm::vec3 getVel();
                glm::vec3 getRot();

                void setPos(glm::vec3 pos);
                void setVel(glm::vec3 vel);
                void setRot(glm::vec3 rot);

                virtual void update() = 0;
                
                void addAttachment(Attachment *att);
                void removeAttachment(Attachment *att);
                
                virtual ~Entity();
            };

            template<typename T>
            Entity *_spawn() {
                return new T;
            }

            void _declareEntityType(std::string uid, Entity*(*e)());

            Entity *spawnEntityByUID(std::string uid);
        }
    }
}

#define SME_REGISTER_ENTITY(T) SME::Level::Entity::_declareEntityType(#T, &SME::Level::Entity::_spawn<T>)

#endif	/* ENTITY_H */

