#include <iostream>
#include "SmartPointer.h"
using namespace std;

typedef struct Node {
    int val;
    SmartPointer<Node> next;
    SmartPointer<Node> prev;
} Node;

int main(int argc, char const *argv[]) {

    Node* node1 = new Node;
    Node* node2 = new Node;

    SmartPointer<Node> head(node1);

    // doesn't garbage collect due to circular reference
    head->next = node2;
    (head->next)->prev = node1;

    return 0;
}
