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


/*void searchContent(string content) {
smatch match;
regex expr("[@!*^]*");

while (regex_search(content, match, expr)) {
for (auto x : match)
cout << x << " ";

cout << std::endl;
content = match.suffix().str();
}

}
*/
/*void search(ifstream stream) {
	std::string result;
	try {
		std::regex re("Name: (.*)");
		std::smatch match;
		if (regex_search(stream, match, re) && match.size() > 1) {
			result = match.str(1);
		}
		else {
			result = std::string("");
		}
	}
}*/