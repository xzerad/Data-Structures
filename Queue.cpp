//
// Created by Radwan on 7/29/2020.
//

#include <iostream>
#include <exception>

struct node {
    node* previous;
    int value;
    node* next;


};

struct Queue {

    Queue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void push(int v) {
        if(size >0){
            head->previous = new node;
            head->previous->next = head;
            head = head->previous;
            head->previous = nullptr;
            head->value = v;
        }else{
            head = tail = new node;
            head->previous = nullptr;
            tail->next = nullptr;
            head->value = v;
        }
        size++;


    }

    int pop() {
        auto tmp = head;
        auto value = head->value;
        head = head->next;
        head->previous = nullptr;
        delete tmp;
        size--;
        return value;

    }


    int len() {
        return size;
    }

    void print() const {
        std::cout << "[";
        node* n = head;
        for (; n != nullptr; n = n->next) {
            std::cout << n->value ;
            if(n->next)
                std::cout<< ", ";
        }
        std::cout << "]" << std::endl;

    }

    ~Queue() {
        auto n = head;
        while (n != nullptr) {
            auto tmp = n;
            n = n->next;
            delete (tmp);
        }
    }




private:
    node* head;
    node* tail;
    int size;
};


int main(){

    Queue s = Queue();
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s.print();
    std::cout<<s.pop()<<std::endl;
    s.print();
    return 0;
}

