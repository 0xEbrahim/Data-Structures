#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node*next;
    struct node*prev;
}Node;

void displayLinkedList(Node *head){
    Node *tmp = head;
    while(tmp){
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}

void displayReversedLinkedList(Node *tail){
    Node *curr = tail;
    while(curr){
        printf("%d ", curr->val);
        curr = curr->prev;
    }
    printf("\n");
}

void reverseLinkedList(Node *head){
    Node *curr = head;
    Node *last = NULL;
    while(curr){
        Node *tmp = curr -> next;
        curr -> next = last;
        curr -> prev = tmp;
        last = curr;
        curr = tmp;
    }
}

void insertNode(Node *head, Node *el){
    Node *curr = head;
    while(curr){
        if(curr -> next == NULL) {
            el -> prev = curr;
            curr->next = el;
            el -> next = NULL;
            break;
        }
        curr = curr -> next;
    }
}

int main() {
    Node *one = malloc(sizeof (Node)),
    *two = malloc(sizeof(Node)),
    *three = malloc(sizeof(Node));
    one -> prev = NULL;
    one -> next = two;
    one -> val = 1;
    two -> prev = one;
    two -> next = three;
    two -> val = 2;
    three -> prev = two;
    three -> next = NULL;
    three -> val = 3;
    displayLinkedList(one);
    reverseLinkedList(one);
    displayLinkedList(three);
    Node *four = malloc(sizeof(Node));
    four -> val = 4 ;
    four -> next = NULL;
    four -> prev = NULL;
    reverseLinkedList(three);
    insertNode(one, four);
    displayLinkedList(one);
    displayReversedLinkedList(four);
    
}
