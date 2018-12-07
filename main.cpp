#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using std::cin;
using std::endl;
using std::cout;
using std::vector;
using std::string;

template <class T>
string FindPrimes (T userInput) {
    
    
    int targetInt = (int) floor((userInput* 100.0) + 0.5) / 100;

    vector<int> dividableBy;
    string resultString;

    for(int i=2; i < targetInt; i++) {
        if (targetInt % i == 0) {
            dividableBy.push_back(i);
        }
    }

    if(dividableBy.empty()) {
        resultString = "Number " + std::to_string(targetInt);
        resultString += " is a Prime!";
    } else {
        resultString = "Your Number is not a prime and is dividable by ";
        int i = 0;
        for(std::vector<int>::iterator it = dividableBy.begin(); it != dividableBy.end(); ++it, i++) {
            if(dividableBy.size() == 1) {
                resultString += std::to_string(*it) + ".";
                continue;
            }
            if(i != dividableBy.size() - 1) {
                resultString += std::to_string(*it) + ", ";
            } else {
                resultString += "and " + std::to_string(*it);
                resultString += ".";
            }
        }
    }

    return resultString;
}

int main() {

    float userInput;

    cout << "Input a Number" << endl;

    cin >> userInput;

    cout << "Looking for Primes for " << userInput << endl;

    string resultString = FindPrimes(userInput);

    cout << resultString << endl;

    return 0;
}
