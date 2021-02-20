//display_ascii2.cpp
//Rahman:Jawadur:A00434830:u28
//Submission 02
//Displaying Printable ASCII Characters and Their Codes, Part 2

/*
 * The program functions as desired and if is properly formatted
*/

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;

#include "utilities.h"
using Scobey::Pause;
using Scobey::DisplayOpeningScreen;


//Function prototypes
void DisplayProgramInfo();
/**<
Display program description, with a pause at the end of each screen.
*/

void DisplayAsciiHorizontally
(
    char firstChar, //in
    char lastChar   //in
);
/**<
Display ASCII characters and their decimal, octal and hexadecimal
codes in row-wise fashion, i.e. with codes increasing from left to right.
@param firstChar The low endpoint of the ASCII value range to be displayed.
@param lastChar The high endpoint of the ASCII value range to be displayed.
@pre ' ' <= firstChar <= lastChar <= '~'.
@post A table of ASCII character/code values has been displayed, with
codes increasing from left to right across the rows, from firstChar to
lastChar (inclusive). Each ASCII character and each of its three
numerical codes appears right-justified in a fieldwidth of 4 spaces.
The range of values displayed depends on input from the user.
*/

void DisplayAsciiVertically
(
    char firstChar, //in
    char lastChar   //in
);
/**<
Display ASCII characters and their decimal, octal and hexadecimal
codes in column-wise fashion, i.e. with codes increasing from top
to bottom down each column.
@param firstChar The low endpoint of the ASCII value range to be displayed.
@param lastChar The high endpoint of the ASCII value range to be displayed.
@pre ' ' <= firstChar <= lastChar <= '~'.
@post A table of ASCII character/code values has been displayed, with
codes increasing  from top to bottom, down the columns, from firstChar
to lastChar (inclusive). Each ASCII character and each of its three
numerical codes appears right-justified in a fieldwidth of 4 spaces.
The range of values displayed depends on input from the user.
*/


int main(int argc, char* argv[])
{
    //Code for your main function goes here
    if (argc == 1)
    {
        DisplayProgramInfo();
        return 0;
    }

    //Error checking
    if (argc != 4)
    {
        cout << "Error: Program must have exactly 3 command-line parameters."
            "\nProgram now terminating.\n";
        Pause();
        return 0;
    }

    if (strlen(argv[1]) != 1 || strlen(argv[2]) != 1 || strlen(argv[3]) != 1)
    {
        cout << "Error: Each input parameter must be a single character."
            "\nProgram now terminating.\n";
        Pause();
        return 0;
    }

    if (argv[1][0] > argv[2][0])
    {
        cout << "Error: First input parameter must not follow second in the "
            "ASCII sequence."
            "\nProgram now terminating.\n";
        Pause();
        return 0;
    }

    if (argv[3][0] != 'h' && argv[3][0] != 'v')
    {
        cout << "Error: Third parameter must be h or v."
            "\nProgram now terminating.\n";
        Pause();
        return 0;
    }

    if (argv[3][0] == 'h')
    {
        DisplayAsciiHorizontally(argv[1][0], argv[2][0]);
    }

    if (argv[3][0] == 'v')
    {
        DisplayAsciiVertically(argv[1][0], argv[2][0]);
    }
}

void DisplayProgramInfo()
{
    //Place function body code here
    DisplayOpeningScreen("Rahman:Jawadur:A00434830:u28", "\nSubmission 02"
        "\nDisplaying Printable ASCII Characters and Their Codes, Part 2"
        , 9, 11);
    cout << R"TEXT(
This program displays a table of printable ASCII characters, along with their
corresponding decimal, octal and hexadecimal codes, four per line, except
possibly for the last line. The table has a suitable header and a pause at
the end of the display and at the end of the first screen if the display
consumes more than a single screen of output.
    
The program takes three command-line parameters as input. The first two give
the range of characters to be displayed, and the first character must precede
the second in the ASCII character sequence. The third input parameter must be
either an h or a v to indicate whether the display is to be horizontal (codes
increasing across the rows) or vertical (codes increasing down the columns).
    
The program must also recognize the following errors and terminate immediately
after reporting that such an error has occurred:

- Wrong number of input parameters (not exactly 3)
      
- One or more input parameters not being a single character
        
- First input value following the second in the ASCII sequence
          
- Third input value something other than h or v
                                                              Screen 1 of 2
)TEXT";
    Pause();
    cout << R"TEXT(
The printable ASCII characters extend from the blank space character ' '
(which has code 32 decimal) to the tilde character '~' (which has code 126
decimal). The characters with codes in the range 0 to 31 and also code 127
are non-printable "control characters".

