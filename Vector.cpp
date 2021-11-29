#include "std_lib_facilities.h"

vector<int> charsPerString(vector<string> strVector) {
    int letterCount;
    vector<int> letterVector;

    for (int i = 0; i < strVector.size(); i++) {
        letterCount = 0;
        for (int j = 0; j < strVector[i].length(); j++) {
            letterCount++;
        }
        letterVector.push_back(letterCount);
    }

    return letterVector;
}

void longestString(vector<string> strVector, vector<int> letterVector) {
    int largestNum = letterVector[0], largestPosition = 0;

    for (int i = 1; i < letterVector.size(); i++) {
        if (letterVector[i] > largestNum) {
            largestNum = letterVector[i];
            largestPosition = i;
        }
    }

    cout << "\nThe longest string is " << strVector[largestPosition] << " with " << largestNum << " letters";
}

void shortestString(vector<string> strVector, vector<int> letterVector) {
    int smallestNum = letterVector[0], smallestPosition = 0;

    for (int i = 1; i < letterVector.size(); i++) {
        if (letterVector[i] < smallestNum) {
            smallestNum = letterVector[i];
            smallestPosition = i;
        }
    }

    cout << "\nThe shortest string is " << strVector[smallestPosition] << " with " << smallestNum << " letters\n";
}

void firstString(vector<string> strVector) {
    sort(strVector.begin(), strVector.end());
    cout << "\nThe first string lexicographically is " << strVector[0];
}

void lastString(vector<string> strVector) {
    sort(strVector.begin(), strVector.end());
    cout << "\nThe last string lexicographically is " << strVector[strVector.size() - 1];
}

int main() {
    vector<string> strVector;
    vector<int> letterVector;
    bool contLooping = true;
    int loopPosition = 0;

    String enteredStr;

    while (contLooping) {
        cout << "Enter a string (\"No more\" to stop inputting): ";
        getline(cin, enteredStr);

        if (enteredStr == "No more") {
            cout << endl;
            contLooping = false;
        }
        else {
            strVector.push_back(enteredStr);
        }

        loopPosition++;
    }

    letterVector = charsPerString(strVector);
    for (int i = 0; i < strVector.size(); i++) {
        cout << "The word " << strVector[i] << " has " << letterVector[i] << " letters\n";
    }

    longestString(strVector, letterVector);
    shortestString(strVector, letterVector);
    firstString(strVector);
    lastString(strVector);
}