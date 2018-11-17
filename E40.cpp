#include <iostream>
#include <vector> 
#include <algorithm>
#include <cmath>
using namespace std;

//1st digit means the rightmost
int getDigit(int num, int digit) {
    for (;digit>1;digit--) {
        num /= 10;
    }
    return num % 10;
}

//current count
int curnum = 1;
//current digit
int curplace = 1;
//current digit cap
int curplacetens = 10;
//current count cap
int curnumtens = 10;
int curdigitcount = 1;


int increasePlacements(int numcount) {
    if (numcount+curnum <= curnumtens) {
        curnum += numcount;
        curplace += numcount * curdigitcount;
        if (curnum>=curnumtens) {
            curdigitcount++;
            curnumtens *= 10;
        }
    } else {
        int next = numcount + curnum - curnumtens;
        curplace += (curnumtens - curnum) * curdigitcount;
        curnum = curnumtens;
        curdigitcount++;
        curnumtens *= 10;
    }
}

int main() {

    
    int end[7] = {1,10,100,1000,10000,100000,1000000};
    int i=0;
    int prod = 1;
    
    while (i<7) {
        if (end[i]-curdigitcount>curplace) {
            increasePlacements((end[i]-curplace)/(curdigitcount));
        } else {
            int d = getDigit(curnum, curdigitcount - end[i] + curplace);
            prod *= d;
            cout << curnum << "," << curplace << "," << d << "\n";
            i++;
        }
    }
    cout << prod;
    return 0;
}