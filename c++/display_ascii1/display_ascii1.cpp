//display_ascii1.cpp
//Rahman:Jawadur:A00434830:u28
//Submission 01
//Displaying Printable ASCII Characters and Their Codes, Part 1

/*
 * Everything is working as requirements specified
 *
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main(int argc, char* argv[])
{
    //Opening Screen
    if (argc == 1)
    {
        cout << "\n\n\n\n\n\n\n\n\n\n"
            "\tRahman:Jawadur:A00434830:u28"
            "\n\tSubmission 01\n\tDisplaying Printable "
            "ASCII Characters and Their Codes, Part 1"
            "\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "Press Enter to continue ... "; cin.ignore(80, '\n');
        cout << endl << R"TEXT(
This program takes two printable ASCII characters as input, with the first
character preceding the second in the ASCII character sequence. The program
then displays all characters in the range determined by those two characters,
along with their corresponding decimal, octal and hexadecimal codes, four per
line, with a suitable header and a pause if the display consumes more than a
single screen of output. The two input character values must be entered as
two separate command-line parameters, and there is no error checking.
        
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
        
                                                                  Screen 1 of 1
)TEXT"; 
        cout << "Press Enter to continue ... "; cin.ignore(80, '\n');
        return 0;
    }
    
    system("clear");

    cout << endl;
    char firstIn = argv[1][0];
    char secondIn = argv[2][0];
    
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
            cout << "Press Enter to continue ... "; cin.ignore(80, '\n');
            cout << endl;
            
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
    
    cout <<"Press Enter to continue ... "; cin.ignore(80, '\n');
}

