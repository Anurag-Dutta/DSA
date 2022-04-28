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

int main(int argc, char **argv)
{
    struct node *node1 = CreateNode(2);
    struct node *node2 = CreateNode(3);
    node1->next = node2;
    head = node1;
    getch();
    return 0;
}