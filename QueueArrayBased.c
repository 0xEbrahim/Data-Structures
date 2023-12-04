#include <stdio.h>
#include <math.h>
int MXS = 5;


typedef struct queue{
int rear , front, size;
int entry[5];
} Queue;

void init(Queue*pq){
    pq -> front = 0;
    pq -> rear = -1;
    pq -> size = 0;
}

void enqueue(Queue*pq, int el){
    if(pq -> size == MXS){
          printf("Queue is full!.\n");
          return;
    }
    pq -> rear = (pq -> rear + 1) % MXS;
    pq -> entry[pq -> rear] = el;
    pq -> size++;
}

int dequeue(Queue*pq){
    if(pq -> size == 0){
        printf("Queue is empty!.\n");
        return 0;
    }
    pq -> size--;
    int el = pq->entry[pq->front];
    pq->front = (pq -> front + 1) % MXS;
    return el;
}

int peak(Queue*pq){
    if(pq -> size == 0){
        printf("Queue is empty!.\n");
        return 0;
    }
    return pq -> entry[pq -> front];
}

int isFull(Queue*pq){
    return (pq -> size == MXS);
}

int isEmpty(Queue*pq){
    return (pq -> size == 0);
}

void display(Queue*pq){
    if(isEmpty(&*pq)){
        printf("Queue is Empty\n");
        return;
    }
    for(int i = pq -> front ; i < pq -> front + pq -> size && i < MXS  ; i++){
        printf("%d ",pq->entry[i]);
    }
    if(pq -> rear < pq -> front && pq -> size != 0){
        for (int i = 0; i <= pq -> rear; i++)
            printf("%d ", pq -> entry[i]);
    }
    printf("\n");
}

int queueSize(Queue*pq){
    return pq -> size;
}

void clearQueue(Queue*pq){
    pq -> front = 0;
    pq -> rear = -1;
    pq -> size = 0;
}
int main() {
Queue q;
init(&q);
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    enqueue(&q,5);
    display(&q);
    dequeue(&q);
    display(&q);
    dequeue(&q);
    display(&q);
    enqueue(&q,6);
    display(&q);
    enqueue(&q,7);
    display(&q);
    enqueue(&q,8);
    display(&q);
    clearQueue(&q);
    display(&q);
}
