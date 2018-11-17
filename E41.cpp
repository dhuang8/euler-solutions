#include <math.h>
#include <vector>
#include <iostream>
using namespace std;
 

bool isPandigital(int a) {
    int numdigits = 1;
    bool hasdigit[10] = {true, false};
    while (a > 0) {
        int digit = a % 10;
        if (hasdigit[digit]) return false;
        hasdigit[digit] = true;
        a /= 10;
        numdigits++;
    }
    for (int i=1; i<numdigits; i++) {
        if (!hasdigit[i]) return false;
    }
    return true;
}

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

int createnum(int cur, vector<int> left) {
    int maxnum = 0;
    if (left.size()>0) {
        for (int i=0;i<left.size();i++){
            vector<int> thisleft = left;
            int pull = thisleft.at(i);
            thisleft.erase(thisleft.begin()+i);
            int thisnum = cur*10 + pull;
            thisnum = createnum(thisnum, thisleft);
            maxnum = max(maxnum, thisnum);
        }
    } else {
        if (isPandigital(cur) && isPrime(cur)) return cur;
        //cout << cur << "\n";
    }
    return maxnum;
}

int main() {
    vector<int> left {9,8,7,6,5,4,3,2,1};
    while (left.size()>0) {
        int thisnum = createnum(0, left);
        if (thisnum!=0) {
            cout << thisnum;
            return 0;
        }
        left.erase(left.begin());
    }
    cout << createnum(0, left);
    return 0;
}