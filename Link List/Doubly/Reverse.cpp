#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *pre;
    int data;
    struct node *next;
} node;

node *head = NULL;
node *last = NULL;

void insert_back(int value)
{
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
}

void reverse_all()
{
    node *rest = head -> next;
    node *current_last = head;
    node *current_head = head;
    while(rest != NULL)
    {
        current_head -> pre = rest;
        node *temp = rest -> next;
        rest -> next = current_head;
        rest -> pre = NULL;
        current_head = rest;
        rest = temp;
    }
    head = current_head;
    last = current_last;
    last -> next = NULL;
}

void print()
{
    node *temp = head;
    while(temp != NULL)
    {
        printf("%d\n", temp -> data);
        temp = temp -> next;
    }
}

int main()
{
    insert_back(10);
    insert_back(10);
    insert_back(20);
    insert_back(30);
    insert_back(10);
    insert_back(40);
    insert_back(10);
    reverse_all();
    print();
}

