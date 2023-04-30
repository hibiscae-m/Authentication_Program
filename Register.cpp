//
// Created by Marius on 21/04/2023.
//

#include "Register.h"
#include "Data.h"
#include "Entry.h"
#include <iostream>
#include <fstream>
#include <string>

void Register::start() {
    std::cout << "Create a new user" << std::endl;
    std::cout << "Login: ";
    std::string username = Entry<std::string>::getUserInput();
    while (Data::doesUserExists("data.txt", username)) {
        std::cout << "User unavailable" << std::endl;
        std::cout << "Login: ";
        username = Entry<std::string>::getUserInput();
    }
    std::fstream file;
    std::string password;
    std::string password_confirmation;
    do {
        std::cout << "Password: ";
        password = Entry<std::string>::getUserInput();
        std::cout << "Confirm password: ";
        password_confirmation = Entry<std::string>::getUserInput();
        if (password != password_confirmation)
            std::cout << "Password doesn't match. Please try again." << std::endl;
    } while (password != password_confirmation);
    file.open("data.txt", std::ios::out | std::ios::app);
    if (file.is_open()) {
        file << username << ";" << password << std::endl;
        std::cout << "User successfully created." << std::endl;
    }
    file.close();
}
