//bs_checker.cpp
//Rahman:Jawadur:A00434830:u28
//Submission 07
//Checking for Balanced Symbols

/*
 * The program functions as desired and if is properly formatted
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;

#include "utilities.h"
using Scobey::Pause;
using Scobey::DisplayOpeningScreen;
using Scobey::TextItems;

struct symbolLineNumIndex
{
    char symbol;
    int lineNum;
    size_t index;
};

//Function prototypes
void DisplayOpeningScreenAndProgramInfo();
/**<
Display program description, with a pause at the end of each screen.
*/

ostream& operator<<(ostream& os, const symbolLineNumIndex& aSymbol);
/**<
Display a symbolLineNumIndex struct in this format: "? at index ? on line ?"
by overloading the << operator.
*/

int main(int argc, char* argv[])
{
    // opening screen and info
    if (argc == 1)
    {
        DisplayOpeningScreenAndProgramInfo();
        return 0;
    }

    // open file
    string fileName = argv[1];
    ifstream inFile(fileName.c_str());
    if (!inFile)
    {
        cout << "\nCould not open file " << fileName << ".\n";
        Pause(0, "Program now terminating.");
        return 0;
    }

    // misc initializations
    const string SYMBOLS = "({[]})";
    int lineNum = 1;
    string line;
    stack<symbolLineNumIndex> s1;
    symbolLineNumIndex temp{};
    cout << endl;

    // reads a line from file
    while (getline(inFile, line))
    {
        //finds opening and closing symbols
        size_t found = line.find_first_of(SYMBOLS);
        while (found != string::npos)
        {
            temp =
            {
                line[found],
                lineNum,
                found
            };

            const string ClOSE_SYMBOLS = "]})";
            string s(1, line[found]);

            // encounters a closing sybmol
            if (s.find_first_of(ClOSE_SYMBOLS) != string::npos)
            {
                // but stack is empty
                if (s1.empty())
                {
                    cout << temp << " is missing the corresponding"
                        " open symbol." << endl;
                    cout << "The file has unmatched symbols.\n\n";
                    inFile.close();
                    return 0;
                }

                // closing symbol does not match the top of the stack symbol.
                // Uses Ascii code to represent its corresponding opening
                // symbol. char(')' - 1)) = '('
                // char('}' - 2)) = '{'
                // char(']' - 2)) = '['
                if (char(line[found] - 2) != s1.top().symbol
                    && char(line[found] - 1) != s1.top().symbol)
                {
                    cout << temp << " does not match " << s1.top()
                        << "." << endl;
                    cout << "The file has unmatched symbols.\n\n";
                    inFile.close();
                    return 0;
                }

                // closing symbol matches
                else
                {
                    s1.pop();
                }

            }

            // encounters a opening symbol
            else
            {
                s1.push(temp);
            }

            found = line.find_first_of(SYMBOLS, found + 1);
        }

        lineNum++;
    }

    // end of the file but the stack still contains opening symbol/symbols.
    bool noMatchSymbols = false;
    while (!s1.empty())
    {
        temp = s1.top();
        s1.pop();
        noMatchSymbols = true;
    }
    if (noMatchSymbols)
    {
        cout << temp << " has no matching close symbol." << endl;
        cout << "The file has unmatched symbols.\n\n";
        inFile.close();
        return 0;
    }

    cout << "The file has matching symbols." << endl << endl;
    inFile.close();
}

void DisplayOpeningScreenAndProgramInfo()
{
    DisplayOpeningScreen("Rahman:Jawadur:A00434830:u28", "\nSubmission 07"
        "\nChecking for Balanced Symbols"
        , 11, 12);

    TextItems text("bs_checker.txt");
    text.displayItem("ProgramDescription");
}

ostream& operator<<(ostream& os, const symbolLineNumIndex& aSymbol)
{
    return os << aSymbol.symbol << " at index " << aSymbol.index
        << " on line " << aSymbol.lineNum;
}

