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

void delete_front()
{
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
}

void delete_back()
{
    if(head == NULL) printf("Empty list.\n");
    else if(head == last)
    {
        node *out = last;
        free(out);
        head = NULL;
        last = NULL;
    }
    else
    {
        node *out = last;
        last = last -> pre;
        last -> next = NULL;
        free(out);
    }
}

void delete_nth(int n)
{
    if(head == NULL) printf("Empty list.\n");
    else
    {
        if(n == 1)
        {
            if(head == last)
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
        }
        else
        {
            node *temp = head;
            n--;
            while(n-- && temp != NULL) temp = temp -> next;
            if(temp == NULL) printf("Trying to delete a wrong position.\n");
            else
            {
                if(temp == last)
                {
                    node *out = last;
                    last = last -> pre;
                    last -> next = NULL;
                    free(out);
                }
                else
                {
                    node *out = temp;
                    temp -> next -> pre = temp -> pre;
                    temp -> pre -> next = temp -> next;
                    free(out);
                }
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
            if(head == last)
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
        }
        else if(last -> data == value)
        {
            if(head == last)
            {
                node *out = last;
                free(out);
                head = NULL;
                last = NULL;
            }
            else
            {
                node *out = last;
                last = last -> pre;
                last -> next = NULL;
                free(out);
            }
        }
        else
        {
            node *temp = head;
            while(temp != NULL)
            {
                if(temp -> data == value)
                {
                    node *out = temp;
                    temp -> next -> pre = temp -> pre;
                    temp -> pre -> next = temp -> next;
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
    insert_back(10);
    insert_back(20);
    insert_back(30);
    insert_back(40);
    insert_back(50);
    delete_a_value(30);
    reprint();
}

