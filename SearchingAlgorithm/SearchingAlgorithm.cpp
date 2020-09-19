/*
    Author : F323RED
    Name : Searching Algorithm
    Date : 2020/9/17
*/

#include <iostream>
using namespace std;

int dataList[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71 };

bool LinearSearch(int data[], int length, int target);
bool BinarySearch(int data[], int length, int target);
void ShowArray(int arrayIn[], int length);

int main()
{
    ShowArray(dataList, sizeof(dataList) / sizeof(int));

    while (true)
    {
        cout << "\n" << "Enter a number : ";    // User hint

        int num1 = 0;
        cin >> num1;
        
        if (!cin.good())    // check is the input value legal
        { 
            cout << "\nWARNING : < Illegal input value! >\n";
            return 1; 
        }

        if (BinarySearch(dataList, sizeof(dataList) / sizeof(int), num1))
            cout << "Number founded" << "\n";
        else 
            cout << "Number not founded" << "\n";
    }

    return 0;
}

void ShowArray(int arrayIn[], int length) 
{
    cout << "Array : { ";

    register int count = 0;
    while(true) 
    {
        cout << *(arrayIn + count++);

        if (count < length) { cout << ", "; }
        else break;
    }
    cout << " }";
}

bool LinearSearch(int data[], int length, int target) 
{
    for (int i = 0; i < length; i++) 
    {
        if (data[i] == target) { return true; }
    }

    return false;
}

bool BinarySearch(int data[], int length, int target)
{
    int ptr = 0, upperPtr = length - 1, lowerPtr = 0;

    while (lowerPtr <= upperPtr)
    {
        ptr = (lowerPtr + upperPtr) / 2;

        if (data[ptr] == target) { return true; }
        else if (data[ptr] > target) { upperPtr = ptr - 1; }
        else if (data[ptr] < target) { lowerPtr = ptr + 1; }
    } 

    return false;
}
