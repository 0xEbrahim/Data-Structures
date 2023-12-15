#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *next;
}Node;


typedef struct queue{
    Node *front;
    Node *rear;
    int size;
} Queue;

void init(Queue *pq){
    pq -> front = malloc(sizeof(Node));
    pq -> rear = malloc(sizeof(Node));
    pq -> front = NULL;
    pq -> rear = NULL;
    pq -> size = 0;
}

int isEmpty(Queue *pq){
    return pq -> size == 0 ? 1 : 0;
}

void push(Queue *pq, int el){
    Node *new_element = malloc(sizeof(Node));
    if(!new_element){
        printf("Memory allocation error.\n");
        return;
    }
    new_element -> val = el;
    new_element -> next = NULL;
    if(isEmpty(&*pq)){
        pq->front = new_element;
    }else
        pq -> rear -> next = new_element;
    pq -> rear = new_element;
    pq -> size++;
}

void pop(Queue *pq){
    if(isEmpty(&*pq)){
        printf("Queue is Empty.\n");
        return;
    }
    Node *tmp = pq -> front;
    pq -> front = pq -> front -> next;
    free(tmp);
    if(!pq->front)
        pq->rear = NULL;
    pq -> size--;
}

int size(Queue *pq){
    return pq -> size;
}

void display(Queue *pq){
    if(isEmpty(&*pq)){
        printf("Queue is Empty.\n");
        return;
    }
    Node *head = pq -> front;
    while(head){
        printf("%d ", head -> val);
        head = head -> next;
    }
    printf("\n");
}

void clear(Queue *pq){
    while(pq -> front){
        Node *tmp = pq -> front;
        pq -> front = pq -> front -> next;
        free(tmp);
    }
    pq->size = 0;
    pq -> front = NULL;
    pq -> rear = NULL;
}

int main() {
    Queue q;
    init(&q);
    push(&q,1);
    push(&q,2);
    push(&q,3);
    push(&q,4);
    display(&q);
    pop(&q);
    display(&q);
    clear(&q);
    display(&q);
}
