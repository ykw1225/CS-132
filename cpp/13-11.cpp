// CS-132 HW 13-11 Payroll
// KIT WONG
// 4-18-2015
// used 30 min

#include<iostream>
using namespace std;

class PayRoll{
    double hpr; // employee's hourly pay rate
    double h; // number of hours worked daily
    double tp; // total pay for the week
    public:
    PayRoll(double newH = 0){
        hpr = 15;
        h = newH;
        tpCal();
    }
    void setH(double newH){
        h = newH;
        tpCal();
    }
    void tpCal(){
        tp = hpr*h;
    }
    double getTp(){
        return tp;
    }
};

int main(){
    PayRoll a[7];
    double temp;
    for(int i = 0; i < 7; i++){
        cout << "Enter the number of hours of employee " << i+1 << " has worked: ";
        cin >> temp;
        while(temp > 60 || temp < 0){
            cout << "Invalid input, enter again: ";
            cin >> temp;
        }
        a[i].setH(temp);
        cout << "The gross pay: " << a[i].getTp() << endl;
    }
    return 0;
}


