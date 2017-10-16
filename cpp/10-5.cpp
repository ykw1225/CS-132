//10-5: Sentence Capitalizer
//Yeung Kit Wong

#include<iostream>
#include<string>
using namespace std;

void stcCap(char* array){
    int i = 0;
    //if the element is the first letter, and after '.', '!', or '?', then upper the case.
    while(*(array+i) != '\0'){
        if(i == 0 || *(array+i-2) == '.' || *(array+i-2) == '!' || *(array+i-2) == '?')
            *(array+i) = char(*(array+i)-32);
        i++;
    }
}

void stcCap(string &s){
    int i = 0;
    while(s[i] != '\0'){
    if(i == 0 || s[i-2] == '.' || s[i-2] == '!' || s[i-2] == '?')
        s[i] = char(s[i]-32);
    i++;
    }
}

int main(){
    char array[999];
    string s;
    cout << "Enter a C-string: ";
    cin.getline(array,999);
    stcCap(array);
    cout << array;
    cout << endl;
    cout << "Enter a string: ";
    getline(cin, s);
    stcCap(s);
    cout << s << endl;
    return 0;
}
