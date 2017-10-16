// CS-132 HW 18-2
// KIT WONG
// 5-29-2015
// used 30 min

#include<iostream>
using namespace std;

class DynamicStack{
private:
	struct Node{
		int data;
		Node* next;
	};
	Node* tail;
public:
	DynamicStack(){tail = NULL;}
	void push(int n){
		Node* newNode = new Node;
		newNode->data = n; newNode->next = NULL;
		if(!isEmpty()){
			newNode->next = tail;
			tail = newNode;}
		else tail = newNode;
	}
	int pop(){
		int n;
		if(!isEmpty()){
			Node* temp = tail;
			n = tail->data;
			tail = tail->next;
			delete temp;
		}else{cout << "Stack is Empty!" << endl;}
		return n;
	}
	bool isEmpty(){
		if(tail != NULL) return false;
		return true;
	}
	void display(){
		if(!isEmpty()){
			DynamicStack temp;
			int tempNum;
			while(!isEmpty())temp.push(pop());
			while(!temp.isEmpty()){
				tempNum = temp.pop();
				cout << tempNum << " ";
				push(tempNum);}
			cout << endl;
		}else{cout << "Stack is Empty!" << endl;}
	}
};

int main(){
	DynamicStack ss;
	ss.push(0);ss.push(1);ss.push(2);
	ss.display();
	ss.push(3);ss.push(4);ss.push(5);
	ss.display();
	ss.pop();ss.pop();ss.pop();
	ss.display();
	ss.pop();ss.pop();ss.pop();
	ss.display();
	return 0;
}
