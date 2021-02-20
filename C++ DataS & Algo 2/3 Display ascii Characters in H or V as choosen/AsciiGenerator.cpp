/** @file AsciiGenerator.cpp
Implementation file corresponding to AsciiGenerator.h
for Submission 03
@author Rahman:Jawadur:A00434830:u28
*/


/*
 * The program functions as desired and if is properly formatted
*/

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;

#include "utilities.h"
#include "AsciiGenerator.h"
using Scobey::Pause;

/*
Private data members of the AsciiGenerator class:
char firstChar;
char lastChar;
*/

AsciiGenerator::AsciiGenerator
(
    char firstChar, //in
    char lastChar   //in
)
{
    this->firstChar = firstChar;
    this->lastChar = lastChar;
}



void AsciiGenerator::displayHorizontally()
{
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

void AsciiGenerator::displayVertically()
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
