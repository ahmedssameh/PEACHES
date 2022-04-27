//
// Created by ahmed on 7/16/2021.
//

#ifndef PEACHES_FRIEND_H
#define PEACHES_FRIEND_H
#include "User.h"
#include <iostream>
using namespace std;


class Friend {
public:
    string username;
    User* friend_referance;
    friend ostream &operator<<(ostream &output, Friend & f) {
        output << f.friend_referance->getUsername()<<","<<f.friend_referance->getName()<<endl;
        return output;
    }
};

#endif //PEACHES_FRIEND_H
