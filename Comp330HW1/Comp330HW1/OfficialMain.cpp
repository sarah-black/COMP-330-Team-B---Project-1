#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <regex>

using namespace std;

int main()
{
	ifstream inputStream; //note
	ofstream outputMention; //writes report
	ifstream inputMention; //opening report

	string word; //Each word in the note is saved in this string
	string mention; //Each mention in the report is saved in this string

	string fileInput; //Asks the user for the name of the file they want to open



	while (true) {
		outputMention.open("TestReport.txt", ios::app); //Opens the report to write in ("app" appends it to the file so it saves)
		cout << "Enter the file name you'd like to open (Example: Enter 'test' to open test.txt)" << endl;
		cin >> fileInput;

		inputStream.open(fileInput + ".txt"); //Opens the note
		while (inputStream >> word) { //Loops the note to parse
			regex e("@.*"); //Matches anything starting with "@"
			bool match = regex_match(word, e);
			regex x("#.*"); //Matches anything starting with "#"
			bool hashMatch = regex_match(word, x);

			if (match == true || hashMatch == true) { //If any matches return true, prints out mention
				outputMention << word << endl;
			}
		}
		//Closes files below
		inputStream.close();
		outputMention.close();

		inputMention.open("TestReport.txt");
		while (inputMention >> mention) {
			cout << mention << endl;
		}
		inputMention.close();
	}
	return 0;
}