// CS-132 HW 14-10
// KIT WONG
// 4-27-2015
// used 30 min

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class DivSales{
	double sales[4];
	static double totalSales;
public:
	DivSales(double=0,double=0,double=0,double=0);
	double getTotal();
	void showSale(int);
};
double DivSales:: totalSales = 0;
DivSales:: DivSales(double a, double b, double c, double d){
	sales[0] = a;
	sales[1] = b;
	sales[2] = c;
	sales[3] = d;
	totalSales += a + b + c + d;
}
double DivSales::getTotal(){
	return totalSales;
}
void DivSales::showSale(int i){
	cout << fixed << setprecision(2);
	cout << "sales: $" << sales[i] << endl;
}

void inputCheck(double &n, double min){
	cin >> n;
	while(n < min){
		cout << "Invalid input, enter again: ";
		cin >> n;
	}
}

int main(){
	double temp[4];
	DivSales divisions[6];
	for(int i = 0; i < 6; i++){
		cout << "Division:" << i+1 << endl;
		for(int j = 0; j < 4; j++){
			cout << "    Enter quarter " << j+1 << " sales: ";
			inputCheck(temp[j],0);
		}
		divisions[i] = DivSales(temp[0],temp[1],temp[2],temp[3]);
		cout << endl;
	}
	for(int i = 0; i < 6; i++){
		cout << "Division:" << i+1 << endl;
		for(int j = 0; j < 4; j++){
			cout << "    Quarter " << j+1 << " ";
			divisions[i].showSale(j);
		}
	}
	cout << "Total year sales of corporate: " << divisions[0].getTotal() << endl;
	return 0;
}
