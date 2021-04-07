//anagrams.cpp
//Rahman:Jawadur:A00434830:u28
//Submission 05
//Finding Anagrams

/*
 * The program functions as desired and if is properly formatted
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#include "utilities.h"
using Scobey::Pause;
using Scobey::DisplayOpeningScreen;


int main()
{
    //opening screen and info
    DisplayOpeningScreen("Rahman:Jawadur:A00434830:u28", "\nSubmission 05"
        "\nFinding Anagrams"
        , 11, 12);
    cout << "\nThis program finds all the words in a dictionary that can be "
        "formed with the\nletters of a given word (or string), and "
        "displays them in alphabetical order.\n\n";

    //enter file
    cout << "Enter the name of the file containing the dictionary: ";
    string fileName;
    getline(cin, fileName);
    vector<string> lineList;
    ifstream inFile(fileName.c_str());
    if (!inFile)
    {
        cout << "\nCould not open file named " << fileName << ".\n";
        Pause(0, "Program now terminating.");
        return 0;
    }

    //read dictionary
    string line;
    cout << "\nReading the dictionary ...\n";
    while (getline(inFile, line)) lineList.push_back(line);
    cout << "The dictionary contains " << lineList.size() << " words.\n";
    sort(lineList.begin(), lineList.end());
    inFile.close();
    Pause();

    //enter words until end of line
    cout << "Now enter a word (or any string of letters) and I'll give you\n"
        "a list of all of its anagrams (if any) found in the dictionary: ";
    string word = "";
    while (getline(cin, word))
    {
        sort(word.begin(), word.end());
        bool found = false;
        do
        {
            if (binary_search(lineList.begin(), lineList.end(), word))
            {
                found = true;
                cout << word << endl;
            }
        }
        while (next_permutation(word.begin(), word.end()));

        if (!found)
        {
            cout << "Sorry, no anagrams found for that input.\n";
        }

        cout << endl;
        cout << "Enter another one (or the end-of-file character to stop): ";
    }
    cin.clear();
    Pause(0, "\nProgram now terminating.");
}

