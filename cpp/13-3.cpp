// CS-132 HW 13-3 Car Class
// KIT WONG
// 4-18-2015
// used 5 min

#include<iostream>
#include<string>
using namespace std;

class Car{
    int yearModel;
    string make;
    int speed;
    public:
    Car(int y, string m){
        yearModel = y;
        make = m;
        speed = 0;
    }
    int getYearModel(){
        return yearModel;
    }
    string getMake(){
        return make;
    }
    int getSpeed(){
        return speed;
    }
    void accelerate(){
        speed += 5;
    }
    void brake(){
        speed -= 5;
    }
};

int main(){
    Car mycar(2015, "Scion");
    for(int i = 0; i < 5; i++){
        mycar.accelerate();
        cout << "Current speed: " << mycar.getSpeed() << endl;
    }
    for(int i = 0; i < 5; i++){
        mycar.brake();
        cout << "Current speed: " << mycar.getSpeed() << endl;
    }
    return 0;
}
