//
// Created by ahmed on 7/16/2021.
//

#ifndef PEACHES_USER_H
#define PEACHES_USER_H
#include <iostream>
using namespace std;

class User {
private:
    string name;
    string username;
    string email;

public:
    User() {
        name = "";
        username = "";
        email = "";
    }

    User(const string &name, const string &username, const string &email) : name(name), username(username),
                                                                            email(email) {}

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        User::name = name;
    }

    const string &getUsername() const {
        return username;
    }



    void setUsername(const string &username) {
        User::username = username;
    }

    const string &getEmail() const {
        return email;
    }

    void setEmail(const string &email) {
        User::email = email;
    }

    friend ostream &operator<<(ostream &output, User &user) {
        output<<user.username<<","<<user.name<<","<<user.email<<endl;

        return output;
    }
};
#endif //PEACHES_USER_H
