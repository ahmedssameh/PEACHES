//
// Created by ahmed on 7/16/2021.
//

#ifndef PEACHES_USERLINKEDLIST_H
#define PEACHES_USERLINKEDLIST_H
#include <iostream>
#include <fstream>
#include "User.h"
#include <vector>

using namespace std;

class userLinkedList {

    struct Node {
        User user;
        Node* next;
        Node* previous;

    };

private:
    Node* head;
    Node* tail;

public:
    class iterator {
    private:
        Node *current;
    public:
        iterator(Node *n) {
            current = n;
        }

        iterator &operator++() {

                current = current->next;
                return *this;

        }

        iterator &operator--() {
            if (current->previous == nullptr) {
                cout << "you are already on the head of the list";
                exit(0);
            } else {
                current = current->previous;
                return *this;
            }
        }

        User &operator*() {
            return current->user;
        }

        bool operator==(const iterator &ite) {
            return this->current == ite.current;
        }

        bool isNull() {
            if (current->next == nullptr) {
                return true;
            } else
                return false;

        }

        Node *getcurrent() {
            return current;
        }

        bool operator!=(const iterator &anotherNode) {
            if (anotherNode.current != current)
                return true;

            return false;
        }


    };
    Node *getHead() const {
        return head;
    }

    Node *getTail() const {
        return tail;
    }

    userLinkedList() {
        head = NULL;
        tail = NULL;
        addFromFile();
    }

    void addFromFile() {
        sortingFileAlphabetically();
        User user;
        ifstream myfile ("sortedFile.in");
        if (!myfile.is_open())
            cout << "Can't open this file! \n";
        int count = 0;
        string line,username,name,email;
        if(myfile.is_open()){
            while(!myfile.eof()){
                getline(myfile,line);
                count++;
            }
        }
        myfile.seekg(0);
        while (!myfile.eof()) {
            for (int i=0; i <count; i++) {
                getline(myfile, username, ',');
                user.setUsername(username);
                getline(myfile, name, ',');
                user.setName(name);
                getline(myfile, email, ' ');
                user.setEmail(email);
                myfile.peek();
                addUser(user);
            }

        }

    }
    bool isuser(string username){
        Node* tmp = head;

        int flag = 0;
        while (tmp != NULL) {
            if (tmp->user.getUsername() == username) {
                flag = 1;
                return true;
            }
            tmp = tmp->next;
        }
        if (flag==0){
            return false;
        }
    }

    User getUserByUsername(string name) {
        Node* tmp = head;

        int flag = 0;
        while (tmp != NULL) {
            if (tmp->user.getUsername() == name) {
                flag = 1;
                break;
            }

            tmp = tmp->next;
        }

        if (flag == 1) {
            return tmp->user;
        }
        else {
            cout<<"Can't find a user with this username!"<<endl;
        }
    }
    void addUser(User user) {
        Node* newNode = new Node();
        newNode->user = user;
        if (head == NULL) {
            head = tail = newNode;
            newNode ->next = NULL;
        }
        else {
            newNode -> next = NULL;
            tail -> next = newNode;
            newNode -> previous = tail;
            tail = newNode;
        }

    }

    bool isUnique() {
        string uniqueName = head->user.getUsername();
        Node* tmp = new Node();
        tmp = head;
        while (tmp->next != NULL) {
            if (tmp->user.getUsername() == uniqueName) {
                return false;
            }
            else {
                tmp = tmp -> next;
            }
        }
        return true;
    }

    void sortingFileAlphabetically(){
        vector<string> sortedFile;

        ifstream unsortedFile ("all-users.in");
        if(!unsortedFile.is_open())
            cout << "Can't open this file! \n";

        string word;
        while(getline(unsortedFile, word))
            sortedFile.push_back(word);

        sort(sortedFile.begin(), sortedFile.end());


        ofstream MyFile("sortedFile.in");

        for (size_t i = 0; i < sortedFile.size(); i++)
        {
            MyFile << sortedFile[i]<<" ";
        }

        MyFile.close();
    }

    void display()
    {
        Node* tmp = new Node();
        tmp=head;
        while(tmp!=NULL)
        {
            cout<<tmp->user<<" ";
            tmp=tmp->next;
        }
        cout<<endl;
    }
};
#endif //PEACHES_USERLINKEDLIST_H
