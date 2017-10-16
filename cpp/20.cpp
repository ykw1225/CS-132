// CS-132 HW 20-1/3/5
// KIT WONG
// 6-7-2015
// used 120 min

#include<iostream>
using namespace std;

template <class T>
class BinaryTree{
private:
	struct Node{
		T data;
		Node* left;
		Node* right;
	};
	Node* root;
	void addNode(T t, Node*& n){
		if(n){
			if(n->data > t)addNode(t, n->left);
			else if(n->data < t)addNode(t, n->right);
		}else{
			Node* newNode = new Node;
			newNode->data = t;
			newNode->left = NULL;
			newNode->right = NULL;
			n = newNode;
		}
	}
	void displayPre(Node* n){
		if(n){
			cout << n->data << " ";
			displayPre(n->left);
			displayPre(n->right);
		}else return;
	}
	void displayIn(Node* n){
		if(n){
			displayIn(n->left);
			cout << n->data << " ";
			displayIn(n->right);
		}else return;
	}
	void displayPost(Node* n){
		if(n){
			displayPost(n->left);
			displayPost(n->right);
			cout << n->data << " ";
		}else return;
	}
	Node* leftEnd(Node* n){
		if(n->left) return leftEnd(n->left);
		else return n;
	}
	Node* rightEnd(Node* n){
		if(n->right) return rightEnd(n->right);
		else return n;
	}
	void deleteNode(T t, Node*& n){
		if(isContain(t, n)){
			if(n->data == t && !isLeaf(n)){
				Node* temp = n;
				Node* end;
				if(n->right && n->left){
					n = n->right;
					end = leftEnd(n);
					end->left = temp->left;
				}
				else if(n->left)n = n->left;
				else if(n->right)n = n->right;
				delete temp;
			}
			else if(n->data == t && isLeaf(n)){
				Node*temp = n;
				n = NULL;
				delete temp;
			}
			else{
				deleteNode(t, n->left);
				deleteNode(t, n->right);
			}
		}else return;
	}
	bool isContain(T t, Node* n){
		if(n){
			if(n->data == t) return true;
			if(isContain(t, n->left)) return true;
			if(isContain(t, n->right)) return true;
		}else return false;
		return false;
	}
	int leafCount(Node* n){
		if(n){
			if(isLeaf(n)) return 1;
			else return leafCount(n->left) + leafCount(n->right);
		}else return 0;
	}
	int treeWidth(Node* n, int level, int currentLv){
		if(n){
			if(currentLv == level-1){
				if(isLeaf(n))return 0;
				else if(n->left && n->right)return 2;
				else return 1;
			}
			else return treeWidth(n->left, level, currentLv+1) + treeWidth(n->right, level, currentLv+1);
		}
		else return 0;
	}
	void copyTree(Node*& m, Node* n){
		if(n){
			cout << "Noede " << n->data << " is added!" << endl;
			m->data = n->data;
			m->left = n->left;
			m->right = n->right;
			copyTree(m->left,n->left);
			copyTree(m->right,n->right);
		}
		else return;
	}
	void copyTree(BinaryTree& other){
		if(other.root){
			this->root = new Node;
			copyTree(this->root, other.root);
		}
		else this->root = NULL;
	}


public:
	BinaryTree(){root = NULL;}
	BinaryTree(BinaryTree& other){
			copyTree(other);
	}
	bool isLeaf(Node* n){
		if(n->left || n->right)return false;
		return true;
	}
	void addNode(T t){addNode(t, root);}
	void displayPre(){
		if(root){
			cout << "Pre-order: ";
			displayPre(root);
			cout << endl;
		}else return;
	}
	void displayIn(){
		if(root){
			cout << "In-order: ";
			displayIn(root);
			cout << endl;
		}else return;
	}
	void displayPost(){
		if(root){
			cout << "Post-order: ";
			displayPost(root);
			cout << endl;
		}else return;
	}
	void deleteNode(T t){
		if(root && isContain(t))deleteNode(t, root);
		else return;
	}
	bool isContain(T t){
		if(root)return isContain(t, root);
		else return false;
	}
	int leafCount(){
		if(root)return leafCount(root);
		else return 0;
	}
	int treeWidth(int level){
		if(root && level>0){
			if(level == 1)return 1;
			else return treeWidth(root, level, 1);
		}else return 0;
	}
};

