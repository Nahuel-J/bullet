#include <iostream>
#include <stdio.h>
#include "model/Users.cpp"
using namespace std;

string getName(){
    return s_name;
}
int getScore(){
    return s_score;
}

void setName(string name){
    saveUser(name,s_score);
}
void setScore(int score){
    saveUser(s_name, score);
}
