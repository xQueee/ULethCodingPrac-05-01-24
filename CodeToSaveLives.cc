// This program takes in a number of test cases, and two numbers with a number of digits between 0 and 9, and outputs
// the sum of said digits.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

// Function Prototype
string addSpaces(string);

int main(){
    int t = 0;
    // Input the test cases
    cin >> t;
    cin.ignore();
    
    // Loop running t-times to run each test case.
    while(t--){
        string num1, num2 = "";
        // Input the two numbers
        getline(cin, num1);
        getline(cin, num2);
        
        // Removes the spaces in these numbers, moves them to the back, and then erases them, leaving the numbers
        // with no spaces.
        num1.erase(remove(num1.begin(), num1.end(), ' '), num1.end());
        num2.erase(remove(num2.begin(), num2.end(), ' '), num2.end());
        
        // Strings converted to integers using stoi and then added.
        int sum = stoi(num1) + stoi(num2);
        // Converted back to string using to_string.
        string sumString = to_string(sum);
        
        // Outputs the string with spaces added back to it.
        cout << addSpaces(sumString) << endl;
    }
    return 0;
}

// Function Defintiion
string addSpaces(string sumString){
    string sumStringSpaces = "";
    // For eacg charcter in sumString, add it to the result string, and then add a space afterwards.
    for(char c: sumString){
        sumStringSpaces += c;
        sumStringSpaces += ' ';
    }
    return sumStringSpaces;
}