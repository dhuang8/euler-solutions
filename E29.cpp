#include <iostream>
using namespace std;

int pow(int a, int b){
    int result = 1;
    for (int i=0;i<b;i++){
        result*=a;
    }
    return result;
}

int log(int a, int b) {
    int cur = a;
    int count = 1;
    while (cur != b) {
        cur = cur * a;
        count++;
    }
    return count;
}

//int* base = new int[101];
int base[101] = {0};

bool testDup(int a, int b) {
    if (base[a]==0) return false;
    int basea = base[a];
    int baseb = b*log(basea,a);
    //cout << basea << "," << baseb;
    int mult = 1;
    while (mult < baseb) {
        if (baseb % mult == 0) {
            int curb = baseb / mult;
            if (curb<101) {
                //cout << curb;
                if (curb == b) return false;
                return true;
            }
        }
        mult++;
    }
    return false;
}

int main() {
    //saves the base below the index
    for (int i = 10; i>1;i--) {
        int j = 2;
        int index = i*i;
        while (index<101) {
            base[index] = i;
            index*=i;
        }
    }
    cout << base[4] << "\n";
    int total = 99*99;
    
    for (int a=2; a<101; a++){    
        for (int b=2; b<101; b++){
            if (testDup(a,b)) {
                total--;
            }
        }
    }
    cout << total;
}