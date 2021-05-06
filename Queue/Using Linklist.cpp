#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *pre;
    int data;
    struct node *next;
} node;

node *head = NULL;
node *last = NULL;
int ssize;

void enqueue(int value){
    node *new_node = (node*)malloc(sizeof(node));
    new_node -> data = value;
    new_node -> pre = NULL;
    new_node -> next = NULL;
    if(head == NULL)
    {
        head = new_node;
        last = new_node;
    }
    else
    {
        last -> next = new_node;
        new_node -> pre = last;
        last = new_node;
    }
    ssize++;
}

void dequeue(){
    if(head == NULL) printf("Empty list.\n");
    else if(head == last)
    {
        node *out = head;
        free(out);
        head = NULL;
        last = NULL;
    }
    else
    {
        node *out = head;
        head = head -> next;
        head -> pre = NULL;
        free(out);
    }
	ssize--;
}

void print_full(){
    node *temp = head;
    while(temp != NULL){
        printf("%d\n", temp -> data);
        temp = temp -> next;
    }
}

int get_top(){ return head -> data; }

int get_size(){ return ssize; }

bool check_empty(){
    if(ssize) return true;
    else return false;
}

int main(){
    push_top(1);
    push_top(2);
    push_top(3);
    pop_top();
    printf("%d\n", get_top());
}