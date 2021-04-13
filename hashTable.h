#pragma once
#define HASHFUNC ((reinterpret_cast<unsigned int>(value) * 27644437) % size )
#include <iostream>
using namespace std;

class hashTable {
private:
    struct list {
        unsigned int value;
        list* next;
    };
    list* list_iter = nullptr;
    int iter;
    int cur_size;
    int size;
    list** keys = nullptr;
public:
    hashTable(int size) : size(size), cur_size(0){
        keys = new list*[size];
        for(int i = 0; i < size; i++){
            keys[size] = nullptr;
        }
    }
    void put(unsigned int value) { 
       // cout << value << " " << HASHFUNC;
        keys[HASHFUNC]->value;
        cur_size++;     
    }
    void del(unsigned int value) {
        if(keys[HASHFUNC] == nullptr){
            throw "error";
        } 
        cur_size--;
        delete keys[HASHFUNC];
    }
    list* find(int key){
        return keys[key];
    }
    void clear(){
        for(int i = 0; i < size; i++){
            delete keys[i];
        }
        cur_size = 0;
        delete[] keys;
    }
    bool isEmpty(){
        return cur_size == 0;
    }
    bool contains(int position, unsigned int value){
        list* temp = keys[position];
        while(temp->next!=nullptr){
            if(temp->value == value){
                return true;
            }
        }
        return false;
    }

//итератор
    void start(){
        iter = 0;
    }
    void next(){
        iter++;
    }
    list* getValue(){
        return keys[iter];
    }
    bool finish(){
        return iter == size-1;
    }
//итератор для linkedhash
    void list_start(){
        list_iter=keys[iter];       
    }
    void list_next(){
        list_iter = list_iter->next;
    }
    unsigned int list_getValue(){
        return list_iter->value;
    }
    bool list_finish(){
        return list_iter->next == nullptr;
    }

    void print(){
        start();
        while(!finish()){
            if(getValue()!=nullptr){
                cout << iter << ": " << getValue()->value;
                //list_start();
                /*
                while(!list_finish()){
                    cout << list_getValue() << "->";
                    list_next();
                }
                */
                cout << "nullptr" << endl;
            }
            next();
        }
    }
};