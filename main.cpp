  /**
   *  Author: Matthew Marinets
   *  Date: 2018-10-13
   *  Copyright (c) 2018.
   */


#include <iostream>
#include "LinkedStack.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char* argv[]) {
    // 1. print name, login id, student number
    cout << "Matthew Marinets" << endl;
    cout << "mmarinet" << endl;
    cout << "301311930" << endl;

    // 2. Create instance(s) of the basic stack class
    LinkedStack<string> input_stack = LinkedStack<string>();
    LinkedStack<string> reverse_input_stack = LinkedStack<string>();

    // 3. Read in a sequence of strings from the keyboard, one per line, and terminated by the null string
    while (cin) {
        string input = string();
        std::getline(cin, input);
        if (input.length() == 0) {
            break;
        } else {
            input_stack.push(input);
        }
    }

    // 4. Output a blank line, followed by a line with the length of the sequence, followed by a line with a 
    // concatenation of the strings in reverse order, followed by another blank line; To determine the size of 
    // the sequence you must use the stack size function;
    cout << endl;
    cout << input_stack.size() << endl;
    while (!input_stack.empty()) {
        reverse_input_stack.push(input_stack.top());
        cout << input_stack.top();
        input_stack.pop();
    }
    cout << endl;

    // 5. Output the sequence of strings in the original order, one per line
    while (!reverse_input_stack.empty()) {
        cout << reverse_input_stack.top();
        reverse_input_stack.pop();
    }
    cout << endl;

    // 6. Output a (exactly one) "goodbye" line
    cout << "Goodbye" << endl;

    return 0;
}
