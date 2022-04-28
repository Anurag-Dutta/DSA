#include "bits/stdc++.h"
#include "conio.h"

using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *CreateNode(int data)
{
    struct node *NEWNODE = (struct node *)malloc(sizeof(struct node));
    NEWNODE->data = data;
    NEWNODE->next = NULL;
    return NEWNODE;
}
struct node *head;
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
int main(int argc, char **argv)
{
    struct node *node1 = CreateNode(2);
    struct node *node2 = CreateNode(3);
    node1->next = node2;
    head = node1;
    TraversalLinkedList(head);
    getch();
    return 0;
}