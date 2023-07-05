#include <stdio.h>
#include <stdlib.h>
typedef struct Node node;

struct Node{
    int data;
    node* next;
};

node* newnode(int x){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void insert(node** hd,node **tl,int x){
    node* temp = newnode(x);
    if(*hd == NULL){
        *hd = temp;
        *tl = temp;
    }else{
        (*tl)->next = temp;
        (*tl) = temp;
    }
}

void pop(node** hd,node **tl){
    if(*hd != NULL){
        node* temp = (*hd)->next;
        (*hd)->next = NULL;
        free(*hd);
        (*hd) = temp;
    }
    if((*hd) == NULL){
        (*tl) = NULL;
    }

}

int front(node** head){
    if(*head == NULL){
        printf("queue is empty\n");
        return -1;
    }
    return (*head)->data;
}

void display(node* head){
    while(head!=NULL){
        printf("%d ",head->data);
        head = head -> next;
    }
    printf("\n");
}

void check_queue(){
    node* queue_h = (node*) malloc(sizeof(node));
    queue_h = NULL;
    node* queue_t = (node*) malloc(sizeof(node));
    queue_t = NULL;    
    for(int i=1; i<=5; i++){
        insert(&queue_h,&queue_t,i);
        display(queue_h);
    }
    display(queue_h);
    for(int i=1; i<=5; i++){
        pop(&queue_h,&queue_t);
        display(queue_h);
    }
}



void bfs(int** graph, int src, int n){
    int* visited = (int*) calloc(n,sizeof(int));
    for(int i=0; i<n; i++){
        visited[i]=0;
    }
    visited[src]=1;
    
    node* queue_h = (node*) malloc(sizeof(node));
    queue_h = NULL;
    node* queue_t = (node*) malloc(sizeof(node));
    queue_t = NULL;  

    insert(&queue_h,&queue_t,src);

    while(queue_h!=NULL){
        int fnode = front(&queue_h);
        printf("%d ",fnode);
        pop(&queue_h,&queue_t);
        for(int i=0; i<n; i++){
            if(!visited[i] && graph[fnode][i]==1){
                insert(&queue_h,&queue_t,i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}


void dfs(int** arr, int src, int n, int* visited){
    
    visited[src] = 1;
    printf("%d ",src);
    for(int i=0; i<n; i++){
        if(!visited[i] && arr[src][i]==1){
            visited[i] = 1;
            dfs(arr, i, n, visited);
        }
    }

}

int main(){
    int n;
    printf("Enter the number of nodes in the graph");
    scanf("%d",&n);
    int e;
    printf("Enter the number of edges in the graph");
    scanf("%d",&e);
    int type;
    printf("Enter 1 for directed graph and 0 for undirected graph\n");
    scanf("%d",&type);
    printf("give information about the nodes:");
    int** graph = (int**) calloc(n,sizeof(int*));
    for(int i=0; i<n; i++){
        graph[i] = (int*) calloc(n,sizeof(int));
    }
    while(e--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a>=n || b>=n){
            printf("bhai pagal ho gya tu!\n");
            return 0;
        }
        if(type==1)
        graph[a][b] = c;
        else{
             graph[a][b] = c;
            graph[b][a] = c;
        }

    }

    for(int i=0; i<n; i++){
        printf("%d-->",i);
        for(int j=0; j<n; j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    printf("\n\n bfs of the graph is:\n");
    bfs(graph,0,n);
    //check_queue();
    int* visited = (int*) calloc(n,sizeof(int));
    for(int i=0; i<n; i++){
        visited[i]=0;
    }
    printf("\n\ndfs of the given graph is:\n");
    dfs(graph,0,n,visited);
    printf("\n");
    return 0;
}


