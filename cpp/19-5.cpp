// CS-132 HW 19-5
// KIT WONG
// 6-6-2015
// used 3 min

#include<iostream>
using namespace std;

int multiple(int x, int y){
	if(y==0) return 0;
	return x + multiple(x, y-1);
}

int main(){
	cout << multiple(3, 5) << endl;
	cout << multiple(4, 4) << endl;
	cout << multiple(7, 8) << endl;
	return 0;
}
