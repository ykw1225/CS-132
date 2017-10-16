// CS-132 HW 11-2 Movie Profit
// KIT WONG
// 4-10-2015
// used 5 min

#include<iostream>
#include<string>
using namespace std;

struct MovieData{
    string Title;
    string Director;
    int Year;
    int RunTime;
    double costs;
    double revenues;
};

void display(MovieData m){
    cout << "\nTitle: " << m.Title
         << "\nDirector: " << m.Director
         << "\nYear Released: " << m.Year
         << "\nRunning Time: " << m.RunTime << " minutes"
         << endl;
    if(m.costs < m.revenues){
        cout << "Profits of movie: " << m.revenues-m.costs << " million dollars\n" << endl;
    }
    else if(m.costs > m.revenues){
        cout << "Loss of movie: " << m.costs-m.revenues << " million dollars\n" << endl;
    }
    else{
        cout << "The gross and budget are same!\n" << endl;
    }
}

int main(){
    MovieData movie1 = {"Into the Woods","Rob Marshall",2014,125,50,204.3};
    MovieData movie2 = {"Big Hero 6","Don Hall & Chris Williams",2014,102,165,651.9};
    display(movie1);
    display(movie2);
    return 0;
}