int main(){
	BinaryTree<int> tree;
	tree.addNode(50);
	tree.addNode(20);
	tree.addNode(80);
	tree.addNode(10);
	tree.addNode(30);
	tree.addNode(60);
	tree.addNode(90);
	tree.addNode(15);
	tree.addNode(25);
	tree.addNode(70);
	tree.addNode(85);

	cout << "Contains? (1 for yes, 0 for no) :" << endl;
	cout << "15: " << tree.isContain(15) << "   ";
	cout << "25: " << tree.isContain(25) << "   ";
	cout << "70: " << tree.isContain(70) << "   ";
	cout << "85: " << tree.isContain(85) << "   ";
	cout << "0: " << tree.isContain(0) << endl;
	cout << endl;

	cout << "Leaf: " << tree.leafCount() << endl;
	cout << endl;

	cout << "Width of level 1: " << tree.treeWidth(1) << endl;
	cout << "Width of level 2: " << tree.treeWidth(2) << endl;
	cout << "Width of level 3: " << tree.treeWidth(3) << endl;
	cout << "Width of level 4: " << tree.treeWidth(4) << endl;
	cout << "Width of level 5: " << tree.treeWidth(5) << endl;
	cout << endl;

	tree.displayPre();
	tree.displayIn();
	tree.displayPost();
	cout << endl;

	tree.deleteNode(50);

	cout << "Leaf: " << tree.leafCount() << endl;
	cout << endl;

	cout << "Width of level 1: " << tree.treeWidth(1) << endl;
	cout << "Width of level 2: " << tree.treeWidth(2) << endl;
	cout << "Width of level 3: " << tree.treeWidth(3) << endl;
	cout << "Width of level 4: " << tree.treeWidth(4) << endl;
	cout << "Width of level 5: " << tree.treeWidth(5) << endl;
	cout << endl;

	tree.displayPre();
	tree.displayIn();
	tree.displayPost();
	cout << endl;

	tree.deleteNode(20);

	cout << "Leaf: " << tree.leafCount() << endl;
	cout << endl;

	cout << "Width of level 1: " << tree.treeWidth(1) << endl;
	cout << "Width of level 2: " << tree.treeWidth(2) << endl;
	cout << "Width of level 3: " << tree.treeWidth(3) << endl;
	cout << "Width of level 4: " << tree.treeWidth(4) << endl;
	cout << "Width of level 5: " << tree.treeWidth(5) << endl;
	cout << "Width of level 6: " << tree.treeWidth(6) << endl;
	cout << endl;

	tree.displayPre();
	tree.displayIn();
	tree.displayPost();
	cout << endl;

	tree.deleteNode(15);

	cout << "Leaf: " << tree.leafCount() << endl;
	cout << endl;

	cout << "Width of level 1: " << tree.treeWidth(1) << endl;
	cout << "Width of level 2: " << tree.treeWidth(2) << endl;
	cout << "Width of level 3: " << tree.treeWidth(3) << endl;
	cout << "Width of level 4: " << tree.treeWidth(4) << endl;
	cout << "Width of level 5: " << tree.treeWidth(5) << endl;
	cout << endl;

	tree.displayPre();
	tree.displayIn();
	tree.displayPost();
	cout << endl;
	cout << endl;
	cout << endl;

	BinaryTree<int> bt = tree;
	bt.displayPre();
	bt.displayIn();
	bt.displayPost();
	cout << endl;
	BinaryTree<int> bt1 = bt;
	bt1.displayPre();
	bt1.displayIn();
	bt1.displayPost();
	cout << endl;
	tree.displayPre();
	tree.displayIn();
	tree.displayPost();



	return 0;
}
