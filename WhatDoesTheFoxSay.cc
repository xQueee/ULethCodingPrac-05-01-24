// This program will finally understand what the fox says.

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

// Function Definitons
void mapSounds(map<string, string>& sounds, string animal, string sound);
vector<string> removeKnownSounds(map<string, string>& sounds, vector<string> sequence);

int main(){
    // Inputs the test cases.
    int t = 0;
    cin >> t;
    cin.ignore();
    
    // For each test case,  it reads a sequence of sounds into a vector.
    for(int i = 0; i < t; ++i){
        string sequence = "";
        getline(cin, sequence);
        // This creates a stringstream object, 'ss', from the string 'sequence'. This allows for easy seperation
        // of the sequence of sounds to take out one word at a time.
        stringstream ss(sequence);
        vector<string> sounds;
        string sound = "";
        // For every sound in sequence, each on will be put into the sounds vector.
        while(ss >> sound){
            sounds.push_back(sound);
        }
        // Map to label different sounds to different animals.
        map<string, string> animalSounds;
        
        string line = "";
        // This reads the lines of what animal says what and maps them.
        while(getline(cin, line) && line != "what does the fox say?"){
            stringstream ss(line);
            string animal, goes, sound = "";
            ss >> animal >> goes >> sound;
            mapSounds(animalSounds, animal, sound);
        }
        // This is the remaining vector of sounds, after the known animal sounds have been removed.
        vector<string> remainingSounds = removeKnownSounds(animalSounds, sounds);
        
        // Outputs the sounds to reveal what the fox says.
        for(const auto& sound: remainingSounds){
            cout << sound << " ";
        }
        cout << endl;
    }
    return 0;
}

// Function Definitions
// Simply finds each sound an animal makes and maps it.
void mapSounds(map<string, string>& sounds, string animal, string sound){
    sounds[sound] = animal;
}
// Removes the sounds that have been labeled to be from know animals from the sequence, leaving the unknown sounds.
vector<string> removeKnownSounds(map<string, string>& sounds, vector<string> sequence){
    vector<string> remainingSounds;
    for(const auto& sound: sequence){
        if(sounds.find(sound) == sounds.end()){
            remainingSounds.push_back(sound);
        }
    }
    return remainingSounds;
}