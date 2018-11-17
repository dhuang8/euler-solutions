#include <iostream>
using namespace std;

int sumsquare(int n) {
    return 4*n*n-6*n+6;
}

int main() {    
    int sum = 1;
    for (int i=3;i<1002;i+=2){
        sum+=sumsquare(i);
    }
    //cout << sum;
    printf("%i", sum);
}