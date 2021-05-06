#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;

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

void sorting()
{
    node *currentI = head;
    node *currentJ;
    while(currentI != NULL)
    {
        currentJ = currentI -> next;
        while(currentJ != NULL)
        {
            if((currentI -> data) > (currentJ -> data))
            {
                int temp = currentI -> data;
                currentI -> data = currentJ -> data;
                currentJ -> data = temp;
            }
            currentJ = currentJ -> next;
        }
        currentI = currentI -> next;
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
    insert_back(40);
    insert_back(20);
    insert_back(-9);
    insert_back(40);
    sorting();
    print();
}
