#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

string stateName;
int stateScore;

void saveUser(string name, int score){
    ofstream file;
    file.open(name,ios::out); //abre el archivo o lo genera.
    
    if(file.fail()){
        cout<<"[model]: Error al guardar datos";
    }else{
        stateName = name;
        stateScore = score;
        file<<name<<" "<<score; //inserta nombre y score en el file
    }
}

void readUser(string name, int score){
    ifstream file;
    file.open(name,ios::in); //abre el archivo o lo genera.
    
    if(file.fail()){
        cout<<"[model]: Error al leer los datos";
    }

    while (!file.eof()){
        if(!file.eof()){
            file>>name>>score; //extrae las palabras valiendose del espacio
        }
    }
}
