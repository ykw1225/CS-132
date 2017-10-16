//
#include<iostream>
using namespace std;

class StaticStack{
private:
	int* array;
	int size;
	int tail;
public:
	StaticStack(int s){
		tail = -1;
		size = s;
		array = new int[size];
	}
	void push(int n){
		if(isFull()){cout << "Stack is Full!\n"; return;}
		tail++;
		*(array+tail) = n;
	}
	void pop(int& n){
		if(isEmpty()){cout << "Stack is Empty!\n"; return;}
		n = *(array+tail);
		tail--;
	}
	int pop(){
		if(isEmpty()){cout << "Stack is Empty!\n"; return -1;}
		tail--;
		return *(array+tail+1);
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
	StaticStack ss(5);
	ss.push(0);ss.push(1);ss.push(2);
	ss.display();
	ss.push(3);ss.push(4);ss.push(5);
	ss.display();
	ss.pop();ss.pop();ss.pop();
	ss.display();
	ss.pop();ss.pop();ss.pop();
	ss.display();
	system("pause");
	return 0;
}