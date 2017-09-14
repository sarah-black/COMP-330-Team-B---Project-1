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

Note note = new Note;
ifstream xFile;
cout << data << endl;
cout << "Please enter the file path that you would like to search: " << endl;
cin >> note;
xFile.open(note, ios::in);
vector<int> temp;
char data[];
xFile >> data;
while(xFile >> data) {
    temp.push_back(data);
}
for(vector<int>::iterator i = temp.begin(); i != temp.end(); i++) {
    cout << *i << endl;
}


/*just in case we can't find file, this is err output*/
if(!xFile){
    cout<<"File cannot be found."<<;
    end(1);
}

xFile.close();

}