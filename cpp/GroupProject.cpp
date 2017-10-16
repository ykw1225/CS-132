//Group member: eric chan, Kit Wong, koon yin
// Online Stroe Shopping System Version 1.0


/*LOG:
KIT: Just finished some simple menu and struct (4/5/17:42)
KIT: Finished add function
*/

#include<iostream>
#include<string>
using namespace std;



const int SIZE = 999;

// Structure for a single product
struct Product{
    string name;
    double price;
    string productionDate;
    string expirationDate;
};

// Structure for a single shopping cart
struct ShoppingCart{
    Product products[SIZE];
    double totalPrice;
    double discount;
    bool isDiscount;
};

// Check if user input is valid
void inputCheck(double &select, double min){
    cin >> select;
    while(select < min){
        cout << "Invalid input, enter again: ";
        cin >> select;
    }
    cin.clear();
    cin.ignore(99999999999, '\n');
}

void inputCheck(int &select, int min, int max){
    cin >> select;
    while(select < min || select > max){
        cout << "Invalid input, enter again: ";
        cin >> select;
    }
    cin.clear();
    cin.ignore(99999999999, '\n');
}

// Removing a product from database
void remove(){
}

// Viewing current products from database
void viewP(){
}

// Viewing products in the shopping cart
void viewC(){
}

// Finished shopping and display the price calculation
// Also asking the billing and shipping information from user
void check(){
}

// Adding a product into the database
void add(Product* p, int &proNum){
    string name;
    double price;
    string productionDate;
    string expirationDate;
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter price: ";
    inputCheck(price, 0);
    cout << "Enter production date(mm/dd/yyyy): ";
    getline(cin, productionDate);
    cout << "Enter expiration date(mm/dd/yyyy): ";
    getline(cin, expirationDate);
    Product newPro = {name,price,productionDate,expirationDate};
    p[proNum] = newPro;
    proNum++;
}

// Menu for manage database
void employee(Product* p, int &proNum){
    int select = 0;
    do{
            cout << "***********************************\n"
            << "Welcome Employee!\n"
            << "Management Menu:\n"
            << "\t1. Add Product\n"
            << "\t2. Remove Product\n"
            << "\t0. Back\n"
            << "Enter your selection(0~2): ";
            inputCheck(select, 0, 2);
            switch(select){
                case 1: add(p, proNum);
                        break;
                case 2: remove();
                        break;
                case 0: break;
            }
    }while(select != 0);
}

// Menu for shopping
void customer(){
    int select = 0;
    do{
        cout << "***********************************\n"
            << "Welcom dear value customer!\n"
            << "Customer Menu:\n"
            << "\t1. View products\n"
            << "\t2. View shopping cart\n"
            << "\t3. Check out\n"
            << "\t0. Back\n"
            << "Enter your selection(0~3): ";
            inputCheck(select, 0, 3);
            switch(select){
                case 1: viewP();
                        break;
                case 2: viewC();
                        break;
                case 3: check();
                        break;
                case 0: break;
                default:;
            }
    }while(select != 0);
}

// Home page menu
void mainMenu(Product* p, int &proNum){
    int select = 0;
    do{
        cout << "***********************************\n"
            << "Welcome to EKK Online Store!\n"
            << "Main Menu:\n"
            << "\t1. Employee\n"
            << "\t2. Customer\n"
            << "\t0. Exit\n"
            << "Enter your selection(0~2): ";
            inputCheck(select, 0, 2);
            switch(select){
                case 1: employee(p, proNum);
                        break;
                case 2: customer();
                        break;
                case 0: break;
            }
    }while(select != 0);
}

int main(){
    const int SIZE = 10;
    int proNum = 0;
    Product p[SIZE];
    mainMenu(p,proNum);
    return 0;
}




