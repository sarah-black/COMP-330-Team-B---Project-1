#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <regex>

using namespace std;

class UniqueIdentifier {
	string id; //Keywords
	string textfile; //Which notes it came from

public:
	string get_id();
	string get_textFile();
	void set_id(string word);
	void set_textFile(string textFileInput);
};
