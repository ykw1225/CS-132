#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>
using namespace std;

class A{
	string a;
	public:
	A(string a=""){this->a = a;}
	virtual string get(){return a;}
};
class B{
	string b;
	public:
	B(string b=""){this->b = b;}
	string get(){return b;}
};
class AB:public A,public B{
	string ab;
	public:
	AB(string ab=""){this->ab = ab;}
	string get(){return ab;}
};

int main(){
	A a("a");
	B b("b");
	AB ab("ab");
	A* ap = &ab;
	B* bp = &ab;
	cout << ap->get() << endl;
	cout << bp->get() << endl;
	cout << ab.get() << endl;
	cout << ab.get() << endl;
	cout << a.get() << endl;
	cout << b.get() << endl;
    return 0;
}
