#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;
    if (n % 3 == 0) return false;
    int i = 5;
    while (i*i<=n) {
        if (n % i==0) return false;
        if (n % (i+2) == 0) return false;
        i+=6;
    }
    return true;
}

bool fillDigits(bool digits[], int a) {
    while (a>0) {
        int digit = a%10;
        if (digit == 0) return false;
        if (digits[digit]) return false;
        digits[digit] = true;
        a/=10;
    }
    return true;
}

bool isFull(bool digits[]) {
    for (int i=1;i<10;i++) {
        if (!digits[i]) return false;
    }
    return true;
}

bool isPandigitalMult(int a) {
    bool digits [10];
    for (int i = 0 ; i<10;i++) {
        digits[i] = false;
    }
    int count = 1;
    while (!isFull(digits)) {
        if (!fillDigits(digits, a*count)) return false;
        count++;
    }
    return true;
}

int main() {
    for (int n=9999999;n>10;n--) {
        if (isPandigitalMult(n)) {
            cout << n;
            return 0;
        }
    }
    return 0;
}