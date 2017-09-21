#include<fstream>
#include<iostream>
#include<cstdlib>
#include <string>
#include <regex>

using namespace std;

int main()
{
	/*
	ifstream fin;
	fin.open("test.txt");
	if (fin.fail())
	{
	cout << "Input file opening failed.\n";
	exit(1);
	}
	string search;
	cout << "Please enter a name: ";
	cin >> search;
	bool isFound = 0;
	while (!fin.eof())
	{
	string temp = "";
	getline(fin, temp);
	for (int i = 0; i<search.size(); i++)
	{
	if (temp[i] == search[i])
	isFound = 1;
	else
	{
	isFound = 0;
	break;
	}
	}

	if (isFound)
	{
	cout << "Password is: ";
	for (int i = search.size() + 1; i<temp.size(); i++)
	cout << temp[i];

	break;
	}

	}

	if (fin.eof() && (!isFound))
	{
	cout << "Name not found!\n";
	}

	fin.close();
	*/

	ifstream stream;
	ofstream outputMention;
	ifstream inputMention;
	string word;
	string mention;
	stream.open("test.txt");
	outputMention.open("outputMention.txt");
	outputMention << "MentionReport:" << endl;
	while (stream >> word) {
		if (word[0] == *"@" || word[0] == *"#") {
			cout << "Found Word: " << word << endl;
			outputMention << word << endl;
		}
	}
	stream.close();
	outputMention.close();
	inputMention.open("outputMention.txt");
	while (inputMention >> mention) {
		cout << mention << endl;
	}

	/*cin >> token;
	while (getline(stream, line)) {
	if (line.find(token) != string::npos) {
	cout << line << endl;
	isFound = 1;
	}
	}
	if (isFound == 0) {
	cout << token << "not found" << endl;
	}*/
	return 0;
}