// CS-132 HW 11-8 Search Funtion for Customer Account Program
// KIT WONG
// 4-10-2015
// used 10 min

#include<iostream>
#include<string>
using namespace std;

struct Customer{
    string name;
    string address;
    string city;
    string state;
    int zip;
    int teleNum;
    double balance;
    string lastPay;
};

void inputClear(){
    cin.ignore();
}

void inputCheck(string &s){
    getline(cin,s);
    while(s == ""){
        cout << "Invalid input, enter again(not empty): ";
        getline(cin,s);
    }
}

void inputCheck(double &n){
    cin >> n;
    while(n < 0){
        cout << "Invalid input, enter again(not negative): ";
        cin >> n;
    }
    inputClear();
}

void inputCheck(int &n, int min, int max){
    cin >> n;
    while(n < min || n > max){
        cout << "Invalid input, enter again(" << min << "~" << max << "): ";
        cin >> n;
    }
    inputClear();
}

void addCus(Customer *a, int &i){
    cout << "\nCustomer " << i + 1 << endl;
    cout << "Enter name: ";
    inputCheck(a[i].name);
    cout << "Enter street address: ";
    inputCheck(a[i].address);
    cout << "Enter city: ";
    inputCheck(a[i].city);
    cout << "Enter state: ";
    inputCheck(a[i].state);
    cout << "Enter zip code: ";
    cin >> a[i].zip;
    cout << "Enter telephone number: ";
    cin >> a[i].teleNum;
    inputClear();
    cout << "Enter account balances: ";
    inputCheck(a[i].balance);
    cout << "Enter date of last payment(mm/dd/yyyy): ";
    inputCheck(a[i].lastPay);
    i++;
}

void display(Customer *a, int i){
    cout << "\n\t1. Name: " << a[i].name
         << "\n\t2. Address: " << a[i].address
         << "\n\t3. City: " << a[i].city
         << "\n\t4. State: " << a[i].state
         << "\n\t5. Zip: " << a[i].zip
         << "\n\t6. Telephone number: " << a[i].teleNum
         << "\n\t7. Account balances: " << a[i].balance
         << "\n\t8. Last payment date: " << a[i].lastPay
         << endl;
}

void displayAll(Customer *a, int i){
    for(int j = 0; j < i; j++){
        cout << "\nCustomer #" << j+1;
        display(a, j);
    }
}

void changeMenu(Customer *a, int i){
    int select = 0;
    int iCus;
    do{
        cout << "\nHere is the current data:" << endl;
        displayAll(a, i);
        cout << "\nEnter the # of customer need change: ";
        inputCheck(iCus,1,i);
        display(a, iCus-1);
        cout << "\nSelect a information to change(1~8) or enter 0 for exit: ";
        inputCheck(select, 0, 8);
        cout << "\nEnter a new ";
        switch(select){
            case 1: cout << "name: ";
                    inputCheck(a[iCus-1].name);
                    break;
            case 2: cout << "address: ";
                    inputCheck(a[iCus-1].address);
                    break;
            case 3: cout << "city: ";
                    inputCheck(a[iCus-1].city);
                    break;
            case 4: cout << "state: ";
                    inputCheck(a[iCus-1].state);
                    break;
            case 5: cout << "zip: ";
                    cin >> a[iCus-1].zip;
                    break;
            case 6: cout << "telephone number: ";
                    cin >> a[iCus-1].teleNum;
                    break;
            case 7: cout << "account balance: ";
                    inputCheck(a[iCus-1].balance);
                    break;
            case 8: cout << "last payment date(mm/dd/yyyy): ";
                    inputCheck(a[iCus-1].lastPay);
                    break;
            case 0: break;
            default:;
        }
    }while(select != 0);
}

void matchingName(Customer *a, string name, int i){
    int match[10], k = 0;
    bool isMatch = false;
    for(int j = 0; j < i; j++){
        if(a[j].name.find(name) != string::npos){
            match[k] = j;
            k++;
            isMatch = true;
        }
    }
    if(isMatch){
        cout << "\nHere is the customer match the name:" << endl;
        for(int j = 0; j < k; j++)
            display(a, match[j]);
    }
    else cout << "No customer mathc the name!" << endl;
}

void search(Customer *a, int i){
    string name;
    cout << "\nEnter a name need to search(case sensitive): ";
    getline(cin, name);
    matchingName(a, name, i);
}

void mainMenu(Customer *a, int &i){
    int select = 0;
    do{
        cout << "\nMain Menu\n"
             << "\t1. New Customer\n"
             << "\t2. Change data\n"
             << "\t3. Display all data\n"
             << "\t4. Seach customer\n"
             << "\t0. Exit\n"
             << "Enter selection(0~4): ";
        inputCheck(select, 0, 4);
        switch(select){
            case 1: if(i < 10) addCus(a, i);
                    else cout << "\nCustomer database is full now!" << endl;
                    break;
            case 2: if(i > 0) changeMenu(a, i);
                    else cout << "\nCustomer database is empty now!" << endl;
                    break;
            case 3: if(i > 0) displayAll(a, i);
                    else cout << "\nCustomer database is empty now!" << endl;
                    break;
            case 4: if(i > 0) search(a, i);
                    else cout << "\nCustomer database is empty now!" << endl;
                    break;
            case 0: break;
            default:;
        }
    }while(select != 0);
}

int main(){
    int cusNum = 0;
    Customer a[10];
    mainMenu(a, cusNum);
    return 0;
}
