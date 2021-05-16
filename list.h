#include <iostream>
using namespace std;
struct node {
        int value = 0;
        node* next;
    };
class list{

    //а это реализация однонаправленного списка специально для хэш таблицы
private:
	node* list_; 
	node* head;
	int size;
    int pos;
public:
	list() : size(0), pos(0){
        head = nullptr;
		list_ = new node;
		list_->value = 0;
		list_->next = nullptr;
	};
    list(const list& _list) : list_(_list.list_), head(_list.head), size(_list.size), pos(_list.pos) {}
	~list() {
		clear();
		delete list_;
	};
    bool contains(unsigned int value){
        node* temp = list_;
        while(temp->next != nullptr){
            if(temp->value == value){
                return true;
            }
        }
        return false;
    }
	void push(int y) {
        node* temp = new node;
        temp->value = y;
        temp->next = list_;
        list_ = temp;
        head = list_;
        size++;
        pos++;
	};
    void clear(){
        node* temp = new node;
		list_ = head;
		while (list_ != nullptr) {
			pop();
		}
		size = 0;
		delete temp;
    }
	int pop() {
        start();
        head = list_->next;
		int a = list_->value;
		node* temp = list_->next;
        list_ = nullptr;
        list_ = temp;
        temp = nullptr;
        return a;
	};
	void next() {
        list_ = list_->next;
        pos++;
	};
	void start() {
		list_ = head;
        pos = 0;
	};
	unsigned int get() {
		return list_->value;
	};
    int length(){
        return size;
    }
    bool isEnd(){
        return pos == size;
    }
};