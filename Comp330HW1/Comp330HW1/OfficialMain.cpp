#include<fstream>
#include<iostream>
#include<cstdlib>
#include <string>
#include <regex>
#include <vector>
#include <algorithm>
#include <math.h>
#include <windows.h>
#include <search.h>

using namespace std;

string search;

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

	//FREQUENCY//
	cout << "Please enter the path of the directory of files you would like to use: "<<endl;
	string path;
	cin >> path;

	string txtFile = "*.txt";
	string fullPath = path + txtFile;

	//Using this, we can do the whole Find First File, Next, et cetera thing!!
	WIN32_FIND_DATA FindData;
	HANDLE hFind;

	hFind = FindFirstFile(fullPath.c_str(), &FindData);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		cout << "Error searching directory\n";
		return -1;
	}

	do
	{
		string filePath = path + FindData.cFileName;
		ifstream stream(filePath.c_str());
		if (stream)
		{
			string str, str2, strn, tab[10000], tab2[10000];
			int i, k, j, n, tabl;
			int l = 0;
			char c = 179;
			vector<int> tabs;
			vector<string> stringi;
			

			while (getline(stream, str2)) {
				str += str2;
				str += ' ';
			}
			k = 0;
			for (i = 0; i < str.length(); i++) {
				if (str[i] != ' ' && str[i] != '.' && str[i] != '\t' && str[i] != ','
					&& str[i] != ';' && str[i] != ':' && str[i] != '}' && str[i] != '{') {
					tab[k] += tolower(str[i]);
				}
				else {
					k++;
				}
				if (str[i] == '.' || str[i] == '\t' || str[i] == ',' || str[i] == ';'
					|| str[i] == ':' || str[i] == '}' || str[i] == '{') {
					k--;
				}
			}
			tabl = k;

			k = 0;
			for (i = 0; i < tabl; i++) {
				for (j = 0; j < tabl; j++) {
					if (tab[i] == tab[j]) {
						k++;
					}
				}
				tabs.push_back(k);
				k = 0;
			}
			for (i = 0; i < tabl; i++) {
				for (j = 0; j < tabl - 1; j++) {
					if (tab[j] < tab[j + 1]) {
						n = tabs.at(j);
						tabs.at(j) = tabs.at(j + 1);
						tabs.at(j + 1) = n;
						strn = tab[j];
						tab[j] = tab[j + 1];
						tab[j + 1] = strn;
					}
				}
			}
			for (i = 0; i < tabl; i++) {
				for (j = 0; j < tabl - 1; j++) {
					if (tabs.at(j) < tabs.at(j + 1)) {
						n = tabs.at(j);
						tabs.at(j) = tabs.at(j + 1);
						tabs.at(j + 1) = n;
						strn = tab[j];
						tab[j] = tab[j + 1];
						tab[j + 1] = strn;
					}
				}
			}
			tab2[0] = tab[0];
			for (i = 0; i < tabl; i++) {
				if (tab[i] != tab[i + 1]) {
					tab2[i] = tab[i + 1];
				}
			}
			k = 1;
			l++;
			for (i = 0; i < tabl; i++) {
				if (!tab2[i].empty()) {
					l++;
				}
			}


			//Mention Report - Print



			//Prints out the most freq used words in each txt file. I think this was a requirement. :)
			cout << "|--->MOST FREQUENTLY USED WORDS<---|" << endl;
			for (i = 0; i < tabl; i++) {
				if (!tab2[i].empty() && k <= 20) {
					cout << c << k++ << "." << '\t' << c << tab2[i] << '\t' << c << "*" <<
						tabs.at(i + 1)
						<< '\t' << c << roundf(((float)tabs.at(i + 1) * 100 / l) * 100) / 100 << "%" <<
						endl;
				}
			}
			//These two are just to add spaces between reports.
			cout << "" << endl;
			cout << "" << endl;

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
		}
		else
		{
			cout << "Problem opening file " << FindData.cFileName << "\n";
		}

	} while (FindNextFile(hFind, &FindData) > 0);

	if (GetLastError() != ERROR_NO_MORE_FILES)
	{
		cout << "Something went wrong during searching\n";
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