#include <iostream>
using namespace std;

// Euclidean algorithm a>b
int gcd(int a, int b) {
    int remainder = a % b;
    if (remainder==0) return b;
    return gcd(b, remainder);
}

//b>a
int* simplify(int a, int b) {
    int curgcd = gcd(b,a);
    int* data = new int[2];
    data[0] = a/curgcd;
    data[1] = b/curgcd;
    return data;
}

bool testEqual(int a, int b, int c, int d) {
    if (c>=d || c==0 || d==0) return false;
    int* simp = simplify(c,d);
    if (a==simp[0] && b==simp[1]) return true;
    return false;
}

int main() {
    //int* p = simplify(49,98);
    //cout << p[0] << "/" << p[1] << "\n";
    //cout << testEqual(1, 2, 49, 98);
    int numprod = 1;
    int denprod = 1;
    for (int a=10; a<99; a++) {
        for (int b=a+1; b<100; b++) {
            int c10 = a / 10;
            int c1 = a % 10;
            int d10 = b / 10;
            int d1 = b % 10;
            int* orig = simplify(a,b);
            
            if (c1==0 && d1==0) continue;
            
            if (c1 == d10 && testEqual(orig[0], orig[1], c10, d1)) {
                cout << a << "/" << b << " : " << orig[0] << "/" << orig[1] << "\n";
                numprod *= orig[0];
                denprod *= orig[1];
                continue;
            }
            
            if (c10 == d1 && testEqual(orig[0], orig[1], c1, d10)) {
                cout << a << "/" << b << " : " << orig[0] << "/" << orig[1] << "\n";
                numprod *= orig[0];
                denprod *= orig[1];
                continue;
            }
            
            if (c1 == d1 && testEqual(orig[0], orig[1], c10, d10)) {
                cout << a << "/" << b << " : " << orig[0] << "/" << orig[1] << "\n";
                numprod *= orig[0];
                denprod *= orig[1];
                continue;
            }
            if (c10 == d10 && testEqual(orig[0], orig[1], c1, d1)) {
                cout << a << "/" << b << " : " << orig[0] << "/" << orig[1] << "\n";
                numprod *= orig[0];
                denprod *= orig[1];
                continue;
            }
        }
    }
    int* anssimp = simplify(numprod, denprod);
    cout << anssimp[1];
}