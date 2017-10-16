// CS-132 HW 11-4 Weather Statistics
// KIT WONG
// 4-10-2015
// used 40 min

#include<iostream>
using namespace std;

struct WeatherData{
    double TotalRainfall;
    double HighTemperature;
    double LowTemperature;
    double AverageTemperature;
};

void inputCheck(double &n, double min, double max){
    cin >> n;
    if(max > 0){
        while(n < min || n > max){
            cout << "Invalid input! Please enter again("
                 << min << "~" << max << "): ";
            cin >> n;
        }
    }
    else{
        while(n < min){
            cout << "Invalid input! Please enter again(bigger than"
                 << min << "): ";
            cin >> n;
        }
    }
}

double totalYearRainfallCal(WeatherData *a){
    double n = 0;
    for(int i = 0; i < 12; i++){
        n += a[i].TotalRainfall;
    }
    return n;
}

double averageMonRainfallCal(WeatherData *a){
    return totalYearRainfallCal(a) / 12;
}

double findHighTemperature(WeatherData *a){
    double t = a[0].HighTemperature;
    for(int i = 1; i < 12; i++){
        if(a[i].HighTemperature > t) t = a[i].HighTemperature;
    }
    return t;
}

int findMonthOfHighTemperature(WeatherData *a){
    double HighTemperature = findHighTemperature(a);
    for(int i = 0; i < 13; i++){
        if(a[i].HighTemperature == HighTemperature) return i+1;
    }
    return -1;
}

double findLowTemperature(WeatherData *a){
    double t = a[0].LowTemperature;
    for(int i = 1; i < 12; i++){
        if(a[i].LowTemperature < t) t = a[i].LowTemperature;
    }
    return t;
}

int findMonthOfLowTemperature(WeatherData *a){
    double LowTemperature = findLowTemperature(a);
    for(int i = 0; i < 12; i++){
        if(a[i].LowTemperature == LowTemperature) return i+1;
    }
    return -1;
}

double averageOfAverageTemperature(WeatherData *a){
    double totalAverageTemperature = a[0].AverageTemperature;
    for(int i = 1; i < 12; i++){
        totalAverageTemperature += a[i].AverageTemperature;
    }
    return totalAverageTemperature/12;
}

int main(){
    WeatherData a[12];
    for(int i = 0; i < 12; i++){
        cout << "\nMonth " << i + 1 << endl;
        cout << "Enter total rainfall: ";
        inputCheck(a[i].TotalRainfall, 0, 0);
        cout << "Enter high temperature(Fahrenheit): ";
        inputCheck(a[i].HighTemperature, -100, 140);
        cout << "Enter low temperature(Fahrenheit): ";
        inputCheck(a[i].LowTemperature, -100, 140);
        a[i].AverageTemperature = (a[i].HighTemperature + a[i].LowTemperature) / 2;
    }
    cout << "\nAverage monthly rainfall: " << averageMonRainfallCal(a) << endl;
    cout << "Total rainfall for the year: " << totalYearRainfallCal(a) << endl;
    cout << "The highest temperature: " << findHighTemperature(a)
         << " degree which is occurred in month " << findMonthOfHighTemperature(a) << endl;
    cout << "The lowest temperature: " << findLowTemperature(a)
         << " degree which is occurred in month " << findMonthOfLowTemperature(a) << endl;
    cout << "The average of all the monthly average temperatures: "
         << averageOfAverageTemperature(a) << endl;
    return 0;
}
