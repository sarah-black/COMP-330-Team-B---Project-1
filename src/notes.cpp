//
// Created by S.Black on 9/10/2017.
//
//PLAN: this part of the program will put everything into a string vector (?)
//and tokenize the words to make searching for a keyword easier.
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;

void notes(){

string word;
char space;
word.clear();
ifstream xFile;
xFile.open(/*here is where the path to said file will be. Will prob be a variable of sorts.*/);

if(xFile.is_open()){

}
/*just in case we can't find file, this is err output*/
if(!xFile){
    cout<<"File cannot be found."<<;
    end(1);
}

}