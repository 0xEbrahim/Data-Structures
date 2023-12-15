#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}Node;

typedef struct stack{
    Node *top;
} Stack;

void init(Stack *ps){
    ps -> top = malloc(sizeof(Node));
    ps -> top = NULL;
}

void push(Stack *ps, int el){
    Node *new_element = malloc(sizeof (Node));
    new_element -> val = el;
    new_element -> next = ps -> top;
    ps -> top = new_element;
}

int isEmpty(Stack *ps){
    return ps->top == NULL ? 1 : 0;
}

void pop(Stack*ps){
    if(isEmpty(&*ps)){
        printf("Stack is Empty.\n");
        return;
    }
    Node *tmp = ps -> top;
    ps -> top = ps -> top -> next ;
    free(tmp);
}

void top(Stack *ps,  int *el){
    if(isEmpty(&*ps)){
        printf("Stack is Empty.\n");
        return;
    }
    *el = ps->top->val;
}

void display(Stack *ps){
    if(isEmpty(&*ps)){
        printf("Stack is Empty.\n");
        return;
    }

    Node *head = ps -> top;
    while(head){
        printf("%d ", head -> val);
        head = head -> next;
    }
    printf("\n");
}


int main() {
  Stack st;
  init(&st);
    push(&st,1);
    push(&st,2);
    push(&st,3);
    push(&st,4);
    display(&st);
    pop(&st);
    display(&st);
    pop(&st);
    pop(&st);
    pop(&st);
    display(&st);
    pop(&st);
    int tp ;
    top(&st,&tp);
   
}
