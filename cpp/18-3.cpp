// CS-132 HW 18-3
// KIT WONG
// 5-29-2015
// used 20 min

#include<iostream>
using namespace std;

class StaticQueue{
private:
	int* array;
	int size;
	int tail;
public:
	StaticQueue(int s){
		tail = -1;
		size = s;
		array = new int[size];
	}
	void enqueue(int n){
		if(isFull()){cout << "Queue is Full!\n"; return;}
		tail++;
		*(array+tail) = n;
	}
	int dequeue(){
		if(isEmpty()){cout << "Queue is Empty!\n"; return -1;}
		int n = *(array+0);
		for(int i = 0; i < tail; i++) *(array+i) = *(array+i+1);
		tail--;
		return n;
	}
	bool isEmpty(){
		if(tail < 0) return true;
		return false;
	}
	bool isFull(){
		if(tail+1 == size) return true;
		return false;
	}
	void display(){
		for(int i = 0; i < tail+1; i++) cout << *(array+i) << " ";
		cout << endl;
	}
};

int main(){
	StaticQueue ss(5);
	ss.enqueue(0);ss.enqueue(1);ss.enqueue(2);
	ss.display();
	ss.enqueue(3);ss.enqueue(4);ss.enqueue(5);
	ss.display();
	ss.dequeue();ss.dequeue();ss.dequeue();
	ss.display();
	ss.dequeue();ss.dequeue();ss.dequeue();
	ss.display();
	return 0;
}
