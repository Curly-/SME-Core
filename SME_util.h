/* 
 * File:   SME_util.h
 * Author: Sam
 *
 * Created on 22 June 2016, 17:00
 */

#ifndef SME_UTIL_H
#define	SME_UTIL_H

#include <string>
#include <vector>

namespace SME {
    namespace Util {
        /*
         * Remove any whitespace from both sides of the string (eg "   xyz  "->"xyz")
         */
        std::string trim(std::string);
        
        /*
         * Generates a vector, separating a string by a delimiter
         */
        std::vector<std::string> split(std::string str, char delim, bool skipEmptyTokens = false);
    }
}

#endif	/* SME_UTIL_H */

