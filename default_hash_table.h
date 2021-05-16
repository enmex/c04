#pragma once
#include <iostream>
#include "hashTable.h"
#include <set>
using namespace std;

class default_hash_table {
private:
    set<int>::iterator iter; //итератор по массиву
    int cur_size; //текущий размер
    unsigned int size; //максимальный размер
    int* keys = nullptr; //массив ключей
    set<int> setOfKeys; //это множество занятых индексов
public:
    default_hash_table(int size) : size(size), cur_size(0){
        keys = new int[size];
    }
    void put(unsigned int value) {
        //основная идея - получаем индекс, затем сдвигаемся вниз до тех пор пока элемент под индексом не пустой
        int position = HASHFUNC(value, size);
        int j;
        for(j = position; j < size && keys[j]!=-1163005939; j++); //тут надо как-то проверить что элемент мусорный поэтому такое значение взял, но надо подругому)

        keys[j] = value;

        cur_size++;
        setOfKeys.insert(j); //включаем индекс в множество индексов
    }
    void del(unsigned int value) {
        cur_size--;
        keys[HASHFUNC(value, size)] = NULL; //просто зануляем значение под индексом
    }
    int find(int key){
        return keys[key];
    }
    void clear(){
        set<int>::iterator i = setOfKeys.begin(); //создаем итератор по множеству и гуляем по индексам
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