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

void search_a_value_position(int value)
{
    int p = 1;
    node *temp = head;
    while(temp != NULL)
    {
        if(temp -> data == value)
        {
            printf("%d\n", p);
            return;
        }
        p++;
        temp = temp -> next;
    }
    printf("No value founded.\n");
}

void search_nth_value(int n)
{
    node *temp = head;
    n--;
    while(n-- && temp != NULL) temp = temp -> next;
    if(temp == NULL) printf("No value founded.\n");
    else printf("%d\n", temp -> data);
}

void search_min_value()
{
    node *temp = head;
    if(temp == NULL) printf("No value founded.\n");
    else
    {
        int mini = temp -> data;
        while(temp != NULL)
        {
            if(temp -> data < mini) mini = temp -> data;
            temp = temp -> next;
        }
        printf("%d\n", mini);
    }
}

int main()
{
    insert_back(10);
    insert_back(20);
    insert_back(30);
    insert_back(40);

    search_nth_value(4);
}
