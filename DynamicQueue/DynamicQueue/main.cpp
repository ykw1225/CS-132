#include<iostream>
using namespace std;

class DynamicQueue{
private:
	struct Node{
		int data;
		Node* next;
	};
	Node* head;
public:
	DynamicQueue(){head = NULL;}
	void enqueue(int n){
		Node* newNode = new Node;
		newNode->data = n; newNode->next = NULL;
		if(!isEmpty()){
			Node* current = head;
			while(current->next) current = current->next;
			current->next = newNode;
		}else{head = newNode;}
	}
	int dequeue(){
		int n;
		if(!isEmpty()){
			Node* temp = head;
			n = head->data;
			head = head->next;
			delete temp;
		}else{cout << "Queue is Empty!" << endl;}
		return n;
	}
	bool isEmpty(){
		if(head != NULL) return false;
		return true;
	}
	void display(){
		if(!isEmpty()){
			Node* current = head;
			cout << current->data << " ";
			while(current->next){
				current = current->next;
				cout << current->data << " ";}
			cout << endl;
		}else{cout << "Queue is Empty!" << endl;}
	}
};

int main(){
	DynamicQueue ss;
	ss.enqueue(0);ss.enqueue(1);ss.enqueue(2);
	ss.display();
	ss.enqueue(3);ss.enqueue(4);ss.enqueue(5);
	ss.display();
	ss.dequeue();ss.dequeue();ss.dequeue();
	ss.display();
	ss.dequeue();ss.dequeue();ss.dequeue();
	ss.display();
	system("pause");
	return 0;
}