#include <iostream>
#include <string>
#include "../model/Users.cpp"
using namespace std;

//Trae el nombre disponible en el sistema. No funciona con relaciones.
string getName(){
    return s_name;
}
int getScore(){
    return s_score;
}

//Asigna el nombre que quedará latente en el sistema.
void setName(string name){
    int score = s_score;
    saveUser(name,score);
}
void setScore(int score){
    string name = s_name;
    saveUser(name, score);
}
