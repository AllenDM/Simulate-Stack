//
//  Queue.h
//  Simulate Stack
//
//  Created by Allen Moody on 10/12/14.
//  Copyright (c) 2014 FAMU. All rights reserved.
//

#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <iostream>

using namespace std;

template <typename T, int sz>
class Queue {
private:
    int capacity;
    T store[sz];
    int nEles;
public:
    Queue() {
        nEles=0;
        capacity=sz;
    }
    void Qinsert(T item) {
        if (nEles<capacity)
            store[nEles++] = item;
    }
    void Qremove() {
        if (nEles>0) {
            nEles--;
            for (int i=0; i<nEles; i++)
                store[i]=store[i+1];
        }
    }
    T Qfront() {
        return store[0];
    }
    bool Qempty() {
        return nEles==0;
    }
    void display() {
        cout <<"Q[ ";
        for (int i = 0; i < nEles; i++)
            cout << store[i] << ',';
        cout << "]" << endl;
    }
};

#endif // QUEUE_H_INCLUDED