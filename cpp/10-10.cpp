//10-10: replaceSubstring Function
//Yeung Kit Wong

#include<iostream>
#include<cstring>
#include<string>
using namespace std;

const int SIZE = 999;
string replaceSubstring(string s1, string s2, string s3){
    string newS;
    int i;
    //if the s2 is exist in the s1 and get the index, then replace the s2 in the s1 to the s3
    while((i = s1.find(s2)) != string::npos)
        newS = s1.replace(i, s2.length(), s3);
    return newS;
}

string replaceSubstring(char* c1, char* c2, char* c3){
    string s1(c1), s2(c2), s3(c3);
    string newS;
        int i;
        while((i = s1.find(s2)) != string::npos)
            newS = s1.replace(i, s2.length(), s3);
    return newS;
}

int main(){
    string s1, s2, s3;
    cout << "Enter a string: ";
    getline(cin,s1);
    cout << "Enter a key word for searching: ";
    getline(cin,s2);
    cout << "Enter a key word for changing: ";
    getline(cin,s3);
    cout << replaceSubstring(s1,s2,s3) << endl;
    char c1[SIZE], c2[SIZE], c3[SIZE];
    cout << "Enter a C-string: ";
    cin.getline(c1, SIZE);
    cout << "Enter a key word for searching: ";
    cin.getline(c2, SIZE);
    cout << "Enter a key word for changing: ";
    cin.getline(c3, SIZE);
    cout << replaceSubstring(c1, c2, c3) << endl;
    return 0;
}
