//
// Created by Marius on 22/04/2023.
//

#ifndef LOGIN_REGISTRATION_DATA_H
#define LOGIN_REGISTRATION_DATA_H

#include <string>

class Data {
public:
    Data() = default;
    static bool doesUserExists(const std::string &file_location, const std::string &user);
    static std::string getPassword(const std::string &file_location, const std::string &user);
};


#endif //LOGIN_REGISTRATION_DATA_H
