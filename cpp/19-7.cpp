// CS-132 HW 19-7
// KIT WONG
// 6-6-2015
// used 3 min

#include<iostream>
using namespace std;

int sum(int n){
	if(n==0) return 0;
	return n + sum(n-1);
}

int main(){
	cout << sum(3) << endl;
	cout << sum(8) << endl;
	cout << sum(10) << endl;
	cout << sum(100) << endl;
	return 0;
}
