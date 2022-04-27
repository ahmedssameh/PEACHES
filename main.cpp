#include <iostream>
#include <ostream>
#include <string>
#include<algorithm>
#include "Treap.h"



void MenuListOfAllAction()
{
    cout<<"Welcome to PEACHES"<<endl
        <<"----------------------------------------"<<endl
        <<"1-List all friends "<<endl
        <<"2-Search by username "<<endl
        <<"3-Add friend "<<endl
        <<"4-Remove friend"<<endl
        <<"5-People you may know"<<endl
        <<"6-logout "<<endl
        <<"7-Exit"<<endl
        <<"Make your choice"<<endl;
}
void LoginMenu(){
    cout<<"Welcome to PEACHES"<<endl
        <<"----------------------------------------"<<endl
        <<"1-Login "<<endl
        <<"2-Exit "<<endl
        << "Make your Choice "<<endl;
}
using namespace std;
int main() {
    while (true) {
        LoginMenu();
        int option1;
        userLinkedList obj;
        userLinkedList::iterator it=obj.getHead();
        cin >> option1;
        if (option1 == 2)
            break;
        if (option1 == 1) {
            string username;
            cout << "Enter User Name" << endl;
            cin >> username;
            bool found = obj.isuser(username);
            if (!found) {
                cout << "Wrong! Please Enter correct Username" << endl;
                continue;
            }
            else {
                User curr = obj.getUserByUsername(username);//obj user log in
                Treap objUser;
                static Treap *rootUser;
                static Treap *rootFriend;
                rootUser = objUser.FriendList(curr);//root user log in
                Friend user;// obj friend for user log in
                user.username = username;
                user.friend_referance = &curr;
                while(true) {
                    int option;
                    MenuListOfAllAction();
                    cin >> option;
                    if (option == 6) {
                        break;
                    }
                    if (option == 7) {
                        break;
                    }
                    if (option == 3) {
                        string friend_user_name;
                        cout << "Enter friend username ";
                        cin >> friend_user_name;
                        User *Found = rootUser->Find(rootUser, friend_user_name);//friend founded in Treap user log in
                        if (Found == NULL) {
                            Friend friendd;//obj friend for friend name
                            User MyNewFriend = obj.getUserByUsername(friend_user_name);//obj user for friend
                            friendd.username = friend_user_name;
                            friendd.friend_referance = &MyNewFriend;
                            rootUser->Add(rootUser, friendd);//Do Add friend for user log in
                            Treap objFriend;
                            rootFriend = objFriend.FriendList(MyNewFriend);// root friend
                            rootFriend->Add(rootFriend, user);//do Add user in friendlist for friend
                            cout << "You are now friends" << endl;
                        } else {
                            cout << "You are already friends" << endl;
                        }
                    }
                    if (option == 4) {
                        string friend_user_name_deleted;
                        cout << "Enter friend username want delete ";
                        cin >> friend_user_name_deleted;
                        User *Found = rootUser->Find(rootUser,friend_user_name_deleted);//friend founded in Treap user log in
                        if (Found != NULL) {
                            Friend friendd;//obj friend
                            User MyNewFriend = obj.getUserByUsername(friend_user_name_deleted);//obj user for friend
                            friendd.username = friend_user_name_deleted;
                            friendd.friend_referance = &MyNewFriend;
                            rootUser->deleteFriend(rootUser, friendd);
                            cout << "Done delete " << friend_user_name_deleted << "From Friend list" << endl;
                        }
                        if (Found == NULL) {
                            cout << "Do nothing! " << friend_user_name_deleted << "Not Friend" << endl;
                        }
                    }
                    if(option==1){
                        objUser.inorder(rootUser);
                    }
                    if(option ==5)
                    {
                        while (it.getcurrent() != NULL) {
                            User *Found = rootUser->Find(rootUser, it.getcurrent()->user.getUsername());
                            if (Found == NULL) {
                                cout << it.getcurrent()->user.getUsername() << ','
                                     << it.getcurrent()->user.getName()<<endl;
                                ++it;
                            } else
                            {
                                ++it;
                                continue;
                            }
                        }
                        it=obj.getHead();
                    }
                    if(option==2){
                        User Search;
                        string SearchedFriend;
                        cout << "Enter friend username that you want to search for ";
                        cin >> SearchedFriend;
                        User *Found = rootUser->Find(rootUser,SearchedFriend);
                        if (Found != NULL) {
                            Search=obj.getUserByUsername(SearchedFriend);
                            cout<<Search.getUsername()<<','<<Search.getName()<<','<<Search.getEmail()<<endl;
                    }
                        else{
                            cout<<SearchedFriend<<"  not found"<<endl;
                        }
                    }
                }
            }
        }
    }

}
/*User user;
   user.setUsername("talaat3000");
   user.setName("Talaat Mahmoud");
   user.setEmail("talaat3000@gmail.com");
   Treap tr;
   tr.FriendList(user);*/