#include <iostream>
#include <math.h> //sqrt
using namespace std;
 
int arrsize = 2000000;
bool* notprime = new bool[arrsize];
//bool notprimt[arrsize] = {0};

void fillPrime() {
    for (int i=2;i<arrsize;i++) {
        for (int j=i*2; j<arrsize; j+=i) {
            notprime[j] = true;
        }
    }
}

int maxPrimes (int a, int b) {
    int n = 0;
    while (true) {
        int num = n*n + a*n + b;
        if (num < 2 || notprime[num]) return n;
        n++;
    }
}

int main() {
    fillPrime();
    int best = 0;
    int besta = 0;
    int bestb = 0;
    
    for (int a=-1000; a<1000; a++){    
        for (int b=-1000; b<1000; b++){
            int cur = maxPrimes(a,b);
            if (cur > best) {
                best = cur;
                besta = a;
                bestb = b;
            }
        }
    }
    //cout << best << " " << besta << " " << bestb;
    cout << besta*bestb;
    /*
    for (int i=1;i<50;i++) {
        if (!notprime[i]) cout << i << ", ";
    }
    */
}