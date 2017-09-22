#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

//ARBITRARY CHANGE

using namespace std;

string search;

int main()
{

	ifstream stream;
	ofstream outputMention;
	ifstream inputMention;
	string word;
	string mention;
	//stream.open("test.txt");
	outputMention.open("outputMention.txt");
	outputMention << "MentionReport:" << endl;
	if (word[0] == *"@" || word[0] == *"#") {
		cout << "Found Word: " << word << endl;
			outputMention << word << endl;
	}		
		stream.close();
		outputMention.close();
		inputMention.open("outputMention.txt");
		while (inputMention >> mention) {
			cout << mention << endl;
		}
	return 0;
}