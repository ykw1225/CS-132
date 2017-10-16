#include<iostream>
using namespace std;

class StaticQueue{
	int* array;
	int size;
	int front;
	int rear;
	int nums;
	public:
	StaticQueue(int s){
		array = new int[s];
		size = s;
		front = -1;
		rear = -1;
		nums = 0;
	}
	void enqueue(int n){
		if(nums == size)
			cout <<"FULL!" <<endl;
		else{
			cout << "front: " << front << "   rear: " << rear << "   nums: " << nums << endl;
			rear=(rear+1)%size;
			array[rear]=n;
			nums++;
			cout << "front: " << front << "   rear: " << rear << "   nums: " << nums << endl;
		}
	}
	void dequeue(int& n){
		if(nums == 0)
			cout <<"EMpty!" <<endl;
		else{
			cout << "front: " << front << "   rear: " << rear << "   nums: " << nums << endl;
			front=(front+1)%size;
			n=array[front];
			nums--;
			cout << "front: " << front << "   rear: " << rear << "   nums: " << nums << endl;
		}
	}
	int dequeue(){
			if(nums == 0){cout <<"EMpty!" <<endl;return -1;}
			else{
				cout << "front: " << front << "   rear: " << rear << "   nums: " << nums << endl;
				int n;
				front=(front+1)%size;
				n=array[front];
				nums--;
				cout << "front: " << front << "   rear: " << rear << "   nums: " << nums << endl;
				return n;
			}
	}
	void display(){
		if(nums!=0){
			for(int i=0; i<nums; i++)cout << array[i] << " ";
		}cout << endl;
	}

};

int main(){
	StaticQueue q(5);
	q.enqueue(1);q.enqueue(2);q.enqueue(3);q.enqueue(4);q.enqueue(5);q.enqueue(6);
	q.display();
	q.dequeue();q.dequeue();q.dequeue();q.dequeue();q.dequeue();q.dequeue();
	q.display();
	return 0;
}
