//
// Created by S.Black on 9/10/2017.
//
//PLAN: this part of the program will put everything into a string vector (?)
//and tokenize the words to make searching for a keyword easier.
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include "notes.h"
using namespace std;

void notes(){

int sum = 0;
ifstream xFile;
int x;
Note note = new Note;

/*should put something in later that let's them search multiple files*/
cout<<"Please enter the file path that you would like to search: "<<;
cin >> note;
xFile.open(note);

while(xFile >> x){
    sum = sum + x;
}

/*just in case we can't find file, this is err output*/
if(!xFile){
    cout<<"File cannot be found."<<;
    end(1);
}

}