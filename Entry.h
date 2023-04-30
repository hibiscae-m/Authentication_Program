//
// Created by Marius on 22/04/2023.
//

#ifndef LOGIN_REGISTRATION_ENTRY_H
#define LOGIN_REGISTRATION_ENTRY_H

#include <iostream>

template <typename T>
class Entry {
public:
    Entry() = default;
    static T getUserInput() {
        T result{};
        while (!(std::cin >> result)) {
            std::cout << "Invalid entry." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return result;
    };
};


#endif //LOGIN_REGISTRATION_ENTRY_H
