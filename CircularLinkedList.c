#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}Node;

int main() {
    Node *one = malloc(sizeof(Node));
    Node *two = malloc(sizeof(Node));
    Node *three = malloc(sizeof(Node));
    one -> val = 1;
    two -> val = 2;
    three -> val = 3;
    one -> next = two;
    two -> next = three;
    three -> next = one;
}
