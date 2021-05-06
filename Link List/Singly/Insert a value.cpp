#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;

void insert_front(int value)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node -> data = value;
    new_node -> next = NULL;
    if(head == NULL) head = new_node;
    else
    {
        new_node -> next = head;
        head = new_node;
    }
}

void insert_back(int value)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node -> data = value;
    new_node -> next = NULL;
    if(head == NULL) head = new_node;
    else
    {
        node *temp = head;
        while(temp -> next != NULL) temp = temp -> next;
        temp -> next = new_node;
    }
}

void insert_nth(int n, int value)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node -> data = value;
    new_node -> next = NULL;
    if(head == NULL)
    {
        if(n == 1) head = new_node;
        else printf("Trying to insert at a wrong position.\n");
    }
    else
    {
        if(n == 1)
        {
            new_node -> next = head;
            head = new_node;
        }
        else
        {
            n -=  2;
            node *temp = head;
            while(n-- && temp != NULL) temp = temp -> next;
            if(temp == NULL) printf("Trying to insert at a wrong position.\n");
            else
            {
                new_node -> next = temp -> next;
                temp -> next = new_node;
            }
        }
    }
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
    insert_back(20);
    insert_front(10);
    insert_back(40);
    insert_nth(3, 30);
    insert_nth(5, 30);
    print();
}
