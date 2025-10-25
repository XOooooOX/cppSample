//
// Created by hosein-gh on 10/4/25.
//

#include "counter.h"

CIS::CIS(int f) {
    std::cout << f << std::endl;
}
namespace App{

    int counter =0;
    void increment(){
        counter++;
    }
}