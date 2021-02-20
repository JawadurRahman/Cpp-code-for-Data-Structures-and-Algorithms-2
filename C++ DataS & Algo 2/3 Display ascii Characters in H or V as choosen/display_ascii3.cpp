//display_ascii3.cpp
//Rahman:Jawadur:A00434830:u28
//Submission 03
//Displaying Printable ASCII Characters and Their Codes, Part 3

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
using Scobey::ReadChar;
using Scobey::Menu;
using Scobey::Pause;
using Scobey::DisplayOpeningScreen;
using Scobey::TextItems;
using Scobey::userSaysYes;

//Function prototypes
void BuildMenu
(
    Menu& menu
);
/**<
Sets title of, and adds options to, menu.
@param menu The menu to receive the title and options.
@pre menu has been initialized and is empty.
@post menu has a title and four options.
*/

void GetAsciiRangeFromUser
(
    char& firstChar, //in
    char& lastChar   //in
);

/**<
Gets the end points of the required ASCII range from the user.

@param firstChar The low end of the character interval to be displayed.
@param lastChar The high end of the character interval to be displayed.
@pre None
@post The user has entered the low endpoint of the range, which is in
firstChar, and the high endpoint of the range, which is in lastChar, and
firstChar <= lastChar.

If the first character of whatever the user enters when prompted for the start
character for the table is not a printable character, the following message
is displayed:
Error: The first character of that entry was not a printable character.
Try again. Be careful to enter valid starting/ending characters for the table.

If the first character of whatever the user enters when prompted for the end
character for the table is not a printable character, the following message
is displayed:
Error: The first character of that entry was not a printable character.
Try again. Be careful to enter valid starting/ending characters for the table.

If the both characters entered by the user lie within the range of printable
characters, but the second precedes the first in the ASCII sequence,
the following message is displayed:
Error: The starting character for the table display must not follow
the ending character in the ASCII sequence. Try again.
*/

int main()
{
    //Code for your main function goes here
    DisplayOpeningScreen("Rahman:Jawadur:A00434830:u28", "\nSubmission 03"
        "\nDisplaying Printable ASCII Characters and Their Codes, Part 3"
        , 9, 11);
    Menu menu("Menu");
    BuildMenu(menu);
    int menuChoice;
    char firstChar = ' ';
    char lastChar = '~';
    do
    {
        menu.display();
        menuChoice = menu.getChoice();
        switch (menuChoice)
        {
        case -1:
        case 1:
            break;
        case 2:
        {
            TextItems text("display_ascii3.txt");
            text.displayItem("ProgramDescription");
            break;
        }
        case 3:
        {
            do
            {
                GetAsciiRangeFromUser(firstChar, lastChar);
                AsciiGenerator hAscii(firstChar, lastChar);
                hAscii.displayHorizontally();
            }
            while (userSaysYes("Display another range using this format?"));
            break;
        }
        case 4:
            do
            {
                GetAsciiRangeFromUser(firstChar, lastChar);
                AsciiGenerator vAscii(firstChar, lastChar);
                vAscii.displayVertically();
            }
            while (userSaysYes("Display another range using this format?"));
            break;
        }
    }
    while ((menuChoice != 1) && (menuChoice != -1));
    Pause(0, "Program now terminating.");
}

void BuildMenu
(
    Menu& menu
)
{
    menu.addOption("Quit");
    menu.addOption("Get information");
    menu.addOption("Display ASCII codes horizontally "
        "(increasing across rows)");
    menu.addOption("Display ASCII codes vertically (increasing down columns)");
}

void GetAsciiRangeFromUser
(
    char& firstChar,
    char& lastChar
)
{
    cout << "\nChoose ASCII character end points for the range of values "
        "you wish to display.\nBoth end point characters must lie "
        "in the range of characters from ' ' to '~'.\n"
        "Also, the start character must precede the end character "
        "in the ASCII sequence.\n\n";

    do
    {
        ReadChar("Enter start character for the table display: ", firstChar);
        if (firstChar  < ' ' || firstChar > '~')
        {
            cout << "\nError: The first character of that entry"
                " was not a printable character.\n"
                "Try again. Be careful to enter valid "
                "starting/ending characters for the table.\n\n";
            continue;
        }
        ReadChar("Enter end character for the table display "
            "(>= previous value): ", lastChar);
        if (lastChar  < ' ' || lastChar > '~')
        {
            cout << "\nError: The first character of that entry"
                " was not a printable character.\n"
                "Try again. Be careful to enter valid "
                "starting/ending characters for the table.\n\n";
            continue;
        }

        if (lastChar < firstChar)
        {
            cout << "\nError: The starting character for the "
                "table display must not follow\n"
                "the ending character in the ASCII sequence. Try again.\n\n";
        }
    }
    while ((lastChar < ' ' || lastChar > '~')
        || (firstChar  < ' ' || firstChar > '~')
        || (lastChar < firstChar));
}

