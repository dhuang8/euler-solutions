#include <iostream>
#include <cstdio>
#include "infint-master\InfInt.h"
using namespace std;

int main() {
    InfInt a = 0;
    InfInt b = 1;
    int count = 1;

    for (int i=0;i<9999999;i++){
        count++;
        a=b+a;
        if (a.numberOfDigits()>999) {
            
        cout << count;
        cout << ": ";
        cout << a;
        return 0;
        }
        count++;
        b=a+b;
        if (a.numberOfDigits()>999) {
            
            cout << count;
            cout << ": ";
            cout << b;
            return 0;
        }
    }
}