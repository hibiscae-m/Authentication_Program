//
// Created by Marius on 21/04/2023.
//

#include "Login.h"
#include "Entry.h"
#include "Data.h"
#include <iostream>

void Login::start() {
    std::cout << "Log into your account" << std::endl;
    std::cout << "Login: ";
    std::string username = Entry<std::string>::getUserInput();
    std::cout << "Password: ";
    std::string password = Entry<std::string>::getUserInput();
    if (Data::doesUserExists("data.txt", username)) {
        if (password == Data::getPassword("data.txt", username)) {
            std::cout << username << " logged in." << std::endl;
        }
        else {
            std::cout << "Wrong password/username" << std::endl;
        }
    }
    else {
        std::cout << "Wrong password/username" << std::endl;
    }
}
