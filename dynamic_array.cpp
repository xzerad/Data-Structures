//
// Created by Radwan on 8/5/2020.
//

#include <iostream>
#include <exception>

template <class T>
class Dynamic_array{
    T* arr;
    int len;
    int capacity;
public:

    Dynamic_array(){
        arr = nullptr;
        len = 0;
        capacity = 0;
    }

    void add(T value){
        if(len  == 0){
            len++;
            arr = new T[len];
	    arr[capacity++] = value;
        } else if (len == capacity){
            capacity = capacity*2;
            T* new_arr =  arr;
            arr = new T[capacity];
            auto i =0;
            for( ; i<len; i++ ){
                arr[i] = new_arr[i];
            }
            arr[i] = value;
            len++;
        }else{
            arr[len++] = value;
        }
    }


    int size() const{
        return len;
    }

    bool isEmpty() const{
        return len == 0;
    }

    T& operator[](int index){
        if ((index> len-1) || (index<0))
            throw std::out_of_range("index out of range");
        return arr[index];
    }

    T removeAt(int index){
        if( (index < 0)||(index > len-1))
            throw std::out_of_range("index out of range");
        else{
            T value = arr[index];
            T* new_arr = new T[len-1];
            for(auto i=0, j=0; i<len; i++, j++){
                if(i == index)
                    j--;
                else{
                    new_arr[j] == arr[i];
                }
            }
            arr = new_arr;
            capacity = --len;
            return value;
        }
    }

    void remove(T elem){
        for(auto i=0; i<len; i++){
            if(arr[i] == elem)
                removeAt(i);
        }
    }

    int indexOf(T elem){
        for(auto i=0; i<len ; i++){
            if(arr[i]== elem)
                return i;
        }
        return -1;
    }

    bool contains(T elem){
        return indexOf(elem) != -1;
    }

    template<class U>
    friend std::ostream& operator<< (std::ostream& o , Dynamic_array<U>& d);


    void clear(){
        delete[] arr;
        len = 0;
        capacity = 0;
        arr = nullptr;
    }

    ~Dynamic_array(){
        clear();
    }


};

template <class t>
std::ostream& operator<< (std::ostream& o , Dynamic_array<t>& d){
    o<<'[';
    for(auto i=0; i<d.len-1; i++){
            o<<d.arr[i]<<',';
    }
    o<<d.arr[d.len-1]<<']';
    return o;
}


int main(){

    Dynamic_array<int> t{};
    t.add(5);
    t.add(6);
    t.add(9);
    t[1] = 8;
    std::cout<<t<<std::endl;
    t.add(1);
    t.add(6);
    t.add(6);
    t.add(5);
    t.add(4);
    t.add(3);
    t.add(0);
    t.add(0);
    t.add(2);
    t.add(4);
    t.add(6);
    t.add(9);
    t.add(6);
    std::cout<<t.size()<<std::endl;
   
    std::cout<<t<<std::endl;

    t.clear();
    if(t.isEmpty()){
	t.add(5);
	t.add(6);
    }
    std::cout<<t<<std::endl;
    return 0;
}
