//Menu.cpp
//Rahman:Jawadur:A00434830:u28
//Submission 04
//Implementing a Simple Student::Menu Class

/*
 * The program functions as desired and if is properly formatted
*/

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <cstring>
#include "menu.h"

using namespace std;
using Student::Menu;

//Implementation file corresponding to menu.h

/*
Private data members of the Menu class:
int numberOfOptions;
char* titlePtr;
struct OptionNode
{
    char* optionTextPtr
    OptionNode* link
};
OptionNode* firstNodePtr;
OptionNode* lastNodePtr;
*/

extern const string MY_ID_INFO = "Rahman:Jawadur:A00434830:u28";

Menu::Menu()
{

    string defaultTitle = "Empty Menu";
    titlePtr = new char[defaultTitle.length() + 1];
    strcpy(titlePtr, defaultTitle.c_str());
    firstNodePtr = nullptr;
    lastNodePtr = nullptr;
    numberOfOptions = 0;
}

Menu::~Menu()
{
    cout <<  "Deleting menu title: " << titlePtr << endl;
    delete [] titlePtr;

    int count = 1;
    while (firstNodePtr != nullptr)
    {
        OptionNode* current = firstNodePtr;
        firstNodePtr = firstNodePtr->link;
        cout << "Deleting text in node " << count << ": "
            << current->optionTextPtr << endl;
        delete current->optionTextPtr;
        cout << "Deleting node " << count << " itself." << endl;
        delete current;
        count++;
    }
    cout << "Press Enter to continue ... "; cin.ignore(80, '\n');
}


void Menu::setTitle
(
    const string& menuTitle
)
{
    titlePtr = new char[menuTitle.length() + 1];
    strcpy(titlePtr, menuTitle.c_str());
}

void Menu::addOption
(
    const string& option
)
{
    numberOfOptions++;
    if (firstNodePtr == nullptr)
    {
        firstNodePtr = new OptionNode;
        firstNodePtr->optionTextPtr = new char[option.length() + 1];
        strcpy(firstNodePtr->optionTextPtr, option.c_str());
        firstNodePtr->link = nullptr;

        lastNodePtr = firstNodePtr;
    }
    else
    {
        OptionNode* next = new OptionNode;
        next->optionTextPtr = new char[option.length() + 1];
        strcpy(next->optionTextPtr, option.c_str());
        next->link = nullptr;

        lastNodePtr->link = next;
        lastNodePtr = next;
    }

}

void Menu::display() const
{
    OptionNode* current = firstNodePtr;
    int count = 1;
    int linesInMid = 2;

    linesInMid += numberOfOptions;
    int blankLinesTop = (int)ceil((23 - linesInMid) / 2.0);
    int blankLinesBot = (int)floor((24 - linesInMid) / 2.0);

    for (int i = 0; i < blankLinesTop; i++)
    {
        cout << endl;
    }

    cout << titlePtr << endl << endl;
    if (current == nullptr)
    {
        cout << "This menu currently has no options ... " << endl;
    }

    while (current != nullptr)
    {
        cout << count << ". " << current->optionTextPtr << endl;
        current = current->link;
        count++;
    }
    for (int i = 0; i < blankLinesBot; i++)
    {
        cout << endl;
    }
}

int Menu::getChoice() const
{
    if (numberOfOptions == 0)
    {
        cout << "\n===== Error: The menu has no options from which to choose.";
        cout << "\nPress Enter to continue ... "; cin.ignore(80, '\n');
        return -1;
    }
    int choice;
    cout << "Enter the number of your menu choice here and press Enter: ";
    string choiceStr;
    getline(cin, choiceStr);
    choice = atoi(choiceStr.c_str());

    return choice;
}
