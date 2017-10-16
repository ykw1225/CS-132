//for Product
#include"Product.h"
#include<iostream>
#include<iomanip>
#include<string>

int Product :: totalPro = 0;
Product::Product(){
    //totalPro++;
        name = "";
        price = 0;
}
Product::Product(string nam){
    totalPro++;
        name = nam;
        price = 0;
}
Product:: Product(double pri){
    totalPro++;
        name = "";
        price = pri;
}
Product::Product(string nam, double pri){
	totalPro++;
	//cout << "constructor" << endl;
	name = nam;
	price = pri;
	//cout << "finished construct" << endl;
}
Product::Product(const Product& p){
	//cout << "Copy constructor!!!" << endl;
	this->name = p.name;
	this->price = p.price;
}
Product::~Product(){}
Product Product::operator+(const Product p){
	// Combining two products into one product
	Product temp;
	temp.name.append(this->name);
	temp.name.append(" & ");
	temp.name.append(p.name);
	temp.price = this->price + p.price;
	return temp;
}
Product Product::operator-(const Product p){
        // combining two products into one product with discount
        //(buy one, get 50% off on the higher price one) or make first one if their price are same
        Product temp;
        temp.name.append(this->name);
        temp.name.append(" & ");
        temp.name.append(p.name);
        temp.name.append(" [PROMO]");
        if(*this < p || this->price == p.price){temp.price = this->price + p.price * 0.5;}
        else if(*this > p){temp.price = this->price * 0.5 + p.price;}
        return temp;
}
bool Product::operator<(const Product p){
	if(this->price < p.price) return true;
	return false;
}
bool Product::operator>(const Product p){
	if(this->price > p.price) return true;
	return false;
}
bool Product::operator==(const Product p){
	if(this->price == p.price) return true;
	return false;
}
void Product::setName(string nam){name = nam;}
void Product::setPrice(double pri){price=pri;}
string Product::getName(){return name;}
double Product::getPrice(){return price;}
int Product::getTotalPro(){return totalPro;}
void Product::setTotalPro(int n){totalPro = n;cout << "totalprosetter\n";}
ostream& operator<<(ostream os,Product& pro){
	os<<"Product: "<<pro.name<<"\n" 
	<<"Price $: "<<pro.price<<".\n";
	return os;
}
istream& operator>>(istream is,Product& pro){
	cout<<"Product Name: ";
	is>>pro.name;
	cout<<"Price of product: ";
	is>>pro.price;
	return is;
}
void Product::display(){cout << "Name: " << name << "\n" << "Price: " << fixed << setprecision(2) << price << endl;}