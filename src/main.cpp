#include <iostream>
#include <thread>
#include <string>
#include "./controllers/stats.cpp"
using namespace std;

//testing
main(){
    string username;
    int score;
    
    cout<<"Inserte nombre: ";
    cin>>username;
    setName(username);
    cout<<"Inserte score: ";
    setScore(score);
    cin>>score;
    
}


