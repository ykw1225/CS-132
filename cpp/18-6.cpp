// CS-132 HW 18-6
// KIT WONG
// 5-31-2015
// used 10 min

#include<iostream>
#include<string>
using namespace std;

class DynamicStringStack{
private:
	struct Node{
		string data;
		Node* next;
	};
	Node* tail;
public:
	DynamicStringStack(){tail = NULL;}
	void push(string s){
		Node* newNode = new Node;
		newNode->data = s; newNode->next = NULL;
		if(!isEmpty()){
			newNode->next = tail;
			tail = newNode;}
		else tail = newNode;
	}
	string pop(){
		string s;
		if(!isEmpty()){
			Node* temp = tail;
			s = tail->data;
			tail = tail->next;
			delete temp;
		}else{cout << "Stack is Empty!" << endl;}
		return s;
	}
	bool isEmpty(){
		if(tail != NULL) return false;
		return true;
	}
	void display(){
		if(!isEmpty()){
			DynamicStringStack temp;
			string tempS;
			while(!isEmpty())temp.push(pop());
			while(!temp.isEmpty()){
				tempS = temp.pop();
				cout << tempS << " ";
				push(tempS);}
			cout << endl;
		}else{cout << "Stack is Empty!" << endl;}
	}
};

int main(){
	DynamicStringStack ss;
	ss.push("ab");ss.push("bc");ss.push("cd");
	ss.display();
	ss.push("de");ss.push("ef");ss.push("fg");
	ss.display();
	ss.pop();ss.pop();ss.pop();
	ss.display();
	ss.pop();ss.pop();ss.pop();
	ss.display();
	return 0;
}
