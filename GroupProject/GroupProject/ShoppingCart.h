// Class for a single shopping cart
#ifndef ShoppingCart_H
#define ShoppingCart_H
#include "Product.h"
class ShoppingCart{
private:
    Product* products;
    double totalPrice;
    bool membership;
    double discount;
	int proNum;
public:
    ShoppingCart(){
		proNum = 0;
        totalPrice = 0;
        membership =false; 
		discount = 0;
	}
	ShoppingCart(Product* p){
		products = p;
		totalPrice = 0;
	}
    Product* getPro(){return products;}
    double getTotalP(){return totalPrice;}
	double getDiscount(){return discount;}
    double isDiscount(){
        if(discount > 0) return true;
        return false;
	}
};
#endif