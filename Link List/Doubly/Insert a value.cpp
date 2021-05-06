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

void insert_front(int value)
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
        new_node -> next = head;
        head -> pre = new_node;
        head = new_node;
    }
}

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

void insert_nth(int n, int value)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node -> data = value;
    new_node -> pre = NULL;
    new_node -> next = NULL;

    if(head == NULL)
    {
        if(n == 1)
        {
            head = new_node;
            last = new_node;
        }
        else printf("Trying to insert at a wrong position.\n");
    }
    else
    {
        if(n == 1)
        {
            new_node -> next = head;
            head -> pre = new_node;
            head = new_node;
        }
        else
        {
            n -= 2;
            node *temp = head;
            while(n-- && temp != NULL) temp = temp -> next;
            if(temp == NULL) printf("Trying to insert at a wrong position.\n");
            else
            {
                if(temp == last)
                {
                    last -> next = new_node;
                    new_node -> pre = last;
                    last = new_node;
                }
                else
                {
                    new_node -> next = temp -> next;
                    new_node -> pre = temp;
                    temp -> next -> pre = new_node;
                    temp -> next = new_node;
                }
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

void reprint()
{
    node *temp = last;
    while(temp != NULL)
    {
        printf("%d\n", temp -> data);
        temp = temp -> pre;
    }
}

int main()
{
    insert_back(1);
    insert_back(2);
    insert_nth(3, 3);
    insert_nth(1, 4);
    insert_nth(5, 5);
    insert_nth(4, 6);
    insert_nth(2, 7);
    insert_back(8);
    reprint();
}
