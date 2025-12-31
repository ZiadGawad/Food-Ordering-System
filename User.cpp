#include <iostream>
using namespace std;

#include "User.h"


//Initialize static member
int User::totalUsers = 0;

//Constructors
User::User():userId(""),name(""),phoneNumber(""){
    totalUsers++;
}
User::User(string userId,string name,string phoneNumber)
    : userId(userId),name(name),phoneNumber(phoneNumber){
    totalUsers++;
}

//Getters
int User::getTotalUsers(){ 
    return totalUsers;
} 

string User::getUserID(){ 
    return userId ;
}

string User::getName(){ 
    return name;
}

string User::getPhoneNumber(){ 
    return phoneNumber; 
}

//Destructors
User::~User(){}