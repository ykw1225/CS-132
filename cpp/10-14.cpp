//10-14 Word Separator
//Yeung Kit Wong

#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main(){
    string s;
    cout << "Enter a string without space and\nuppercase every first letter of the word: ";
    getline(cin, s);
    //start at index 1 because the first character is upper case
    for(int i = 1; s[i] != '\0'; i++){
        //save the character into a temp variable
        char c = s[i];
        //check if the character is upper case
        if(isupper(c)){
            //if true, then lower the case and insert a space before it
            s[i] = tolower(c);
            s.insert(i, " ");
        }
    }
    cout << s << endl;
    return 0;
}
