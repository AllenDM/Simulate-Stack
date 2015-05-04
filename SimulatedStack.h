//
//  SimulatedStack.h
//  Simulate Stack
//
//  Created by Allen Moody on 10/12/14.
//  Copyright (c) 2014 FAMU. All rights reserved.
//

#ifndef SIMULATEDSTACK_H_INCLUDED
#define SIMULATEDSTACK_H_INCLUDED
//#include <queue>
#include "Queue.h"
// Allen Moody
// Prog 4 Simulated Stack
using namespace std;
template <typename T, int sz>
class sStack {
private:
    Queue<T,sz> store;
    Queue<T,sz> temp;
public:
    void push(T v) {
        store.Qinsert(v);
    }
    void pop() {
        int currentSize =0;
        while (!store.Qempty()){
            
            temp.Qinsert(store.Qfront());
            store.Qremove();
            currentSize++;
        }// Transfer store queue to temp queue
        
        
        int cutOff = currentSize;
        for (int i=1; i<cutOff; i++) {
            store.Qinsert(temp.Qfront());
            temp.Qremove();
        }// Adds first 4 values back to store Queue if it previously had 5 values
        temp.Qremove(); // Removes front value from temp, which was the top of the stack
                   }
    
    
    
     T top() {
         
         int currentSize =0;
         while (!store.Qempty()){
             
             temp.Qinsert(store.Qfront());
             store.Qremove();
             currentSize++;
         }// Transfer store queue to temp queue
         
         
         int cutOff = currentSize;
         for (int i=1; i<cutOff; i++) {
             store.Qinsert(temp.Qfront());
             temp.Qremove();
         }// Adds first 4 values back to store Queue if it previously had 5 values
         int top = temp.Qfront(); // Retrieves front value from temp, which was the top of the stack. Places
                                  // the value in top variable.
         store.Qinsert(temp.Qfront()); //Places top back on stack
         temp.Qremove(); //Removes store's top value from temp
         
         return top;
     }
    
    
         
    
    
    bool isEmpty() {
        
        return store.Qempty();
    }
    
    void display() {
        cout << "[ ";
        while (!(store.Qempty())) {
            T x = store.Qfront();
            store.Qremove();
            cout << x;
            if (!store.Qempty())
                cout << ',' ;
            temp.Qinsert(x);
        }
        while (!temp.Qempty()) {
            store.Qinsert(temp.Qfront());
            temp.Qremove();
        }
    }
};
#endif // SIMULATEDSTACK_H_INCLUDED