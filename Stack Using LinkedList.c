#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}Node;

typedef struct stack{
    Node *top;
    int size ;
} Stack;

void init(Stack *ps){
    ps -> top = malloc(sizeof(Node));
    ps -> top = NULL;
    ps -> size = 0;
}

void push(Stack *ps, int el){
    Node *new_element = malloc(sizeof (Node));
    if(!new_element){
        printf("Memory allocation error.\n");
        return;
    }
    new_element -> val = el;
    new_element -> next = ps -> top;
    ps -> top = new_element;
    ps -> size++;
}

int isEmpty(Stack *ps){
    return ps -> size == 0 ? 1 : 0;
}

void pop(Stack*ps){
    if(isEmpty(&*ps)){
        printf("Stack is Empty.\n");
        return;
    }
    Node *tmp = ps -> top;
    ps -> top = ps -> top -> next ;
    free(tmp);
    ps -> size--;
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

void clear(Stack *ps){
    while(ps -> top){
        Node *tmp = ps -> top;
        ps -> top = ps -> top -> next;
        free(tmp);
    }
    ps -> size = 0;
    ps -> top = NULL;
}

int size(Stack *ps){
    return ps -> size;
}

int main() {
    Stack st;
    init(&st);
    push(&st,1);
    push(&st,2);
    push(&st,3);
    push(&st,4);
    int sz = size(&st);
    printf("Size => %d \n",sz);
    display(&st);
    clear(&st);
    display(&st);
     sz = size(&st);
    printf("Size => %d \n",sz);

}
