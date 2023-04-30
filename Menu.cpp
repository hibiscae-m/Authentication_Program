//
// Created by Marius on 21/04/2023.
//

#include <iostream>
#include "Menu.h"
#include "Register.h"
#include "Login.h"
#include "Entry.h"

void Menu::start() {
    short userChoice;
    while (true) {
        display();
        userChoice = Entry<short>::getUserInput();
        switch (userChoice) {
            case CHOICES::Login:
                Login::start();
                break;
            case CHOICES::Register:
                Register::start();
                break;
            case CHOICES::Quit:
                std::cout << "Bye." << std::endl;
                return;
            default:
                std::cout << "Option unavailable." << std::endl;
                break;
        }
    }
}

void Menu::display() const {
    int counter = 0;
    for (const std::string &option: options) {
        std::cout << counter << ": " << option << std::endl;
        counter++;
    }
}