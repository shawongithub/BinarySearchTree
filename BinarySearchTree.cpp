#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* GetNode(int data)
{
    Node* node=new Node();
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
};
Node* Insert(Node* root,int data)
{
    if(root==NULL)
    {
        root=GetNode(data);
    }
    else if(data<=root->data)
    {
        root->left=Insert(root->left,data);
    }
    else
    {
        root->right=Insert(root->right,data);
    }
    return root;
};
bool Search(Node* root,int data)
{
    if(root==NULL)
    {
        return false;
    }
    else if(root->data==data)
    {
        return true;
    }
    else if(data<=root->data)
    {
        return Search(root->left,data);
    }
    else
    {
        return Search(root->right,data);
    }
}
int MinValue(Node* root)
{
    if(root==NULL)
    {
        printf("\nno data exist\n");
        return -1;
    }
    Node* current=root;
    while(current->left!=NULL)
    {
        current=current->left;
    }
    return current->data;
}
int MaxValue(Node* root)
{
    if(root==NULL)
    {
        printf("\nno data is found\n");
        return -1;
    }
    else if(root->right==NULL)
    {
        return root->data;
    }
    return MaxValue(root->right);

}
int FindHeight(struct Node* root)
{
    if(root==NULL)
    {
        return -1;
    }
    return max(FindHeight(root->left),FindHeight(root->right))+1;
}
void LevelOrder(Node* root)
{
    if(root==NULL) return;
    queue<Node*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        Node* current=Q.front();
        printf("%d\t",current->data);
        if(current->left!=NULL) Q.push(current->left);
        if(current->right!=NULL) Q.push(current->right);
        Q.pop();
    }
}
void PreOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d\t",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    InOrder(root->left);
    printf("%d\t",root->data);
    InOrder(root->right);
}
void PostOrder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d\t",root->data);

}
int main()
{
    Node* root=NULL;
    root=Insert(root,15);
    root=Insert(root,5);
    root=Insert(root,20);
    root=Insert(root,23);
    root=Insert(root,3);
    root=Insert(root,11);
    root=Insert(root,9);
    root=Insert(root,21);
    int n;
    printf("enter the data you want to search:");
    scanf("%d",&n);
    if(Search(root,n)==true)
    {
         printf("the data is found");
    }
    else
    {
        printf("the data is not found");
    }
    int minvalue=MinValue(root);
    printf("\n\niterative method.the min value of this tree is:%d\n",minvalue);

    int maxvalue=MaxValue(root);
    printf("\n\nrecursive method.the max value of this tree is:%d\n",maxvalue);

    int height=FindHeight(root);
    printf("\nthe height of this tree:%d\n",height);

    printf("\ndata after level order traversal\n");
    LevelOrder(root);

    printf("\ndata after preorder traversal\n");
    PreOrder(root);

    printf("\ndata after inorder traversal\n");
    InOrder(root);

    printf("\ndata after postorder traversal\n");
    PostOrder(root);

    return 0;
}
