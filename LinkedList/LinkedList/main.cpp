#include<iostream>
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
				//cout << newNode->data << " is added!" << endl;
			}
			else{
				head = newNode;
				//cout << newNode->data << " is added!" << endl;
			}
		}
		~LinkedList(){
			if(head)while(head)deleteNode(head->data);
			//cout << "List is destroied!" << endl;
		}
		void insertNode(int n){
			Node* newNode = new Node;
			newNode->data = n; newNode->next = NULL;
			if(head){
				if(head->data > n){
					newNode->next = head;
					head = newNode;
					//cout << newNode->data << " is inserted!" << endl;
					return;
				}
				Node* current = head;
				while(current->next && current->next->data < n)current = current->next;
				if(current->next){
					newNode->next = current->next;
					current->next = newNode;
					//cout << newNode->data << " is inserted!" << endl;
				}
				else{
					current->next = newNode;
					//cout << newNode->data << " is inserted!" << endl;
				}
			}
			else{
				head = newNode;
				//cout << newNode->data << " is inserted!" << endl;
			}
			//cout << "end insert" << endl;
		}
		void deleteNode(int n){
			if(head){
				Node* current = head;
				Node* before;
				if(head->data == n){
					head = head->next;
					//cout << current->data << " is deleted!" << endl;
					delete current;
					return;
				}
				while(current && current-> data != n){
					before = current;
					current = current->next;
				}
				if(current){
					before->next = current->next;
					//cout << current->data << " is deleted!" << endl;
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
		void copyFrom(const LinkedList list){
			Node* current = list.head;
			while(current){
				this->appendNode(current->data);
				current = current->next;
			}
		}
};

int main(){
	LinkedList list;
	list.appendNode(1);list.appendNode(3);
	list.displayList();
	list.insertNode(0);list.insertNode(2);list.insertNode(4);
	list.displayList();
	list.reversList();
	list.displayList();
	list.deleteNode(0);list.deleteNode(2);list.deleteNode(4);
	list.displayList();
	list.~LinkedList();
	list.displayList();
	LinkedList list2;
	list2.insertNode(1);list2.insertNode(3);list2.insertNode(5);
	list2.displayList();
	list.copyFrom(list2);
	list.displayList();
	system("pause");
	return 0;
}
