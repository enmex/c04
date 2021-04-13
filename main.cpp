#include "hashTable.h"
#include <iostream>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));
    hashTable table(9973);
    
    int min = 1;
    int max = 6748392;
    for(int i = 0; i < 30; i ++){
        table.put(min + (rand() % ((max - min) + 1)));
    }
    table.print();
}