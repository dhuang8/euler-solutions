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

bool testLeft(int a) {
    while (a>0) {
        if (!isPrime(a)) return false;
        a/=10;
    }
    return true;
}

bool testRight(int a) {
    while (a>0) {
        if (!isPrime(a)) return false;
        int b = a;
        int count = 1;
        while (b>9) {
            b/=10;
            count*=10;
        }
        a -= (b*count);
    }
    return true;
}

int main() {
    int sum = 0;
    int count = 0;
    for (int n=10; n<100000000;n++) {
        if (testLeft(n) && testRight(n)) {
            sum+=n;
            count++;
            cout << n << "\n";
            if (count>10) {
                cout << "sum: " << sum;
                return 0;
            }
        }
    }
    cout << "not enough";
    return 0;
}