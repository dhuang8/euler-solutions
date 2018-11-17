#include <fstream>
#include <iostream>
using namespace std;

bool isTriangleNumber (int n){
    int i=0;
    int count=1;
    while (i<n) {
        i+=count;
        count++;
    }
    return n==i;
}
  
int main() {
    string word;
    ifstream inFile;
    inFile.open("p042_words.txt");
    char delim =',';
    int numTriWord=0;
    while (getline(inFile, word, delim)) {
        word = word.substr(1,word.length()-2);
        int total = 0;
        for (int i=0; i<word.length(); ++i) {
            total += word.at(i)-64;    
        }
        if (isTriangleNumber(total)) numTriWord++;
    }
    cout << numTriWord << endl;
    inFile.close();
}