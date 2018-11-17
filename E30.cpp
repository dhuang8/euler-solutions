#include <iostream>
using namespace std;

int pow(int a, int b){
    int result = 1;
    for (int i=0;i<b;i++){
        result*=a;
    }
    return result;
}

int main() {
    int sum = 0;
    //9^5 * 7 is only 6 digits
    for (int i = 10; i<999999;i++) {
        int cur = i;
        int total = 0;
        for (int j = 100000; j>0; j/=10) {
            total += pow(cur/j,5);
            cur-=cur/j*j;
        }
        if (total == i) {
            cout << i << "\n";
            sum += i;
        }
    }
    cout << "Sum: " << sum;
}