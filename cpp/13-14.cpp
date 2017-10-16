// CS-132 HW 13-14
// KIT WONG
// 4-18-2015
// used 30 min

#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include"Product.h"
using namespace std;

int main(){
	Product* p = new Product[1];
	p[0]=4;
	for(int i=0; i<3; i++)
	cout << p[i];
	cout << endl;
	int* temp = new int[3];
	temp[0]=p[0];
	temp[1]=9;
	for(int i=0; i<3; i++)
	cout << temp[i];
	cout << endl;
	delete []p;
	p = new int[3];
	p[0]=temp[0];
	p[1]=temp[1];
	p[2]=4;
	for(int i=0; i<3; i++)
	cout << p[i];
	cout << endl;
	system("pause");
    return 0;
}
