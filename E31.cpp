#include <iostream>
using namespace std;

//len = 7
int cost[] = {2,5,10,20,50,100,200};

int coins(int leftover, int coincount) {
    if (coincount<0) return 1;
    int sum = 0;
    int i = 0;
    while (leftover >= 0) {
        sum += coins(leftover, coincount-1);
        leftover -= cost[coincount];
    }
    return sum;
}

int main() {
    cout << coins(200,6);
}