/* 
 * File:   SME_config.h
 * Author: Sam
 *
 * Created on 14 June 2016, 00:28
 */

#ifndef SME_CONFIG_H
#define	SME_CONFIG_H

#include <string>

namespace SME {
    namespace Config {
        /*
         * Register a value to be stored
         * \param name The name used to reference the value later
         * \param t The value to be stored 
         */
        template<typename T>
        void registerValue(std::string name, T t);

        /*
         * Retrieves a stored value
         * \return The value associated with the name given
         * \param name The name associated with the value to be returned
         * \tparam T The type of the value to be returned
         */
        template<typename T>
        T getValue(std::string name);
        
        /*
         * Clear all stored values
         */
        void clear();
        /*
         * Remove an individual value
         */
        void removeValue(std::string name);
        
        /*
         * Save all currently stored values to the specified file
         */
        void saveFile(std::string path);
        /*
         * Load all values in the specified file
         */
        void loadFile(std::string path);
    }
}

#endif	/* SME_CONFIG_H */

