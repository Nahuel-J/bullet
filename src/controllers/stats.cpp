#include <iostream>
#include <string>
#include "../model/Users.cpp"
using namespace std;

//Trae el nombre disponible en el sistema. No funciona con relaciones.
string getName(){
    return stateName;
}
int getScore(){
    return stateScore;
}

//Asigna el nombre que quedará latente en el sistema.
void setName(string name){
    int score = stateScore;
    saveUser(name,score);
}
void setScore(int score){
    string name = stateName;
    saveUser(name, score);
}
