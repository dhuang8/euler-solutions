#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int getB(int p, int a) {
    int b = ((p*p-2*a*p)) / (2*(p-a));
    return b;
}

bool testABC(int p, int a, int b) {
    return a*a + b*b == (p-a-b) * (p-a-b);
}

int main() {
    int bestp = 0;
    int bestcount = 0;
    for (int p=1;p<1001;p++) {
        int count = 0;
        for (int a=1;a<p/3;a++) {
            int b = getB(p,a);
            if (testABC(p,a,b)) count++;
        }
        if (count > bestcount) {
            bestp = p;
            bestcount = count;
        }
    }
    cout << bestp << ": " << bestcount << "\n";
}