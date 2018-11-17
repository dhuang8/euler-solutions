#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

vector<int> getDigits(int a) {
    vector<int> digits;
    while (a>0) {
        digits.push_back(a%10);
        a/=10;
    }
    return digits;
}

bool isPalin(int a) {
    vector<int> digits = getDigits(a);
    for (int n = 0; n < digits.size()/2; n++) {
        if (digits.at(n) != digits.at(digits.size()-1-n)) return false;
    }
    return true;
}

bool isPalin(vector<bool> digits) {
    for (int n = 0; n < digits.size()/2; n++) {
        if (digits.at(n) != digits.at(digits.size()-1-n)) return false;
    }
    return true;
}

vector<bool> getBinary (int a) {
    vector<bool> digits;
    while (a > 0) {
        digits.push_back(a % 2);
        a /= 2;
    }
    return digits;
}

int main() {

    int sum = 0;
    for (int n=1; n<1000000;n++) {
        if (isPalin(n)) {
            vector<bool> bin = getBinary (n);
            if (isPalin(bin)) sum +=n;
        }
    }
    cout << sum;
    return 0;
}