//
// Created by Radwan on 7/28/2020.
//

#include <iostream>
#include <exception>

struct node {
    node* previous;
    int value;
    node* next;
};

struct Double_List {
    Double_List() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    Double_List(Double_List& Dl) {
        
    }
    
    void push(int v);
    void pushLeft(int v);
    void push(int v, int index);
    
    int pop();
    int popRight();
    int pop(int index);
    
    int len();
    void print() const;
    
    int operator[](int index);

    ~Double_List();




private:
    node* head;
    node* tail;
    int size;
};



