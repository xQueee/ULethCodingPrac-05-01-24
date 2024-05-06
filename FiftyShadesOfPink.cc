// This program will tell Thore the number of packages contain the words pink, rose, or both.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// Function Protoypes
string toLower(string word);
bool containsTarget(string word, string target);
bool containsSeveralTargets(string word, vector<string> targets);

int main(){
    int n = 0;
    int numberOfSessions = 0;
    // Words we need to find.
    vector<string> targets = {"pink", "rose"};
    cin >> n;
    cin.ignore();
    
    // Looping n times
    while(n--){
        string word = "";
        // Input the word.
        getline(cin, word);
        // Make it all lowercase to make it easier to work with.
        word = toLower(word);
        
        // Counts how many times "pink" or "rose" is found in each word.
        if(containsSeveralTargets(word, targets)){
            numberOfSessions++;
        }
    }
    
    // If greater than 0, outout the number of sessions Thore can attend. If not, he must watch some Star Wars.
    if(numberOfSessions > 0){
        cout << numberOfSessions << endl;
    } else {
        cout << "I must watch Star Wars with my Daughter" << endl;
    }
    return 0;
}

// Function Definitions
string toLower(string word){
    // Transforms the word to lowercase. Not sure why toLower needs ::, but it doesn't work without it.
    // Assuming it's something with namespaces.
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

// Helper function for the the one below, simply converts the words to lowercase, and finds the target.
// If the target is found, word.find(target) will not return npos, causing the comparison to return true.
bool containsTarget(string word, string target){
    word = toLower(word);
    return word.find(target) != string::npos;
}

// This function checks for both "pink" and "rose" to see if either are in the string.
bool containsSeveralTargets(string word, vector<string> targets){
    for(string target: targets){
        if(containsTarget(word, target)){
            return true;
        }
    }
    return false;
}
