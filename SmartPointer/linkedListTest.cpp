#include <iostream>
#include "SmartPointer.h"
using namespace std;

typedef struct Node {
    int val;
    SmartPointer<Node> next;
} Node;

int main(int argc, char const *argv[]) {

    Node* headNode = new Node;
    SmartPointer<Node> head2(headNode);

    {
        SmartPointer<Node> head(headNode);
        head->val = 1;
        head->next = new Node;

        (head->next)->val = 2;
        (head->next)->next = new Node;

        (head->next->next)->val = 3;

        cout << head->val << endl;
        cout << (head->next)->val << endl;
        cout << (head->next->next)->val << endl;
    }

    cout << (head2->next)->val << endl;
    cout << head2->val << endl;

    return 0;
}
