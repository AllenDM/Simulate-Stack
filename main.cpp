//
//  main.cpp
//  Simulate Stack
//
//  Created by Allen Moody on 10/12/14.
//  Copyright (c) 2014 FAMU. All rights reserved.
//

#include <iostream>
#include "SimulatedStack.h"

using namespace std;

typedef union {
    int i;
    char c;
} charOrInt;

sStack<int,10> stk; // need enough for all operands!!

int stackReduce(char op) {
    int rgt = stk.top();
    stk.pop();
    int lft = stk.top();
    stk.pop();
    switch (op) {
        case '*':
            return lft*rgt;
        case '/' :
            return lft / rgt;
        case '+' :
            return lft+rgt;
        default:
            return lft-rgt;
    }
}
int main() {
    const int RPNlen = 9;  // set to len of RPN
    charOrInt RPN[RPNlen]; // = {3, 4, 2,'*','+', 1,'-', 2, '/'};
    
    RPN[0].i = 3;
    RPN[1].i = 4;
    RPN[2].i =  2;
    RPN[3].c = '*';
    RPN[4].c = '+';
    RPN[5].i =  1;
    RPN[6].c = '-';
    RPN[7].i =  2;
    RPN[8].c =  '/';
    
    // show the expression stored
    cout << " expression: ";
    for (int n=0; n<RPNlen; n++)
        if (RPN[n].c=='*' || RPN[n].c=='+'
            || RPN[n].c=='-' || RPN[n].c=='/')
            cout << RPN[n].c << " ";
        else
            cout << RPN[n].i << " ";
    cout << endl << endl;
    
    // evaluate the expression
    for (int n=0; n<RPNlen; n++) {
        switch (RPN[n].c) {
            case '*':
            case '+':
            case '-':
            case '/':
                cout << RPN[n].c << ": " ;
                stk.push(stackReduce(RPN[n].c));
                break;
            default:
                cout << RPN[n].i << ": " ;
                stk.push(RPN[n].i);
        }
        stk.display();
        //cout << endl;
    }
    
    // report results
    int rslt = stk.top();
    stk.pop();
    if (stk.isEmpty())
        cout << "  value is " << rslt << endl;
    else
        cout << "   RPN error!" << endl;
    return 0;
}
