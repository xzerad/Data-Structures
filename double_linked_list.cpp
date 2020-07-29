//
// Created by Radwan on 7/28/2020.
//

#include <iostream>
#include <exception>

struct node {
    node* previous;
    int value;
    node* next;

    node& operator=(int v){
        this->value = v;
        return *this;
    }
};

struct Double_List {

    Double_List() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    Double_List(Double_List& dl){
        if(dl.head == nullptr)
            head = tail = nullptr;
        else{
            head = new node;
            head->value = dl.head->value;
            head->previous = nullptr;
            auto tmp = head;
            auto aux = dl.head;

            for(; aux->next != nullptr; aux = aux->next){
                tmp->next = new node;
                tmp->next->previous = tmp;
                tmp = tmp->next;
                tmp->value = aux->value;
            }
            tail = aux;
            tail->next = nullptr;
        }

    }


    Double_List& operator=(Double_List& dl){
        Double_List tmp(dl);
        return tmp;


    }



    void push(int v) {
        if(size >0){
        auto tmp = new node;
        tail->next = tmp;
        tmp->previous = tail;
        tmp->value = v;
        tmp->next = nullptr;
        tail = tmp;
        }else{
            head = tail = new node;
            head->previous = nullptr;
            tail->next = nullptr;
            head->value = v;
        }
        size++;

    }


    void pushLeft(int v) {
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

    void push(int v, int index) {
        if ((index <= size) && (index >= 0)) {
            if (index == 0)
                pushLeft(v);
            else if (index == size)
                push(v);
            else {
                auto tmp = head;
                auto aux = new node;
                aux->value = v;
                for (auto i = 0; i < index - 1; i++) {
                    tmp = tmp->next;
                }

                aux->next = tmp->next;
                tmp->next->previous = aux;
                aux->previous = tmp;
                tmp->next = aux;

                size++;
            }
        }
        else {
            throw std::out_of_range("index out of range");
        }


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
    int popRight() {
        auto tmp = tail;
        auto value = tail->value;
        tail = tail->previous;
        tail->next = nullptr;
        delete tmp;
        size--;
        return value;
    }

    int pop(int index) {
        if ((index <= size) && (index >= 0)) {
            if (index == 0) {
                return popRight();
            }
            else if (index == size) {
                return pop();
            }
            else {
                auto tmp = head;
                for (auto i = 0; i < index - 1;i++) {
                    tmp = tmp->next;
                }
                auto aux = tmp->next;
                auto value = aux->value;
                tmp->next = tmp->next->next;
                tmp->next->previous = tmp;
                delete aux;
                size--;
                return value;
            }


        }
        else
            throw std::out_of_range("index is out of range");
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

    node& operator[](int index) {
        if (index < size) {
            node* tmp = head;
            for (int i = 0; i < index; i++) {
                tmp = tmp->next;
            }
            return *tmp;
        }
        else {
            throw std::out_of_range("index is out of range");

        }
    }

    friend std::ostream& operator<<(std::ostream& o, node& n);

    ~Double_List() {
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

std::ostream& operator<<(std::ostream& o, node& n){
    o<<n.value;
    return o;
}




int main() {

    Double_List dl ;
    dl.push(5);
    dl.push(7);
    dl.push(9);
    dl.push(5);
    dl.push(11);
    dl.print();
    dl[3] = 6;
    std::cout<<dl[3]<<std::endl;
    dl.print();
    std::cout<<dl.pop()<<std::endl;
    dl.print();


    return 0;
}
