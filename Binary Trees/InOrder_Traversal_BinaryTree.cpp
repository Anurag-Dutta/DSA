#include "bits/stdc++.h"
#include "conio.h"

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *CreateNode(int data)
{
    struct node *NEWNODE = (struct node *)malloc(sizeof(struct node));
    NEWNODE->data = data;
    NEWNODE->left = NULL;
    NEWNODE->right = NULL;
    return NEWNODE;
}
void InOrderNode(struct node *root_node)
{
    if (root_node == NULL)
    {
        return;
    }
    InOrderNode(root_node->left);
    cout << root_node->data << " ";
    InOrderNode(root_node->right);
}
int main(int argc, char **argv)
{
    struct node *node0 = CreateNode(1);
    struct node *node1 = CreateNode(2);
    struct node *node2 = CreateNode(3);
    struct node *node3 = CreateNode(4);
    struct node *node4 = CreateNode(5);
    struct node *node5 = CreateNode(6);
    struct node *node6 = CreateNode(7);
    node0->left = node1;
    node0->right = node2;
    node0->left->left = node3;
    node0->left->right = node4;
    node0->right->left = node5;
    node0->right->right = node6;
    InOrderNode(node0);
    getch();
    return 0;
}