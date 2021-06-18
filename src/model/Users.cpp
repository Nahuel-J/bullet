#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

string s_name;
int s_score;

void saveUser(string name, int score){
    ofstream file;
    file.open(name,ios::out);
    
    if(file.fail()){
        cout<<"[model]: Error al guardar datos";
    }else{
        s_name = name;
        s_score = score;
        file<<name<<" "<<score;
    }

}

void readUser(string name, int score){
    ifstream file;
    file.open(name,ios::in);
    
    if(file.fail()){
        cout<<"[model]: Error al leer los datos";
    }

    while (!file.eof()){
        if(!file.eof()){
            file>>name>>score;
        }
    }
}
