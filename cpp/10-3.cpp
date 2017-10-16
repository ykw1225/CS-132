//10-3: Word Counter
//Yeung Kit Wong

#include<iostream>
#include<string>
using namespace std;

const int SIZE = 999;

int wordCounter(char* c){
    //check if the cstring is empty
    if(c[0] == '\0') return 0;
    int n = 1, i = 0;
    //when the element is not null or space counter +1
    while(c[i] != '\0'){
        if(c[i] == ' ') n++;
        i++;
    }
    return n;
}

int wordCounter(string s){
    if(s.size() < 1) return 0;
    int n = 1, i = 0;
    while(s[i] != '\0'){
        if(s[i] == ' ') n++;
        i++;
    }
    return n;
}

int main(){
    char array[SIZE];
    string s;
    cout << "Enter a C-string: ";
    cin.getline(array,SIZE);
    cout << wordCounter(array) << endl;
    cout << "Enter a string: ";
    getline(cin,s);
    cout << wordCounter(s) << endl;
    return 0;
}
