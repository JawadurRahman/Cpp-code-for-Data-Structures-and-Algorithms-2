//functions.cpp
//Rahman:Jawadur:A00434830:u28
//Submission 06
//Gathering Odds and Evens

/*
 * Working fine and is documented and formatted properly
*/

//#include whatever headers you need
#include <algorithm>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <list>
#include <deque>
using namespace std;

#include "utilities.h"
using Scobey::Pause;
using Scobey::RandomGenerator;

extern const string MY_ID_INFO = "Rahman:Jawadur:A00434830:u28";

//Two auxiliary "helper functions"
int isOdd(int n)
{
    return n % 2 == 1;
}

int isEven(int n)
{
    return n % 2 == 0;
}

void DisplayProgramInfo()
{
    cout << R"(

This program takes a single non-negative integer on the command line as input.
If it is missing, an opening screen is displayed, followed by this information.
If the value supplied is > 0, the generated values will repeat each time that
value is used. If the value is 0, the values will be different on each run.

The program then generates random two-digit integer values from the range
10..99. It puts some of them into a deque and some of them into a list. The
number of values in the deque, as well as the number in the list, is itself
a random number in the range 10..15. Next the program displays the contents
of the deque and the list, with positions numbered so that it is easy for
the viewer to see how many values are in each container.

The program then calls a first function, that arranges for all of the odd
values in both the deque and the list to be placed in the deque, and all
the even numbers from both the deque and the list to be placed in the list.
Furthermore, the deque is sorted ascending and the list descending, and
duplicate values are removed from each. The contents of the deque and the
list are then displayed as before, to confirm that this has been done.

Finally, the program calls a second function, implemented differently, to
perform the same actions on copies of the original deque and list.

                                                                 Screen 1 of 1
)";
    Pause();
}

void SeedRandomGeneratorIfRequired
(
    int seedValue,           //in
    RandomGenerator& randGen //inout
)
{
    if (seedValue > 0)
    {
        randGen.reset(seedValue);
    }
}

void GenerateRandomValues
(
    RandomGenerator& randGen, //inout
    deque<int>& theDeque,     //inout
    list<int>& theList        //inout
)
{
    int dequeSize = randGen.getNext(10, 15);
    int listSize = randGen.getNext(10, 15);
    theDeque.clear();
    theList.clear();

    for (int i = 1; i <= dequeSize; i++)
    {
        theDeque.push_back(randGen.getNext(10, 99)); 
    }
    
    for (int i = 1; i <= listSize; i++)
    {
        theList.push_back(randGen.getNext(10, 99)); 
    }
}

void GatherOddsInDequeEvensInList1
(
    deque<int>& theDeque, //inout
    list<int>& theList    //inout
)
{
    //initialize a local container and place all the values in it
    deque<int> holdDeque(theDeque);
    holdDeque.insert(holdDeque.begin(), theList.begin(), theList.end());

    //clear the list and deque and resize it to max possible size
    theDeque.clear();
    theList.clear();
    theDeque.resize(distance(holdDeque.begin(), holdDeque.end()));
    theList.resize(distance(holdDeque.begin(), holdDeque.end()));
    
    //copy all odds to deque and evens to list
    auto it = 
        copy_if(holdDeque.begin(), holdDeque.end(), theDeque.begin(), isOdd); 
    theDeque.resize(distance(theDeque.begin(), it));
    auto itTwo = 
        copy_if(holdDeque.begin(), holdDeque.end(), theList.begin(), isEven);
    theList.resize(distance(theList.begin(), itTwo));
    
    //sort and uniquify the deque
    sort(theDeque.begin(), theDeque.end());
    auto itThree = unique(theDeque.begin(), theDeque.end());
    theDeque.resize(distance(theDeque.begin(), itThree));
    
    //sort, reverse and uniquify the list
    theList.sort();
    theList.reverse();
    theList.unique();
}

void GatherOddsInDequeEvensInList2
(
    deque<int>& theDeque, //inout
    list<int>& theList    //inout
)
{
    //insert all values in both list and deque
    theDeque.insert(theDeque.begin(), theList.begin(), theList.end()); 
    theList.insert(theList.begin(), theDeque.begin(), theDeque.end());

    //remove evens from deque and odds from list
    auto it = 
        remove_if(theDeque.begin(), theDeque.end(), isEven); 
    theDeque.resize(distance(theDeque.begin(), it));
    auto itTwo = 
        remove_if(theList.begin(), theList.end(), isOdd); 
    theList.resize(distance(theList.begin(), itTwo));

    //sort and uniquify the deque
    sort(theDeque.begin(), theDeque.end());
    auto itThree = unique(theDeque.begin(), theDeque.end());
    theDeque.resize(distance(theDeque.begin(), itThree));
    
    //sort, reverse and uniquify the list 
    theList.sort();
    theList.reverse();
    theList.unique();
}

void DisplayContentsOfDequeAndList
(
    const deque<int>& theDeque, //in
    const list<int>& theList    //in
)
{
    int maxSize = 
        (theDeque.size() > theList.size()) ? theDeque.size() : theList.size();

    cout << endl << "              ";
    for (int i = 1; i <= maxSize; i++)
    {
        cout << setw(3) << i;
    }
    cout << endl;
    
    cout << "For the deque: ";
    copy(theDeque.begin(), theDeque.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    
    cout << "For the list:  " ;
    copy(theList.begin(), theList.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

