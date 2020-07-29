//
// Created by Radwan on 7/26/2020.
//

#include <iostream>
#include <exception>

struct node {
    int value;
    node* next;
};


struct List {

    List() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }


    void print() const {
        std::cout << "[";
        node* n = head;
        for (; n->next != nullptr; n = n->next) {
            std::cout << n->value << ", ";
        }
        std::cout << n->value << "]" << std::endl;

    }


    int operator[](int index) {
        if (index < size) {
            node* tmp = head;
            for (int i = 0; i < index; i++) {
                tmp = tmp->next;
            }
            return tmp->value;
        }
        else {
            std::string error("the index is out of range");
            throw std::out_of_range(error);

        }
    }
    int len() {
        return size;
    }

    void push(int n) {
        node* tmp = new node;
        tmp->value = n;
        tmp->next = nullptr;
        if (size == 0) {
            head = tail = tmp;
        }
        else {
            tail->next = tmp;
            tail = tmp;
        }
        size++;
    }
    void pushLeft(int v) {
        node* tmp = new node;
        tmp->value = v;
        tmp->next = head;
        head = tmp;
        size++;

    }

    void push(int value, int index) {
        if ((index <= size) && (index >= 0)) {
            if (index == 0)
                pushLeft(value);
            else if (index == size)
                push(value);
            else {
                auto tmp = head;
                auto aux = new node;
                aux->value = value;
                for (auto i = 0; i < index - 1; i++) {
                    tmp = tmp->next;
                }
                aux->next = tmp->next;
                tmp->next = aux;
                size++;
            }
        }


    }

    int pop() {
        auto tmp = head;
        auto value = tmp->value;
        head = tmp->next;
        delete(tmp);
        size--;
        return value;
    }
    int popRight() {
        auto tmp = head;
        int value = tail->value;
        while (tmp->next != tail) {
            tmp = tmp->next;
        }
        tail = tmp;
        tail->next = nullptr;
        delete(tmp->next);
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
                delete aux;
                size--;
                return value;
            }


        }
        else
            throw std::out_of_range("index is out of range");
    }

    ~List() {
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

int main() {
    int size;
    List l = List();
    std::cout << "enter list size" << std::endl;
    std::cin >> size;
    for (auto i = 0; i < size; i++) {
        int x;
        std::cin >> x;
        l.push(x);
    }
    l.print();
    std::cout << "size := " << l.len() << std::endl;

    try {

        std::cout << l[1] << std::endl;
    }
    catch (std::out_of_range & e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    l.pop(3);
    l.print();
    return 0;
}

