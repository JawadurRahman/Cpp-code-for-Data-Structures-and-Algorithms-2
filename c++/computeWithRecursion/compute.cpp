//compute.cpp
//Rahman:Jawadur:A00434830:u28
//Submission 09
//Building and Evaluating Expression Trees

/*
This program is formated properly and functions properly.
*/

//header files
#include <cctype>
#include <iostream>
#include <climits>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

#include "utilities.h"
using Scobey::DisplayOpeningScreen;
using Scobey::Pause;

/**
A type used for labeling the data content of a binary expression tree node.
*/
enum TagType
{
    INT_ONLY,
    SUB_NODE
};

/**
The type used for the nodes of a binary expression tree.
*/
struct TreeNode
{
    TagType tag;
    union //Note that this union type is "anonymous".
    {
        int intValue;
        struct //And this struct type is also anonymous.
        {
            TreeNode* left;
            char op;
            TreeNode* right;
        };
    };
};

/**
A global variable to hold the binary expression tree.
*/
TreeNode eTree;

int valueOf
(
    TreeNode node //in
);
/**<
Returns the value of a node. The "value" of any "node" in the tree is
interpreted to be:
    - The value of the integer in the node, if the node does contain
      an integer.
    - Otherwise, it is the value of the node which is the left child
      of the given node, combined with the value of the node which is
      the right child of the given node (in that order) using the
      operator that is in the given node.
@param node The node of which its value will be returned.
@pre The node is initialized.
@post Returns an Integer value of the node.
*/

bool expressionFound
(
    istringstream& iss  //in
);
/**<
Reads the input string stream and returns true if the expression is valid.
Also puts the expression in a TreeNode.
@param iss The istringstream which will be read from.
@pre The TreeNode is initialized and istringstream has an expression.
@post Returns if expression is valid and expression tree is finished building.
*/


int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        DisplayOpeningScreen("Rahman:Jawadur:A00434830:u28",
            "\nSubmission 09"
            "\nImplementing a Simple Four-Function Calculator");
        cout << R"(

This program is a simple four-function calculator, with command-line input.
Only integer arithmetic using four operators (+, -, *, or /) is permitted.

Each line of input is limited to either a single positive integer, or a
fully-parenthesized arithmetic expression containing only binary operators
and positive integer operands.

To avoid the problem of meta character interpretation by the shell, we
enclose each full expression within double quotes.

Extra spaces in valid input are ignored, but any characters other than blank
spaces that appear after a valid expression and on the same line will cause
that entire input line to be rejected as bad input.)"
            << "\n\n\n\n\n\n\n\n\n\n                                   "
            "                           Screen 1 of 1\n";
        Pause();
        return 0;
    }

    //Create a string containing the command-line expression with spaces before
    //and after an operaters. Used in output later.
    string expression = argv[1];
    expression.erase(remove(expression.begin(), expression.end(), ' '),
        expression.end());
    string s1 = "";
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] != '*' && expression[i] != '-' &&
            expression[i] != '/' && expression[i] != '+')
            s1 = s1 + expression[i];
        else
            s1 = s1 + " " + expression[i] + " ";
    }

    //Create an "input string stream" from command-line expression.
    istringstream iss(expression);

    //check if expression is valid or not
    bool valid = expressionFound(iss);
    if (valid)
    {
        string endStr;
        iss >> endStr;

        //expression is not valid, has non whitespace chars at end
        if (endStr.find_first_not_of(' ') != string::npos)
        {
            cout << endl << "Bad input! Could not compute value." << endl;
            Pause();
            return 0;
        }

        // expression is valid
        cout << s1 << " = " << valueOf(eTree) << endl;
        Pause();
    }
    else
    {
        cout << endl << "Bad input! Could not compute value." << endl;
        Pause();
    }

}


int valueOf
(
    TreeNode node //in
)
{
    if (node.tag == INT_ONLY)
        return node.intValue;
    else //It must now be the case that node.tag == SUB_NODE
    {
        if (node.op == '+')
            return valueOf(*node.left) + valueOf(*node.right);
        if (node.op == '*')
            return valueOf(*node.left) * valueOf(*node.right);
        if (node.op == '-')
            return valueOf(*node.left) - valueOf(*node.right);
        if (node.op == '/')
            return valueOf(*node.left) / valueOf(*node.right);
        return INT_MIN;
    }
}

bool expressionFound
(
    istringstream& iss //in
)
{

    char c;
    c = iss.peek();
    //removes whitespace from front of expression
    while (c == ' ')
    {
        c = iss.get();
        c = iss.peek();
    }

    //if a positive integer is read
    if (isdigit(c))
    {
        int n;
        iss >> n;
        TreeNode tree;
        tree.tag = INT_ONLY;
        tree.intValue = n;
        eTree = tree;
        return true;
    }

    //else if a left parenthesis is read then
    else if (c == '(')
    {
        TreeNode tree;
        tree.tag = SUB_NODE;
        iss.get();

        //if expressionFound finds another valid expression then
        if (expressionFound(iss))
        {
            //put in left node
            tree.left = new TreeNode;
            *tree.left = eTree;

            //if a valid operator is read then
            char op;
            iss >> op;
            if (op == '*' || op == '+' || op == '-' || op == '/')
            {
                tree.op = op;

                //if expressionFound finds another valid expression then
                if (expressionFound(iss))
                {
                    //put in right node
                    tree.right = new TreeNode;
                    *tree.right = eTree;

                    //if a right parenthesis is read
                    char rPara;
                    iss >> rPara;
                    if (rPara == ')')
                    {
                        //save the subtree to global variable
                        eTree = tree;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
