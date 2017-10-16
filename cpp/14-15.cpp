// CS-132 HW 14-15
// KIT WONG
// 4-27-2015
// used 40 min

#include<iostream>
#include<string>
using namespace std;

class FuelGauge{
	double fuel;
public:
	FuelGauge(double=0);
	FuelGauge operator++();
	FuelGauge operator++(int);
	FuelGauge operator--();
	FuelGauge operator--(int);
	bool isFull();
	bool isEmpty();
	double* getFuel();
	void showFuel();
};
FuelGauge::FuelGauge(double n){
	while(n > 15 || n < 0){
		cout << "Invalid value, enter again(0-15): ";
		cin >> n;
	}
	fuel = n;
}
FuelGauge FuelGauge::operator++(){
	if(!isFull()) this->fuel++;
	return *this;
}
FuelGauge FuelGauge::operator++(int){
	FuelGauge temp = *this;
	++*this;
	return temp;
}
FuelGauge FuelGauge::operator--(){
	if(!isEmpty()) this->fuel--;
	return *this;
}
FuelGauge FuelGauge::operator--(int){
	FuelGauge temp = *this;
	--*this;
	return temp;
}
bool FuelGauge::isFull(){
	if(fuel >= 15) return true;
	return false;
}
bool FuelGauge::isEmpty(){
	if(fuel <= 0) return true;
	return false;
}
double* FuelGauge::getFuel(){
	return &fuel;
}
void FuelGauge::showFuel(){
	cout << "Current amount of fuel is " << fuel << " gallons." << endl;
}

class Odometer{
	int milage;
	FuelGauge fuel;
public:
	Odometer(double=0, FuelGauge=(15));
	Odometer operator++();
	Odometer operator++(int);
	bool isMax();
	double getMilage();
	FuelGauge* getFuelCar();
	void showMilage();
};
Odometer::Odometer(double n, FuelGauge f){
	fuel = f;
	while(n > 999999){
		cout << "Invalid value, enter again(0-999999): ";
		cin >> n;
	}
	milage = n;
}
Odometer Odometer::operator++(){
	if(!isMax()){
		this->milage++;
	}
	else{
		this->milage = 0;
	}
	return *this;
}
Odometer Odometer::operator++(int){
	Odometer temp = *this;
	++*this;
	return temp;
}
bool Odometer::isMax(){
	if(milage > 999999) return true;
	return false;
}
double Odometer::getMilage(){
	return milage;
}
FuelGauge* Odometer::getFuelCar(){
	return &fuel;
}
void Odometer::showMilage(){
	cout << "Current milage: " << milage << endl;
}

int main(){
	int mileCount = 0;
	FuelGauge fuel(15);
	Odometer mile = Odometer(0, fuel);
	while(!mile.getFuelCar()->isEmpty()){
		mile++;
		mileCount++;
		mile.showMilage();
		mile.getFuelCar()->showFuel();
		if(mileCount == 24){
			(*mile.getFuelCar())--;
			mileCount = 0;
		}
	}
	cout << "Fuel is out!" << endl;
	return 0;
}
