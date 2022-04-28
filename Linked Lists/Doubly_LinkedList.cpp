#include "bits/stdc++.h"
#include "conio.h"

using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *CreateNode(int data)
{
    struct node *NEWNODE = (struct node *)malloc(sizeof(struct node));
    NEWNODE->data = data;
    NEWNODE->next = NULL;
    NEWNODE->prev = NULL;
    return NEWNODE;
}
struct node *head;
int SizeLinkedList(struct node *node)
{
    struct node *ptr = node;
    int size = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        size++;
    }
    return size;
}
void TraversalLinkedList_Detailed(struct node *head_node)
{
    struct node *ptr = head_node;
    while (ptr != NULL)
    {
        printf("PREVIOUS: %x, DATA = %d, NEXT = %x\n", ptr->prev, ptr->data, ptr->next);
        ptr = ptr->next;
    }
    return;
}
void TraversalLinkedList(struct node *head_node)
{
    struct node *ptr = head_node;
    cout << "HEAD";
    while (ptr != NULL)
    {
        cout << "->" << ptr->data;
        ptr = ptr->next;
    }
    cout << "->NULL" << endl;
    return;
}
void InsertNode(struct node *node, int data, int choice)
{
    struct node *NEWNODE = CreateNode(data);
    if (choice == 0) // Insertion at Head
    {
        NEWNODE->next = head;
        NEWNODE->prev = NULL;
        head->prev = NEWNODE;
        head = NEWNODE;
    }
    if (choice == 1) // Insertion at Tail
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = NEWNODE;
        NEWNODE->next = NULL;
        NEWNODE->prev = ptr;
    }
    if (choice == 2) // Insertion at Random
    {
        int position;
        cin >> position;
        if (position > SizeLinkedList(head) - 1 && position < 0)
        {
            return;
        }
        else
        {
            if (position == 0)
            {
                InsertNode(head, data, 0);
                return;
            }
            if (position == SizeLinkedList(head) - 1)
            {
                InsertNode(head, data, 1);
                return;
            }
            else
            {
                struct node *node = head;
                int flag = 1;
                while (flag != position)
                {
                    node = node->next;
                    flag++;
                }
                NEWNODE->next = node->next;
                NEWNODE->prev = node;
                node->next = NEWNODE;
            }
        }
    }
}
void DeleteNode(struct node *node, int choice)
{
    struct node *tmp = head;
    if (choice == 0) // Deletion from Head
    {
        head = tmp->next;
        free(tmp);
    }
    if (choice == 1) // Deletion from Tail
    {
        struct node *ptr;
        while (tmp->next != NULL)
        {
            ptr = tmp;
            tmp = tmp->next;
        }
        ptr->next = NULL;
        free(tmp);
    }
    if (choice == 2) // Deletion from Random
    {
        int position;
        cin >> position;
        if (position > SizeLinkedList(head) - 1 && position < 0)
        {
            return;
        }
        else
        {
            if (position == 0)
            {
                DeleteNode(head, 0);
                return;
            }
            if (position == SizeLinkedList(head) - 1)
            {
                DeleteNode(head, 1);
                return;
            }
            else
            {
                int flag = 1;
                while (flag != position)
                {
                    tmp = tmp->next;
                    flag++;
                }
                tmp->next = tmp->next->next;
                tmp->next->prev = tmp;
            }
        }
    }
}
int main(int argc, char **argv)
{
    struct node *node1 = CreateNode(2);
    struct node *node2 = CreateNode(3);
    node1->next = node2;
    node1->prev = NULL;
    node2->next = NULL;
    node2->prev = node1;
    head = node1;
    InsertNode(head, 4, 0);
    InsertNode(head, 5, 0);
    InsertNode(head, 6, 1);
    InsertNode(head, 6, 1);
    InsertNode(head, 6, 1);
    TraversalLinkedList(head);
    TraversalLinkedList_Detailed(head);
    getch();
    return 0;
}