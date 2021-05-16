#include "hashTable.h"
#include "default_hash_table.h"
#include <iostream>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));
    hashTable table(9973); //создаем на 9973 элемента, это простое число, выбрал таким специально
    
    int min = 1;
    int max = 6748392;
    for(int i = 0; i < 1000; i++){
        unsigned int value = min + (rand() % ((max - min) + 1));
        table.put(value);
    }//добавляем рандомные значения
    table.print();
    cout << "Проверка обычной хэш-таблицы" << endl;
    default_hash_table dtable(9973);
    for(int i = 0; i < 1000; i++){
        unsigned int value = min + (rand() % ((max - min) + 1));
        dtable.put(value);
    }
    dtable.print();
}