#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

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

vector<int> getDigits(int a) {
    vector<int> digits;
    while (a>0) {
        digits.push_back(a%10);
        a/=10;
    }
    return digits;
}

vector<int> getRot(int a) {
    vector<int> digits = getDigits(a);
    vector<int> nums;
    for (int n = 0; n < digits.size(); n++) {
        int num = 0;
        int count = 1;
        for (auto it = digits.rbegin(); it != digits.rend(); it++) {
            num += *it * count;
            count *= 10;
        }
        nums.push_back(num);
        rotate(digits.begin(), digits.end()-1, digits.end());
    }
    return nums;
}

int main() {
    int count = 0;
    for (int n=1; n<1000000;n++) {
        vector<int> test = getRot(n);
        bool isprime = true;
        for (auto it = test.rbegin(); it != test.rend(); it++) {
            // cout << *it << " ";
            isprime = isprime && isPrime(*it);
        }
        if (isprime) count++;
    }
    cout << count;
    return 0;
}