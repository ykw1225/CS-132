// CS-132 HW 13-1 Date
// KIT WONG
// 4-17-2015
// used 10 min

#include<iostream>
#include<string>
using namespace std;

void inputCheck(int &n, string s, int min, int max){
    while(n<min || n>max){
        cout << "Invalid value, enter a new value for " << s << " from " << min << " to " << max << ": ";
        cin >> n;
    }
}
class Date{
    int month;
    int day;
    int year;
public:
    Date(int m=0, int d=0, int y=0){
        month = m;
        inputCheck(month, "month", 1, 12);
        day = d;
        inputCheck(day, "day", 1, 31);
        year = y;}
    void toStringSlash(){
        cout << month << "/"
             << day << "/"
             << year << endl;}
    void toStringMDY(){
        switch(month){
            case 1: cout << "January ";break;
            case 2: cout << "Febuary ";break;
            case 3: cout << "March ";break;
            case 4: cout << "Aprile ";break;
            case 5: cout << "May ";break;
            case 6: cout << "June ";break;
            case 7: cout << "July ";break;
            case 8: cout << "August ";break;
            case 9: cout << "September ";break;
            case 10: cout << "October ";break;
            case 11: cout << "November ";break;
            case 12: cout << "December ";break;
            default: cout << "Error ";break;}
        cout << day << ", "
             << year << endl;}
    void toStringDMY(){
        cout << day;
        switch(month){
            case 1: cout << " January ";break;
            case 2: cout << " Febuary ";break;
            case 3: cout << " March ";break;
            case 4: cout << " Aprile ";break;
            case 5: cout << " May ";break;
            case 6: cout << " June ";break;
            case 7: cout << " July ";break;
            case 8: cout << " August ";break;
            case 9: cout << " September ";break;
            case 10: cout << " October ";break;
            case 11: cout << " November ";break;
            case 12: cout << " December ";break;
            default: cout << " Error ";break;}
        cout <<year << endl;}
};
int main(){
    int m,d,y;
    cout << "Enter month: ";
    cin >> m;
    inputCheck(m,"month",1,12);
    cout << "Enter day: ";
    cin >> d;
    inputCheck(d,"day",1,31);
    cout << "Enter year: ";
    cin >> y;
    Date date(m,d,y);
    date.toStringSlash();
    date.toStringMDY();
    date.toStringDMY();
    return 0;
}
