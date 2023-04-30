//
// Created by Marius on 22/04/2023.
//

#include "Data.h"
#include <fstream>
#include <sstream>

bool Data::doesUserExists(const std::string &file_location, const std::string &user) {
    bool result = false;
    std::fstream file;
    file.open(file_location, std::ios::in);
    if (file.is_open()) {
        std::string line{};
        while(std::getline(file, line)) {
            std::stringstream string_stream(line);
            while (std::getline(string_stream, line, ';')) {
                if (line == user) {
                    result = true;
                }
                break;
            }
            if (result)
                break;
        }
    }
    file.close();
    return result;
}

std::string Data::getPassword(const std::string &file_location, const std::string &user) {
    std::string password;
    bool password_found = false;
    std::fstream file;
    file.open(file_location, std::ios::in);
    if (file.is_open()) {
        std::string line{};
        while (std::getline(file, line)) {
            std::stringstream string_stream(line);
            while (std::getline(string_stream, line, ';')) {
                if (line == user) {
                    std::getline(string_stream, line, ';');
                    password = line;
                    password_found = true;
                }
                break;
            }
            if (password_found)
                break;
        }
    }
    return password;
}
