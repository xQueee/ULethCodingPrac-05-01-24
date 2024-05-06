// This program will help farmer Jon find the earliest day the party can take place.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function prototypes
int findMaxDay(vector<int>& t);

int main(){
    // Take in the number of seedlings.
    int n = 0;
    cin >> n;
    // Make a vector 't' of size  n, the number of seedlings. Stores the number of days it takes for
    // each seedling to grow.
    vector<int> t(n);
    for(int i = 0; i < n; i++){
        cin >> t[i];
    }
    // Outputs the earliest day the party can be held.
    cout << findMaxDay(t) << endl;
}

// Function Definitions
// Simply finds the Max Day it will take for a seedling to grow.
int findMaxDay(vector<int>& t){
    // Sort the vector in reverse.
    sort(t.rbegin(), t.rend());
    // Keeps track of the current day, as well as the max day when a tree reaches maturity.
    int day = 1, maxDay = 0;
    // Then, it iterates through the vector and for each growth time t_i, it calculates
    // the day when the tree will reach full maturity, and updates the maxDay. The day is 
    // then incremented by one.
    for(int t_i : t){
        maxDay = max(maxDay, day + t_i + 1);
        ++day;
    }
    return maxDay;
}