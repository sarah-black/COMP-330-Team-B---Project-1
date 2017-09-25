#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <regex>
#include "UniqueIdentifier.h"

using namespace std;

int main()
{
	UniqueIdentifier notePlus;
	notePlus.set_id("Hello");
	string tempPlus = notePlus.get_id();
	cout << tempPlus << endl;
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
	keywords = new string[10000]; //Unique Keywords Array

	string *identifiers = NULL;
	identifiers = new string[10000]; //!identifiers

	UniqueIdentifier note[10000]; //Holds objects that says which text file the note is from. Goes with "search" function

	string search; //User input for search

	int counter = 0; //Counter to add to unique keywords array
	int size = 0; //Current size of array, adds to end if not duplicate
	bool duplicate = false; //Checks if there is a duplicate in the array
	bool unique = false; //Checks to see if a unique identifier has already been used

	int identifierCounter = 0; //Counter for identifiers array
	int sizeIdentifier = 0; //Current size of identifiers array

	int noteSize = 0; //Current size of note array

	bool quit = false;

	while (!quit) {
		cout << "" << endl;
		cout << "Enter 'file' to run the note. 'quit' to exit terminal window. 'keyword' for list of unique keywords. 'mention' for list of mentions. 'search' to report of specific keywords/mentions." << endl;
		cout << "" << endl;
		cin >> input;
		//Quit condition below
		if (input == "quit") {
			quit = true;
		}
		//File condition below
		if (input == "file") {
			outputMention.open("MentionReport.txt", ios::app); //Opens the report to write in ("app" appends it to the file so it saves)
			outputKeyword.open("KeywordReport.txt", ios::app); //outputKeyword.open("KeywordReport.txt", ios::app);

			cout << "Enter the file name you'd like to open (Example: Enter 'test' to open test.txt)" << endl;
			cin >> fileInput;
			cout << "" << endl;

			inputStream.open(fileInput + ".txt"); //Opens the note
			while (inputStream >> word) { //Loops the note to parse
										  //unique = false;
				regex e("@.*"); //Matches anything starting with "@"
				bool match = regex_match(word, e);
				regex x("#.*"); //Matches anything starting with "#"
				bool hashMatch = regex_match(word, x);
				regex z("!.*");
				bool markMatch = regex_match(word, z);

				if (markMatch == true) { //Checks for !identifiers
					for (identifierCounter = 0; !unique && identifierCounter < sizeIdentifier; ++identifierCounter) {
						if (word == identifiers[identifierCounter]) {
							unique = true;
							cout << "Duplicate Identifier Between Notes!" << endl;
						}
					}
					if (!unique) {
						identifiers[sizeIdentifier++] = word;
					}
				}

				if ((match == true || hashMatch == true)) { //If any matches return true, prints out mention
					duplicate = false;
					noteSize++;
					note[noteSize].set_id(word); //Puts in word for identifier in object array
					note[noteSize].set_textFile(fileInput); //Puts in which text file it came from in object array
					outputMention << word << endl;
					//Checks for duplicates below
					for (counter = 0; !duplicate && counter < size; ++counter) { //Checks for duplicates
						if (word == keywords[counter]) {
							duplicate = true;
						}
					}
					if (!duplicate) { //As long as there was no duplicate, it adds the keyword
						size++;
						keywords[size] = word;
						outputKeyword << word << endl;
					}
				}
			}

			//Closes files below
			inputStream.close();
			outputMention.close();
			outputKeyword.close();
		}
		//Searches the generated reports to figure out which notes the keywords/mentions appear in
		if (input == "search") {
			cout << "Type in a keyword/mention: " << endl;
			cin >> search;
			cout << "" << endl;
			cout << "These are the textfiles associated with the keyword/mention searched: " << endl;
			for (int noteCounter = 0; noteCounter < noteSize; noteCounter++) {
				if (note[noteCounter].get_id() == search) {
					cout << note[noteCounter].get_textFile() << endl;
				}
			}
		}
		//Mention Report Code Below
		if (input == "mention") {
			inputMention.open("MentionReport.txt");
			cout << "" << endl;
			cout << "Current List of Mentions: " << endl;

			while (inputMention >> mention) {
				cout << mention << endl;
			}
			inputMention.close();
		}
		//Keyword Report Code Below
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
	return 0;
}
