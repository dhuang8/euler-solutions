#include <iostream>
using namespace std;

int recurlen(int n) {
    bool divhis[n] = {false};
    int dividend = 1;
    divhis[1] = true;
    int count = 0;
    while (true) {       
        while (dividend < n) {
            dividend *= 10;
        }
        dividend = dividend % n;
        //printf("remain: %i\n", dividend);
        if (dividend ==0) return 0;
        count++;
        if (divhis[dividend] == true) return count;
        divhis[dividend] = true;

    }
}

int main() {    
    int bestnum = 1;
    int bestrecurringlen = 0;
    for (int i=1;i<1000;i++){
        int recur = recurlen(i);
        if (recur > bestrecurringlen) {
            bestrecurringlen = recur;
            bestnum=i;
        }
    }
    printf("%i", bestnum);
}