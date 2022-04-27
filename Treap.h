//
// Created by ahmed on 7/16/2021.
//

#ifndef PEACHES_TREAP_H
#define PEACHES_TREAP_H
#include <iostream>
#include "User.h"
#include "Friend.h"
#include "userLinkedList.h"

using namespace std;

class Node{
public:
    Friend Ldata;
    Node* next;
};

class Treap {
    Treap* userTreap;
    int priority;
    Treap *left;
    Treap *right;
    Friend data;
    string line,firstName,secondName;
    User firstUser;
    Friend firstFriend;
    User secondUser;
    Friend secondFriend;
    Friend obj;
    User user;
    userLinkedList ull;

public:
    Treap() {
        userTreap = NULL;
        this->priority = rand() % 100;
        this->left= this->right = NULL;
    }
    Treap(Friend data) {
        this->data = data;
        this->priority = rand() % 100;
        this->left= this->right = NULL;
    }
    void Add(Treap*  &root ,Friend data) {
        if (root == NULL) {
            root = new Treap(data);
            return;
        }
        if (data.username < root->data.username) {
            Add(root->left,data);
            //  if (root->left != NULL && root->left->priority > root->priority)
            //  RightRotation(root);
        } else {
            Add(root->right,data);
            // if (root->right!= NULL && root->right->priority > root->priority)
            //  LeftRotation(root);
        }
    }
    /*  void LeftRotation(Treap* &root) {
          Treap* R = root->right;
          Treap* X = root->right->left;
          R->left = root;
          root->right= X;
          root = R;
      }
      void RightRotation(Treap* &root) {
          Treap* L = root->left;
          Treap* Y = root->left->right;
          L->right = root;
          root->left= Y;
          root = L;
      } */

    User* Find(Treap* root,string username) {
        if (root == NULL)
            return NULL;
        if (root->data.username == username)
            return root->data.friend_referance;
        if (username < root->data.username)
            return Find(root->left, username);
        return Find(root->right, username);
    }
    int countLNodes(Node *head) {
        int count = 0;
        Node *temp = head;
        while(temp)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
    //Treap* sortedListToBST(Node **head_ref, int n);
    Treap* FriendList(User u) {
        user = u;
        obj.username=user.getUsername();
        obj.friend_referance=&user;
        userTreap->Add(userTreap,obj);
        ifstream myFile ("all-users-relations.in");

        while (!myFile.eof()) {
            getline(myFile, firstName, ',');
            getline(myFile, secondName, '\n');
            if (user.getUsername() == firstName) {
                secondUser = ull.getUserByUsername(secondName);
                secondFriend.username=secondUser.getUsername();
                secondFriend.friend_referance=&secondUser;
                userTreap->Add(userTreap,secondFriend);
            }
            if (user.getUsername() == secondName) {
                firstUser = ull.getUserByUsername(firstName);
                firstFriend.username=firstUser.getUsername();
                firstFriend.friend_referance= &firstUser;
                userTreap->Add(userTreap,firstFriend);
            }
        }
        return userTreap;
    }



    void listAllFriends()
    {
        inorder(userTreap);
    }
    void deleteFriend(Treap*  &root ,Friend data) {
        //node to be deleted which is a leaf node
        if (root == nullptr)
            return;
        if (data.username < root->data.username)
            deleteFriend(root->left, data);
        else if (data.username > root->data.username)
            deleteFriend(root->right, data);
            //node to be deleted which has two children
        else {

            if (root->left && root->right) {
                if (root->left->priority < root->right->priority) {
                    //LeftRotation(root);
                    deleteFriend(root->left, data);
                } else {
                    //RightRotation(root);
                    deleteFriend(root->right, data);
                }
            }
                //node to be deleted has only one child
            else {
                Treap* child = (root->left)? root->left: root->right;
                Treap* curr = root;
                root = child;
                delete curr;
            }
        }
    }
    void inorder(Treap *p)
    {
        if(p != NULL)
        {
            inorder(p->left);
            cout<<p->data<<" ";
            inorder(p->right);
        }
    }


    Treap* GetUserFriendList() {
    }

};
#endif //PEACHES_TREAP_H
