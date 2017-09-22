#include<fstream>
#include<iostream>
#include<cstdlib>
#include <string>
#include <regex>
#include <vector>
#include <algorithm>
#include <math.h>
#include <windows.h>
#include "OfficialMain.h"
#include "search.h"

using namespace std;

ifstream inputStream; //note
ofstream outputMention; //writes mention report
ifstream inputMention; //opening mention report

ofstream outputKeyword; //writes keyword report
ifstream inputKeyword; //opening keyword report

string word; //Each word in the note is saved in this string
string mention; //Each mention in the report is saved in this string
string keyword; // Each keyword in the report is saved in this string
string input; //Takes in user input for help, file, reports, etc

string fileInput; //Asks the user for the name of the file they want to open
string *keywords = NULL;

void Searcher::open() {

	keywords = new string[10000]; //Unique Keywords Array

	int counter = 0; //Counter to add to unique keywords array
	int size = 0; //Current size of array, adds to end if not duplicate
	bool duplicate = false; //Checks if there is a duplicate in the array

	bool quit = false;

	while (!quit) {
		cout << "Enter 'file' to run the note. 'quit' to exit terminal window. 'keyword' for list of unique keywords. 'mention' for list of mentions." << endl;
		cin >> input;

		if (input == "quit") {
			quit = true;
		}

		if (input == "file") {
			outputMention.open("MentionReport.txt", ios::app); //Opens the report to write in ("app" appends it to the file so it saves)
			outputKeyword.open("KeywordReport.txt", ios::app); //outputKeyword.open("KeywordReport.txt", ios::app);

			cout << "Enter the file name you'd like to open (Example: Enter 'test' to open test.txt)" << endl;
			cin >> fileInput;

			inputStream.open(fileInput + ".txt"); //Opens the note
			while (inputStream >> word) { //Loops the note to parse
				regex e("@.*"); //Matches anything starting with "@"
				bool match = regex_match(word, e);
				regex x("#.*"); //Matches anything starting with "#"
				bool hashMatch = regex_match(word, x);
				regex y("!.*"); //Matches anything starting with "!"
				bool exclMatch = regex_match(word, y);

				if (match == true || hashMatch == true) { //If any matches return true, prints out mention
					outputMention << word << endl;
					for (counter = 0; !duplicate && counter < size; ++counter) {
						if (word == keywords[counter]) {
							duplicate = true;
						}
					}
					if (!duplicate) {
						keywords[size++] = word;
						outputKeyword << word << endl;
					}
				}
			}

			//Closes files below
			inputStream.close();
			outputMention.close();
			outputKeyword.close();
		}

		Keyword k;
		k.kwd();
		
		Mention m;
		m.mentions();

	}
}


void Keyword::kwd(){
	if (input == "keyword") {
		inputKeyword.open("KeywordReport.txt");
		cout << "" << endl;
		cout << "Current List of Unique Keywords: " << endl;

		while (inputKeyword >> keyword) {
			cout << keyword << endl;
		}
		inputKeyword.close();
	}
}


void Mention::mentions()
{
	if (input == "mention") {
		inputMention.open("MentionReport.txt");
		cout << "" << endl;
		cout << "Current List of Mentions: " << endl;

		while (inputMention >> mention) {
			cout << mention << endl;
		}
		inputMention.close();
	}

}

