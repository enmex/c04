#pragma once
#include <iostream>
#include "list.h"
#include <set>
using namespace std;

unsigned int HASHFUNC(unsigned int value, int size){
    return (((reinterpret_cast<unsigned int>(value) * 27644437) % (size) ));
}

class hashTable {
private:
    set<int>::iterator iter;
    int cur_size;
    unsigned int size;
    list* list_iter;
    list* keys = nullptr;
    set<int> setOfKeys;
public:
    hashTable(int size) : size(size), cur_size(0){
        keys = new list[size];
    }
    void put(unsigned int value) {
        int position = HASHFUNC(value, size);
        keys[position].push(value);
        cur_size++;     
        setOfKeys.insert(position);
    }
    void del(unsigned int value) {
        cur_size--;
        keys[HASHFUNC(value, size)].clear();
    }
    list find(int key){
        return keys[key];
    }
    void clear(){
        set<int>::iterator i = setOfKeys.begin();
        while(i!=setOfKeys.end()){
            keys[*i].clear();
            i++;
        }
        setOfKeys.clear();
        cur_size = 0;
    }
    bool isEmpty(){
        return cur_size == 0;
    }
    bool contains(unsigned int key, unsigned int value){
        return keys[key].contains(value);
    }
//итератор
    void start(){
        iter = setOfKeys.begin();
    }
    void next(){
        iter++;
    }
    list getValue(){
        return keys[*iter];
    }
    bool finish(){
        return iter == setOfKeys.end();
    }
//итератор для linkedhash
    void list_start(){
        list_iter = new list(getValue());
        list_iter->start();
    }
    void list_next(){
        list_iter->next();
    }
    unsigned int list_getValue(){
        return list_iter->get();
    }
    bool list_finish(){
        return list_iter->isEnd();
    }

    void print(){
        int k = 1;
        start();
        while(!finish()){
            list_start();//ноль не считаем (т.е 0 и единственное значение = 2)
            if(getValue().length()>1){
                cout << k << ". " << hex << *iter << dec << ": ";
                do{
                    cout << list_getValue() << "->";
                    list_next();
                }
                while(!list_finish());
                cout << "nullptr" << endl;
                k++;
            }
            next();
        }
    }
};