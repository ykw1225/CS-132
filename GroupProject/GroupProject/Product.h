// for Product 
#ifndef Product_H
#define Product_H
#include<string>
#include<iostream>
using namespace std;
class Product{
private :
        string name;
        double price;
        static int totalPro;
public:
        Product();
        Product(string);
        Product(double);
        Product(string,double);
        Product(const Product&);
        ~Product();
        Product operator+(const Product);
        Product operator-(const Product);
        bool operator<(const Product);
        bool operator>(const Product);
        bool operator==(const Product);
        friend ostream &operator<<(ostream,Product&); 
        friend istream &operator>>(istream,Product&);
        void setName(string);
        void setPrice(double);
        string getName();
        double getPrice();
        int getTotalPro();
		void setTotalPro(int);
        void display();
};

#endif