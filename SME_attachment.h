/* 
 * File:   SME_attachment.h
 * Author: Sam
 *
 * Created on 23 July 2016, 15:39
 */

#ifndef SME_ATTACHMENT_H
#define	SME_ATTACHMENT_H

#include <glm/glm.hpp>

namespace SME {
    namespace Level {
        namespace Entity {
            class Entity;
            struct Attachment {
                Attachment(Entity *entity);
                virtual void onPosChanged(glm::vec3 pos) = 0;
                virtual void onVelChanged(glm::vec3 vel) = 0;
                virtual void onRotChanged(glm::vec3 rot) = 0;
                virtual void onUpdate() = 0;
                virtual ~Attachment();
            private:
                const Entity *entity;
            };
        }
    }
}

#endif	/* SME_ATTACHMENT_H */

