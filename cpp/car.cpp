#include<string>
#include<iostream>
using namespace std;
void test(int, int = 2, int = 2);
void test(int &, int *, int);
void test(int *, int [], int);
const int SIZE = 4;
int main(){
    int one = 1, two = 2, three = 3;
    int array[SIZE] = {1,2};
    test(one, three);
    cout << one << ", " << two << ", " << three << ", " << endl;
    test(&two, array, SIZE);
    for(int i=0; i<SIZE; i++)
        cout << array[i] << ", ";
    cout<<endl;
    test(array[1], &array[2], array[3]);
    for(int i=0; i<SIZE; i++)
        cout << array[i] << ", ";
    cout<<endl;
    //system("pause");
    return 0;
}
void test(int first, int second, int third){
    first +=1;
    second +=2;
    third +=3;
    cout << first << ", " << second << ", " << third << ", " << endl;
}
void test(int* p, int num[], int SIZE){
    *p = SIZE;
    for(int i=0; i<SIZE; i++){
        cout<<*(num+i)<< ", ";
        *(num + i) += *p;
        cout<<*(num+i)<< ", ";
    }
    cout<<endl;
}
void test(int &first, int *second, int third){
    first +=1;
    *second +=2;
    third +=3;
}
