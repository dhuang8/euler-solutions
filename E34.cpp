#include <iostream>
using namespace std;

int fac[10] = {1,1,2,6,24,120,720,5040,40320,362880};

bool testCurious(int a) {
    int cur = a;
    int sum = 0;
    while (cur>0) {
        int digit = cur % 10;
        sum += fac[digit];
        cur = cur / 10;
    }
    if (sum == a) return true;
    return false;
}

int main() {
    //cout << testCurious(145);
    
    int sum = 0;
    //fac = [1,1,2,6,24,120,720,5040,40320,362880];
    for (int a=10;a<9999999;a++) {
        if (testCurious(a)) {
            cout << a << "\n";
            sum +=a;
        }
    }
    cout << sum;
    
}