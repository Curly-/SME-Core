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

namespace SME {
    namespace Level {
        class Entity {
            friend class Level;
        private:
            glm::vec3 pos = glm::vec3(0.f, 0.f, 0.f);
            glm::vec3 vel = glm::vec3(0.f, 0.f, 0.f);
            glm::vec3 rot = glm::vec3(0.f, 0.f, 0.f);
            bool dirty = false;
            
        protected:
            void markDirty();

            glm::vec3 getPos();
            glm::vec3 getVel();
            glm::vec3 getRot();

            void setPos(glm::vec3 pos);
            void setVel(glm::vec3 vel);
            void setRot(glm::vec3 rot);

            virtual void update() = 0;
        };
        
        template<typename T>
        Entity *_spawn() {
            return new T;
        }
        
        void _declareEntityType(std::string uid, Entity*(* e)());
        
        Entity *spawnEntityByUID(std::string uid);
        
        template<typename T>
        struct EntityDeclarer {
            EntityDeclarer(std::string uid) {
                _declareEntityType(uid, &SME::Level::_spawn<T>);
            }
        };
    }
}

#define SME_REGISTER_ENTITY(T) struct SME::Level::EntityDeclarer<T> T##Declaration = SME::Level::EntityDeclarer<T>(#T)

#endif	/* ENTITY_H */

