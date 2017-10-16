// CS-132 HW 17-1 & 4 & 5
// KIT WONG
// 5-19-2015
// used 120 min

#include<iostream>
#include<string>
using namespace std;

class LinkedList{
	private:
		struct Node{
			int data;
			Node* next;};
		Node* head;

	public:
		LinkedList(){head = NULL;}
		void appendNode(int n){
			Node* newNode = new Node;
			newNode->data = n; newNode->next = NULL;
			if(head){
				Node* current = head;
				while(current->next) current = current->next;
				current->next = newNode;
				cout << newNode->data << " is added!" << endl;
			}
			else{
				head = newNode;
				cout << newNode->data << " is added!" << endl;
			}
		}
		~LinkedList(){
			if(head)while(head)deleteNode(head->data);
			cout << "List is destroied!" << endl;
		}
		void insertNode(int n){
			Node* newNode = new Node;
			newNode->data = n; newNode->next = NULL;
			if(head){
				if(head->data > n){
					newNode->next = head;
					head = newNode;
					cout << newNode->data << " is inserted!" << endl;
					return;
				}
				Node* current = head;
				while(current->next && current->next->data < n)current = current->next;
				if(current->next){
					newNode->next = current->next;
					current->next = newNode;
					cout << newNode->data << " is inserted!" << endl;
				}
				else{
					current->next = newNode;
					cout << newNode->data << " is inserted!" << endl;
				}
			}
			else{
				head = newNode;
				cout << newNode->data << " is inserted!" << endl;
			}
		}
		void deleteNode(int n){
			if(head){
				Node* current = head;
				Node* before;
				if(head->data == n){
					head = head->next;
					cout << current->data << " is deleted!" << endl;
					delete current;
					return;
				}
				while(current && current-> data != n){
					before = current;
					current = current->next;
				}
				if(current){
					before->next = current->next;
					cout << current->data << " is deleted!" << endl;
					delete current;
				}
			}
		}
		void reversList(){
			Node* current = head;
			Node* last = head;
			Node* tempHead = head;
			while(last->next) last = last->next;
			head = last;
			while(tempHead != last){
				current = tempHead;
				while(current->next != last) current = current->next;
				last->next = current;
				last = current;
			}
			tempHead->next = NULL;
			cout << "Finished reversing!" << endl;
		}
		int searchNode(int n){
			int i = -1;
			if(head){
				Node* current = head;
				while(current->data != n && current->next){
					current = current->next;
					i++;
				}
				if(current->data == n) return i+1;
				else return -1;
			}
			return i;
		}
		void displayList(){
			Node* current = head;
			cout << "List: ";
			while(current){
				cout << current->data << " ";
				current = current->next;
			}
			cout << endl;
		}
};

int main(){
	LinkedList list;
	list.appendNode(5);list.appendNode(9);
	list.displayList();
	list.insertNode(2);list.insertNode(7);list.insertNode(15);
	list.displayList();
	cout << "5 at #" << list.searchNode(5) << endl;
	cout << "15 at #" << list.searchNode(15) << endl;
	cout << "0 at #" << list.searchNode(0) << endl;
	list.reversList();
	list.displayList();
	list.deleteNode(2);list.deleteNode(7);list.deleteNode(15);
	list.displayList();
	list.~LinkedList();
	list.displayList();
	return 0;
}
