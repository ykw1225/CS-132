// CS-132 HW 16-7
// KIT WONG
// 5-11-2015
// used 10 min

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

const int SIZE = 10;

class TestScores{
	double* scores;
	public:
	class InvalidSco{};
	TestScores(double*& s){
		for(int i = 0; i < SIZE; i++){
			try{if(s[i] < 0 || s[i] > 100)throw InvalidSco();}
			catch(InvalidSco){cout << s[i] << " is an invalid scores!!!" << endl;}
		scores = *&s;}}
	double aveg(){
		double sum = 0;
		for(int i = 0; i < SIZE; i++)sum += scores[i];
		return sum/SIZE;}
};

int main(){
	double* p = new double[10];
	for(int i = 0; i < 10; i++){
		cout << "Enter a score for Student #" << i+1 << ": ";
		cin >> p[i];
	}
	TestScores t(p);
	cout << fixed << setprecision(2);
	cout << "The average score is " << t.aveg() << endl;
	return 0;
}
