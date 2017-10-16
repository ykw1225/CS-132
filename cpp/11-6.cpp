// CS-132 HW 11-6 Soccer Scores
// KIT WONG
// 4-10-2015
// used 30 min

#include<iostream>
#include<string>
using namespace std;

struct Team{
    string name;
    int number;
    int point;
};

void inputCheck(int &n){
    cin >> n;
    while(n < 0){
        cout << "Invalid input, enter again(not negative): ";
        cin >> n;
    }
}

int totalPointsCal(Team *a){
    int total = a[0].point;
    for(int i = 1; i < 12; i++){
        total += a[i].point;
    }
    return total;
}

int findMostPoint(Team *a){
    int most = a[0].point;
    for(int i = 1; i < 12; i++){
        if(a[i].point > most) most = a[i].point;
    }
    return most;
}

int findMostPlayerIndex(Team *a){
    int most = findMostPoint(a);
    for(int i = 0; i < 12 ; i++){
        if(most == a[i].point) return i;
    }
    return -1;
}

int main(){
    Team a[12];
    for(int i = 0; i < 12; i++){
        cout << "\nPlayer " << i + 1 << endl;
        cout << "Enter player's name: ";
        cin >> a[i].name;
        cout << "Enter player's number: ";
        inputCheck(a[i].number);
        cout << "Enter player's points: ";
        inputCheck(a[i].point);
    }
    cout << "\nTotal points of team: " << totalPointsCal(a) << endl;
    cout << "Player " << a[findMostPlayerIndex(a)].number << " \"" << a[findMostPlayerIndex(a)].name
         << "\" earned " << findMostPoint(a) << " points which is the highest point." << endl;
    return 0;
}
