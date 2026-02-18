#include <bits/stdc++.h>
using namespace std;
int main()
{
    int var = 8;
    int *ptr = &var;
    int **ptr1 = &ptr;
    cout << "The value is " << var << endl;
    cout << "The address of this variable in the memory is " << ptr << endl;
    var = 10;
    cout << "The address of the variable after changing the value is " << ptr << endl;
    cout << "So the memory address does not changes with the change in its value" << endl;
    cout << "This is a double pointer" << ptr1 << endl;
}