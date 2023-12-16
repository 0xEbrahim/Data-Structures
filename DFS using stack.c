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

int pop(Stack*ps){
    if(isEmpty(&*ps)){
        printf("Stack is Empty.\n");
    }
    Node *tmp = ps -> top;
    int x = tmp -> val;
    ps -> top = ps -> top -> next ;
    free(tmp);
    ps -> size--;
    return x;
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


int adj[100][100] = {0};
int vis[100] = {0};
int n , m;


void dfs(int start) {
    Stack stack;
    init(&stack);
    push(&stack, start);
    vis[start] = 1;
    while (isEmpty(&stack)!=1) {
        int current = pop(&stack);
        for (int i = 1; i <= n; ++i) {
            if (adj[current][i] == 1 && vis[i] != 1) {
                push(&stack, i);
                vis[i] = 1;
            }
        }
    }
}

int countConnectedComponents() {
    int count = 0;

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i);
            count++;
        }
    }

    return count;
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the adjacency matrix as [u, v]:\n");
    for (int i = 0; i < m; ++i) {
        int u , v;
        scanf("%d",&u);
        scanf("%d",&v);
        adj[u][v] = 1;

    }

    int connectedComponents = countConnectedComponents();
    printf("%d\n", connectedComponents);

    return 0;
}
