//build_concordance.cpp
//Rahman:Jawadur:A00434830:u28
//Submission 08
//Building Concordances

/*
 * The program functions as desired and if is properly formatted
*/
#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

#include "utilities.h"
using Scobey::Pause;
using Scobey::DisplayOpeningScreen;
using Scobey::TextItems;

//Function prototypes
void DisplayOpeningScreenAndProgramInfo();
/**<
Display program description, with a pause at the end of each screen.
*/

ostream& operator<<(ostream& os, const set<int>& s);
/**<
Display a set of int in the concordian format
by overloading the << operator.
*/

int main(int argc, char* argv[])
{
    //opening screen and info
    if (argc == 1)
    {
        DisplayOpeningScreenAndProgramInfo();
        return 0;
    }

    //input, Output files
    string fileName = argv[1];
    ifstream inFile(fileName.c_str());
    if (!inFile)
    {
        cout << "\nCould not open file " << fileName << ".\n";
        Pause(0, "Program now terminating.");
        return 0;
    }

    ofstream myfile;
    if (argc >= 3)
    {
        fileName = argv[2];
        myfile.open (fileName.c_str());
        if (!myfile)
        {
            cout << "\nCould not open file " << fileName << ".\n";
            Pause(0, "Program now terminating.");
            return 0;
        }
    }

    ifstream diffFile;
    if (argc >= 4)
    {
        fileName = argv[3];
        diffFile.open (fileName.c_str());
        if (!diffFile)
        {
            cout << "\nCould not open file " << fileName << ".\n";
            Pause(0, "Program now terminating.");
            return 0;
        }
    }

    map<string, set<int>> m;
    int lineNum = 1;
    string line;
    // reads a line from file
    while (getline(inFile, line))
    {

        //transfors everyline to lower case and replaces non alphabets with " "
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        size_t found = line.find_first_not_of("abcdefghijklmnopqrstuvwxyz");
        while (found != string::npos)
        {
            line[found] = ' ';
            found = line.find_first_not_of
                ("abcdefghijklmnopqrstuvwxyz", found + 1);
        }

        //splits the transformed string into words
        char* cstr = new char [line.length() + 1];
        strcpy (cstr, line.c_str());
        char* p = strtok (cstr, " ");
        while (p != NULL)
        {
            //places those words into map
            string str(p);
            set<int> setInt;
            setInt = m[str];
            setInt.insert(lineNum);
            m[str] = setInt;
            p = strtok(NULL, " ");
        }
        lineNum++;
    }

    //outputs map to required destination
    map<string, set<int>>::iterator p;
    for (p = m.begin(); p != m.end(); ++p)
    {

        if (argc >= 3)
        {
            myfile << setw(15) << p->first << " " << p->second << "\n";
        }
        else
        {
            cout << setw(15) << p->first << " " << p->second << "\n";
        }
    }

    if (argc >= 3)
    {
        myfile.close();
    }
    //if 3rd parameter than does diff on 2nd and 3rd para
    if (argc >= 4)
    {
        string myOut = argv[2];
        string other = argv[3];
        cout << "\nThe program will now display the contents of\n"
            "differences.txt, if any, before terminating.\n";
        Pause(0);
        string diffCmd = "diff " + myOut + " " + other + " > differences.txt" ;
        system(diffCmd.c_str());
        diffFile.close();
    }
    inFile.close();
}

void DisplayOpeningScreenAndProgramInfo()
{
    DisplayOpeningScreen("Rahman:Jawadur:A00434830:u28", "\nSubmission 08"
        "\nBuilding Concordances"
        , 11, 12);

    TextItems text("build_concordance.txt");
    text.displayItem("ProgramDescription");
}

ostream& operator<<(ostream& os, const set<int>& s)
{
    int i = 0;
    for (int it : s)
    {

        if (i == 15)
        {
            i = 0;
            os << "\n" ;
            if (it >= 100)
            {
                os << setw(19);
            }
            else
            {
                os << setw(18);
            }
        }

        os << it;
        i++;
        if (it != *s.rbegin() && i != 15)
        {
            os << " ";
        }
    }

    return os ;
}
