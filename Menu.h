//
// Created by Marius on 21/04/2023.
//

#ifndef LOGIN_REGISTRATION_MENU_H
#define LOGIN_REGISTRATION_MENU_H

#include <array>
#include <string>

class Menu {
public:
    Menu() = default;
    void start();
private:
    void display() const;
    enum CHOICES { Login, Register, Quit };
    std::array<std::string, 3> options { "Login", "Register", "Quit" };
};


#endif //LOGIN_REGISTRATION_MENU_H
