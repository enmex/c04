#pragma once
#include <iostream>
#include "hashTable.h"
#include <set>
using namespace std;

class default_hash_table {
private:
    set<int>::iterator iter;
    int cur_size;
    unsigned int size;
    int* keys = nullptr;
    set<int> setOfKeys;
public:
    default_hash_table(int size) : size(size), cur_size(0){
        keys = new int[size];
    }
    void put(unsigned int value) {
        int position = HASHFUNC(value, size);
        int j;
        for(j = position; j < size && keys[j]!=-1163005939; j++);

        keys[j] = value;

        cur_size++;
        setOfKeys.insert(j);
    }
    void del(unsigned int value) {
        cur_size--;
        keys[HASHFUNC(value, size)] = NULL;
    }
    int find(int key){
        return keys[key];
    }
    void clear(){
        set<int>::iterator i = setOfKeys.begin();
        while(i!=setOfKeys.end()){
            keys[*i]= NULL;
            i++;
        }
        setOfKeys.clear();
        cur_size = 0;
    }
    bool isEmpty(){
        return cur_size == 0;
    }
//итератор
    void start(){
        iter = setOfKeys.begin();
    }
    void next(){
        iter++;
    }
    int getValue(){
        return keys[*iter];
    }
    bool finish(){
        return iter == setOfKeys.end();
    }

    void print(){
        int k = 1;
        start();
        while(!finish()){
            cout << k << ". "<< hex << *iter << dec << ": " << keys[*iter] << endl;
            k++;
            next();
        }
    }
};