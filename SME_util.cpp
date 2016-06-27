#include "SME_util.h"
#include <string>
#include <sstream>

std::string SME::Util::trim(std::string str) {
    std::string output = "";
    std::string sls = "";
    bool first = true;
    for (char c : str) {
        if (c != ' ') {
            sls += c;
            output += sls;
            sls = "";

            first = false;
            continue;
        }
        if (!first) sls += c;
    }
    return output;
}

std::vector<std::string> SME::Util::split(std::string str, char delim, bool skipEmptyTokens) {
    std::stringstream ss(str);
    std::string item;
    std::vector<std::string> elems;
    while (std::getline(ss, item, delim)) {
        if (skipEmptyTokens && item.size() == 0) {
            continue;
        }
        elems.push_back(item);
    }
    return elems;
}