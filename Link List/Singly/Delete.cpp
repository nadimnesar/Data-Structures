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

void delete_front()
{
    if(head == NULL) printf("Empty list.\n");
    else
    {
        node *out = head;
        head = head -> next;
        free(out);
    }
}

void delete_back()
{
    if(head == NULL) printf("Empty list.\n");
    else
    {
        if(head -> next == NULL)
        {
            node *out = head;
            head = head -> next;
            free(out);
        }
        else
        {
            node *temp = head;
            while(temp -> next -> next != NULL) temp = temp -> next;
            node *out = temp -> next;
            temp -> next = NULL;
            free(out);
        }
    }
}

void delete_nth(int n)
{
    if(head == NULL) printf("Empty list.\n");
    else
    {
        if(n == 1)
        {
            node *out = head;
            head = head -> next;
            free(out);
        }
        else
        {
            n -=  2;
            node *temp = head;
            while(n-- && temp != NULL) temp = temp -> next;
            if(temp == NULL) printf("Trying to delete a wrong position.\n");
            else
            {
                node *out = temp -> next;
                temp -> next = temp -> next -> next;
                free(out);
            }
        }
    }
}

void delete_a_value(int value)
{
    if(head == NULL) printf("Empty list.\n");
    else
    {
        if(head -> data == value)
        {
            node *out = head;
            head = head -> next;
            free(out);
        }
        else
        {
            node *temp = head;
            while(temp -> next != NULL)
            {
                if(temp -> next -> data == value)
                {
                    node *out = temp -> next;
                    temp -> next = temp -> next -> next;
                    free(out);
                    return;
                }
                temp = temp -> next;
            }
            printf("No such value founded.\n");
        }
    }
}

void print()
{
    if(head == NULL) printf("Empty list.\n");
    else
    {
        node *temp = head;
        while(temp != NULL)
        {
            printf("%d\n", temp -> data);
            temp = temp -> next;
        }
    }
}

int main()
{
    insert_back(10);
    insert_back(20);
    insert_back(30);
    insert_back(40);
    delete_a_value(340);
    //delete_back();
    //delete_nth(3);
    print();
}
