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

int front(Queue *pq){
    return pq -> front -> val;
}

int main() {
    int graph[100][100] = {0};
    int visited[100] = {0};
    int path[100] = {0};
    int n , m ;
    printf("Program to print the shortest path between two nodes on a graph \n");
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("\n Enter the number of edges : ");
    scanf("%d",&m);
    printf("\nEnter the edges as [u,v]\n");
    for(int i = 0 ; i < m ; i++){
        int u , v ;
        scanf("%d",&u);
        scanf("%d",&v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    int start , end;
    printf("Enter the starting Node: ");
    scanf("%d",&start);
    printf("\nEnter the ending Node: ");
    scanf("%d",&end);
    Queue q;
    init(&q);
    push(&q,start);
    visited[start] = 1;
    while (isEmpty(&q) == 0) {
        int top = front(&q);
        pop(&q);
        for (int i = 0; i < 100; i++) {
            if (graph[top][i] == 1 && visited[i] != 1) {
                visited[i] = 1;
                path[i] = top;
                push(&q, i);
            }
        }
    }

    printf("The shortest path is : \n");
    int node = end;
    while (node != start && node != 0) {
        printf("%d ", node);
        node = path[node];
    }
    printf("%d\n", start);
}
