#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct node{
    int val;
    struct node*next;
} Node;

void displayLinkedList(Node *head){
    Node *tmp = head;
    while(tmp){
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
}

void reverseLinkedList(Node *head){
    Node *prev= NULL;
    Node *curr = head;
    while(curr){
        Node *tmp = curr -> next;
        curr -> next = prev ;
        prev = curr;
        curr = tmp;
    }
}

void insertNode(Node *head, Node *el){
    Node *lastNode = malloc(sizeof(Node));
    Node *curr = head;
    while(curr){
        if(curr -> next == NULL)
            lastNode = curr;
        curr = curr->next;
    }
    lastNode -> next = el;
}

void deleteLastNode(Node *head){
    Node *curr = head;
    Node *prev = NULL;
    while(curr){
        prev = curr;
        curr = curr -> next;
        if(curr -> next == NULL) {
            prev->next = NULL;
            break;
        }
    }
}

int main() {
Node *one = NULL,*two = NULL,*three = NULL;
    one = malloc(sizeof(Node));
    two = malloc(sizeof(Node));
    three = malloc(sizeof(Node));
one -> val = 1;
two -> val = 2;
three -> val = 3;
one -> next = two;
two -> next = three;
three -> next = NULL;
displayLinkedList(one);
printf("\n");
reverseLinkedList(one);
displayLinkedList(three);
reverseLinkedList(three);
printf("\n");
displayLinkedList(one);
printf("\n");
Node *four = malloc(sizeof(Node));
four -> val = 4;
four -> next = NULL;
insertNode(one,four);
displayLinkedList(one);
deleteLastNode(one);
printf("\n");
displayLinkedList(one);
}
