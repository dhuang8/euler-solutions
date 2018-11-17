#include <iostream>
using namespace std;

//ordered
class LinkedList {
private:
    struct Node {
        int val;
        Node* next = NULL;
        Node* prev = NULL;
    };
    Node* head = NULL;
public:
    bool add(int n) {
        //Node* n = new Node{n};
        if (head == NULL) {
            Node* thisnode = new Node{n};
            head = thisnode;
            return true;
        } else {
            Node* cur = head;
            while (cur != NULL) {
                if (cur->val == n) return false;
                else if (cur->val > n) {
                    Node* thisnode = new Node{n};
                    thisnode->prev = cur->prev;
                    thisnode->next = cur;
                    if (cur == head) {
                        head = thisnode;
                    } else {
                        cur->prev->next = thisnode;
                    }
                    cur->prev = thisnode;
                    return true;
                } else {
                    if (cur->next == NULL) {
                        Node* thisnode = new Node{n};
                        cur->next = thisnode;
                        thisnode->prev = cur;
                        return true;
                    }
                    cur = cur->next;
                }
            }
        }
    }
};

bool isPartPandigital(int a, bool* hasdigit) {
    while (a > 0) {
        int digit = a % 10;
        if (hasdigit[digit]) return false;
        hasdigit[digit] = true;
        a /= 10;
    }
    return true;
}

bool isPandigitalProduct(bool* hasdigit) {
    for (int i = 0; i<10; i++) {
        if (!hasdigit[i]) return false;
    }
    return true;
}

int main() {
    LinkedList* ll = new LinkedList();
    /*
    cout << ll->add(100);
    cout << ll->add(1);
    cout << ll->add(100);
    */
    /*
    bool hasdigit[10] = {true, false};
    cout << isPartPandigital(187, hasdigit);
    for (int i = 0; i<10; i++) {
        cout << hasdigit[i];
    }
    */
    
    int total = 0;
    //bool added[987654322] = {false};
    
    for (int a = 1; a < 9999; a++) {
        bool hasdigit[10] = {true, false};
        if (isPartPandigital(a, hasdigit)){
            for (int b = 1; b < 9999; b++) {
                bool hasdigitb[10];
                copy(begin(hasdigit), end(hasdigit), begin(hasdigitb));
                
                if (isPartPandigital(b, hasdigitb)){
                    int prod = a*b;
                    if (isPartPandigital(prod, hasdigitb) && isPandigitalProduct(hasdigitb) && ll->add(prod)) {
                        cout << a << "," << b << "," << prod << "\n";
                        total += prod;
                    }
                }
            }
        }
    }
    
    cout << total;
}