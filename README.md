# COMP-330-Team-B---Project-1

Hello!

First thing's first, please note the location of the directory of files you would like
to test. If you do not have a specified directory, you may use the test directory within
the projects 'resource' folder.

## TO RUN

1) Make sure all necessary libraries are installed for basic C++ functionality, and put files you wish to search through in the project's resource folder.

2) Download requisite files and open the project. To do this, go into the TeamBProj1 folder and open the TeamBProj1 file.

3) Go ahead and run the main function.

4) When prompted to enter file name, type only the name (no suffix or path information) and press enter. Otherwise, follow instructions within window.

5) The window will auto-run the test, which will output mentions and unique keywords when requested. 

6) When the search is complete, you may enter file name again or a different file name to perform another similar search or a different function.

7) When finished searching, please enter 'quit' to close the window.


## FUNCTIONS

### Searcher::open

This function is used to open the searched file and write to keyword.txt and mentions.txt the keywords and mentions, respectively.

Pub Variables:

https://user-images.githubusercontent.com/18154371/30737559-b0b9942c-9f4c-11e7-8c32-ba135326ff6e.PNG


Class list:

https://user-images.githubusercontent.com/18154371/30737565-b56208d8-9f4c-11e7-8e05-b45628d0ed4f.PNG

      Keyword will print out unique keywords, with Mentions printing out all mentions within a file.


### UniqueIdentifiers

This performs searches for uniques identifiers, and if more than one is found (not allowed), the program states that duplicate id'swere found.


List of jobs the fn performs:

      string UniqueIdentifier::get_id()
      string UniqueIdentifier::get_textFile()
      void UniqueIdentifier::set_id(string word)
      void UniqueIdentifier::set_textFile(string textFileInput)
