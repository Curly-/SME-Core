/* 
 * File:   Level.h
 * Author: Sam
 *
 * Created on 17 July 2016, 17:14
 */

#ifndef LEVEL_H
#define	LEVEL_H

#include <map>
#include <cstring>
#include <string>
#include <vector>
#include "SME_entity.h"

namespace SME {
    namespace Level {
        class Level {
        private:
            std::map<std::string, void *> parameters;
            std::vector<Entity::Entity *> entities; //TODO optimise this using octrees or something

        public:
            template<typename T>
            void setParameter(std::string name, T t) {
                void *v = malloc(sizeof t);
                memcpy(v, &t, sizeof t);
                parameters[name] = v;
            }

            template<typename T>
            T getParameter(std::string name) {
                return (T)*(T*) parameters[name];
            }
            
            void update();
            
            Entity::Entity *addEntity(std::string uid);
            void addEntity(Entity::Entity *entity);
            
            Level();
            ~Level();
        };
    }
}

#endif	/* LEVEL_H */

