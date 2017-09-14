//
// Created by S.Black on 9/10/2017.
//
//PLAN: this part will be what searches for keywords.
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include "parser.h"
using namespace std;


ifstream fin;
fin.open("test.txt");
if(fin.fail())
{
	cout << "Input file opening failed.\n";
	exit(1);
}
string search;
cout << "Search: "
cin  >> search;
bool found = 0;
while(!fin.eof())
{
	string temp = "";
	getline(fin,temp);
	for(int i=0;i<search.size();i++)
	{
		if(temp[i]==search[i])
			found = 1;
		else
		{
			found = 0;
			break;
		}
	}
		if(found)
	{
		cout << "Password is: ";
		for(int i = search.size()+1;i<temp.size();i++)
			cout << temp[i];
			break;
	}

}

if(fin.eof()&&(!found))
{
	cout << "Name not found!\n";
}

fin.close();

return 0;
}

