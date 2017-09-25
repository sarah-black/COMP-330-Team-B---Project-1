#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <regex>
#include "UniqueIdentifier.h"

using namespace std;

string UniqueIdentifier::get_id()
{
	return id;
}

string UniqueIdentifier::get_textFile()
{
	return textfile;
}

void UniqueIdentifier::set_id(string word)
{
	id = word;
}
void UniqueIdentifier::set_textFile(string textFileInput)
{
	textfile = textFileInput;
}