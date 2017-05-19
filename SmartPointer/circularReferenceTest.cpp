#include <iostream>
#include "SmartPointer.h"
using namespace std;

typedef struct Node {
    int val;
    SmartPointer<Node> next;
    SmartPointer<Node> prev;
} Node;

int main(int argc, char const *argv[]) {

    SmartPointer<Node> head(new Node);
    head->next = new Node;
    (head->next)->prev = (head->next);

    return 0;
}