When entering characters at the command line to determine the character range
we want in the output, we need to be very careful how we enter some characters.
These include the blank space character and some others that are treated as
"meta characters" by the operating system, and are thus not passed to the
program for processing. To avoid this problem we will place each character
entered at the command line within double quotes. The " and \ characters must
(as usual) be escaped within their enclosing double quotes, and so must the
backtick character (the `).









                                                              Screen 2 of 2
)TEXT";
    Pause();
}

void DisplayAsciiHorizontally
(
    char firstChar, //in
    char lastChar   //in
)
{
    //Place function body code here

    system("clear");

    cout << endl;
    char firstIn = firstChar;
    char secondIn = lastChar;
    
    //keeps track of which ASCII character we are on (1st char to K-th char)
    int k = 1;

    //prints headers Dec, Oct, and Hex for 1st page
    for (int j = 1; j <= (int)secondIn + 1 - (int)firstIn; j++)
    {
        cout << setw(8) << "Dec";
        cout << setw(4) << "Oct";
        cout << setw(4) << "Hex";
        if (j == 4)
        {
            cout << endl;
            break;
        }
        if (j == (int)secondIn + 1 - (int)firstIn)
        {
            cout << endl;
        }
    }

    int pageOneMax = 88;
    for (int i = (int) firstIn; i <= (int)secondIn; i++)
    {         
        //if 2nd page needs to be made
        if (k == pageOneMax + 1)
        {
            Pause();

            //prints headers Dec, Oct, and Hex for 2nd page
            int numNeedToPrint = (int)secondIn + 1 - (int)firstIn - pageOneMax;
            for (int j = 1; j <= numNeedToPrint; j++)
            {
                cout << setw(8) << "Dec";
                cout << setw(4) << "Oct";
                cout << setw(4) << "Hex";

                if (j == 4)
                { 
                    cout << endl;
                    break;
                }
                if (j == numNeedToPrint)
                {
                    cout << endl;
                }
            }
        }

        //prints and formats ASCII chars and their codes
        cout << setw(4) << (char) i;
        cout << setw(4) << dec << i;
        cout << setw(4) << oct << i;
        cout << uppercase << setw(4) << hex << i;
        
        //newLine every 4 characters
        if (k % 4 == 0)
        {
            cout << endl;
        }
        k++;

        //very last loop subtract k
        if (i == (int)secondIn)
        {
            k--;
        }
    }
    
    //newLine if required
    if (k % 4 != 0)
    {
        cout << endl;
    }
    
    if ((int)lastChar + 1 - (int)firstChar != 88)
    {
        Pause();
    } 
    else 
    {
        cout << "Press Enter to continue ... "; cin.ignore(80, '\n'); 
    }
}

void DisplayAsciiVertically
(
    char firstChar, //in
    char lastChar   //in
)
{
    //Place function body code here
    system("clear");
    cout << endl;
    //keeps track of which ASCII character that need printing
    int counter = (int)lastChar + 1 - (int)firstChar;

    //prints headers Dec, Oct, and Hex for 1st page
    for (int j = 1; j <= counter; j++)
    {
        cout << setw(8) << "Dec";
        cout << setw(4) << "Oct";
        cout << setw(4) << "Hex";
        if (j == 4)
        {
            cout << endl;
            break;
        }
        if (j == counter)
        {
            cout << endl;
        }
    }

    int columnOneCount = (counter/4) + (int)(counter%4 > 0);
    int columnTwoCount = (counter/4) + (int)(counter%4 > 1);
    int columnThreeCount = (counter/4) + (int)(counter%4 > 2);
    int columnFourCount = (counter/4); 
    int columnOne = (int)firstChar;
    int columnTwo = columnOneCount + columnOne;
    int columnThree = columnTwoCount + columnTwo;
    int columnFour = columnThreeCount + columnThree;

    while (counter != 0)
    {
        //if 2nd page needs to be made
        if ((int)lastChar + 1 - (int)firstChar - counter == 88)
        {
            Pause();

            //prints headers Dec, Oct, and Hex for 2nd page
            int numNeedToPrint = (int)lastChar + 1 - (int)firstChar - 88;
            for (int j = 1; j <= numNeedToPrint; j++)
            {
                cout << setw(8) << "Dec";
                cout << setw(4) << "Oct";
                cout << setw(4) << "Hex";

                if (j == 4)
                { 
                    cout << endl;
                    break;
                }
                if (j == numNeedToPrint)
                {
                    cout << endl;
                }
            }
        }

        //prints and formats ASCII chars and their codes
        cout << setw(4) << (char) columnOne;
        cout << setw(4) << dec << columnOne;
        cout << setw(4) << oct << columnOne;
        cout << uppercase << setw(4) << hex << columnOne;
        counter--;
        columnOne++;
        if (counter == 0)
        {
            cout << endl;
            break;
        }
        
        cout << setw(4) << (char) columnTwo;
        cout << setw(4) << dec << columnTwo;
        cout << setw(4) << oct << columnTwo;
        cout << uppercase << setw(4) << hex << columnTwo;
        counter--;
        columnTwo++;
        if (counter == 0)
        {
            cout << endl;
            break;
        }
        
        cout << setw(4) << (char) columnThree;
        cout << setw(4) << dec << columnThree;
        cout << setw(4) << oct << columnThree;
        cout << uppercase << setw(4) << hex << columnThree;
        counter--;
        columnThree++;
        if (counter == 0)
        {
            cout << endl;
            break;
        }

        cout << setw(4) << (char) columnFour;
        cout << setw(4) << dec << columnFour;
        cout << setw(4) << oct << columnFour;
        cout << uppercase << setw(4) << hex << columnFour;
        counter--;
        columnFour++;
        cout << endl;
    }

    if ((int)lastChar + 1 - (int)firstChar != 88)
    {
        Pause();
    } 
    else 
    {
        cout << "Press Enter to continue ... "; cin.ignore(80, '\n'); 
    }
    
}
