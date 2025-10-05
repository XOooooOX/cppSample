//
// Created by hosein-gh on 10/4/25.
//

#ifndef COUNTER_H
#define COUNTER_H

#include <string>
#include <iostream>

namespace App {
    extern int counter;
    void increment();

    struct Address {
        std::string city;
        std::string street;
    };

   struct Student {
        std::string name;
        int age;
        double grade;

       Address * address;

        void print() const {
        std::cout << name << std::endl;
        }
// ba in car khod compiler bar asas in ke struct hast ya class be tartib filed ha ro moghyes mikone
       auto operator<=>(const Student&) const = default;
   };
}
#endif //COUNTER_H
