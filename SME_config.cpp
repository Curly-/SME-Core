#include "SME_config.h"
#include "SME_util.h"
#include <map>
#include <fstream>
#include <cstring>
#include <iostream>

#define FORTYPES(func) func(int); func(long); func(long long); func(float);\
    func(double); func(long double); func(char const *); func(bool)

struct Data {
    std::string type; /**< Stringified type*/
    void *v = nullptr;

    ~Data() {
        if (v != nullptr) {
            free(v);
        }
    }
};

std::map<std::string, Data> vals;

/*
 * Registers generic types
 * \param name Name to be associated with value
 * \param t Value to be stored
 * \param type Stringified typename
 */
template<typename T>
void regVal(std::string name, T t, std::string type) {
    Data *data = &vals[name];
    data->type = type;
    data->v = malloc(sizeof t);
    memcpy(data->v, &t, sizeof t);
}

/*
 * Registers CStrings
 * Strings need to be handled separately because they're pointers
 * \param name Name to be associated with value
 * \param t Value to be stored
 * \param type Stringified typename (must be "char const *")
 */
template<>
void regVal<char const *>(std::string name, char const *t, std::string type) {
    Data *data = &vals[name];
    data->type = type;
    data->v = malloc(sizeof t);
    strcpy((char *)data->v, t);
}

/*
 * Generic getter
 * \return Value associated with key provided, casted to type T
 */
template<typename T>
T getVal(std::string name) {
    if (vals.find(name) == vals.end()) {std::cout << "Invalid config key (" << name << ")" << std::endl; exit(-1);}
    return (T)*(T*)vals[name].v;
}

/*
 * CString getter
 * Strings need to be handled separately because they're pointers
 * \return CString value associated with key provided
 */
template<>
char const *getVal<char const *>(std::string name) {
    if (vals.find(name) == vals.end()) {std::cout << "Invalid config key (" << name << ")" << std::endl; exit(-1);}
    return (char const *)vals[name].v;
}

/* Basically redefined SME::Config::registerValue
 * Has to be redefined because the value of registerValue<type> cannot be set
 * outside of SME::Config
 */
template<typename T>
void reg(std::string name, T t);
template<typename T>
T get(std::string name);

template<typename T>
void SME::Config::registerValue(std::string name, T t) {
    reg(name, t);
}

template<typename T>
T SME::Config::getValue(std::string name) {
    return get<T>(name);
}

#define REGTYPE(type)\
template<> void reg<type>(std::string name, type t) { regVal(name, t, #type); }\
template void SME::Config::registerValue<type>(std::string name, type t);\
template<> type get<type>(std::string name) { return getVal<type>(name); }\
template type SME::Config::getValue<type>(std::string name)
FORTYPES(REGTYPE);
#undef REGTYPE

void SME::Config::clear() {
    vals.clear();
}

void SME::Config::removeValue(std::string name) {
    vals.erase(name);
}

void SME::Config::saveFile(std::string path) {
    std::ofstream out(path);
#define IFTYPEWRITE(t) if (it->second.type == #t) {out << it->first << "=" << ((t)*(t *) it->second.v) << std::endl; continue;}
    for (std::map<std::string, Data>::iterator it = vals.begin(); it != vals.end(); ++it) {
        if (it->second.type == "char const *") { //override default cast (include "x")
            out << it->first << "=\"" << ((char const *) it->second.v) << "\"" << std::endl;
            continue;
        } else if (it->second.type == "bool") { //use true/false so doesn't load as long long
            out << it->first << "=" << (((bool)*(bool *)it->second.v) ? "true" : "false") << std::endl;
            continue;
        }
        FORTYPES(IFTYPEWRITE);
    }
#undef IFTYPEWRITE
    out.close();
}

/*
 * Determines if a string represents an integer
 * \return true if string represents an integer
 */
bool isInt(std::string str) {
    for (int i = 0; i < str.length(); i++) {
        char c = str.at(i);
        if (c == '-' && i == 0) {
            continue;
        } if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

/*
 * Determines if a string represent a decimal number
 * \return true if string contains one decimal point and digits only
 */
bool isDecimal(std::string str) {
    int d = 0;
    for (int i = 0; i < str.length(); i++) {
        char c = str.at(i);
        if (c == '.') {
            d++;
        } else if (c == '-' && i == 0) {
            continue;
        } else if (!isdigit(c)) {
            return false;
        }
    }
    return d == 1;
}

void SME::Config::loadFile(std::string path) {
    std::ifstream in(path);
    std::string line;
    while (std::getline(in, line)) {
        std::string key = SME::Util::trim(line.substr(0, line.find('=')));
        std::string val = SME::Util::trim(line.substr(line.find('=') + 1)); //+1 to remove "

        if ((val.at(0) == '"' && val.at(val.length() - 1) == '"')
                || (val.at(0) == '\'' && val.at(val.length() - 1) == '\'')) {
            registerValue(key, val.substr(1, val.length() - 2).c_str());
        } else if (isInt(val)) {
            registerValue(key, std::stoll(val));
        } else if (isDecimal(val)) {
            registerValue(key, std::stold(val));
        } else if (val == "true") {
            registerValue(key, true);
        } else if (val == "false") {
            registerValue(key, false);
        } else {
            std::cout << "Failed to load " << key << std::endl;
        }
    }
}