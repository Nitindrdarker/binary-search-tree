#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
//creating nodes named bst
class bst{
    public:
    int data;
    bst *left,*right;
};
//function to create new node on every call
bst* newNode(int data)
{
    bst *n=new bst();
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
//function to insert a value in its location in this bst
bst* insert_node(bst *root,int data)
{
    if(root==NULL)
    {
        root=newNode(data);
    }
    else if(root->data>data)
    {
        root->left=insert_node(root->left,data);
    }
    else
    {
        root->right=insert_node(root->right,data);
    }
    return root;
}
//function for searching a numeber inside this tree......
bool search_node(bst* root,int data)
{
    if(root==NULL)
    {return false;}
    else if(root->data==data)
    {return true;}
    else if(root->data>data)
    {
        return search_node(root->left,data);
    }
    else
    {
        return search_node(root->right,data);
    }
}
//function to find  the height of bst by counting the numebr of edges between two nodes
int height(bst *root)
{
    if(root==NULL)
    {
        return -1;
    }
    int left_height,right_height;
    left_height=height(root->left);
    right_height=height(root->right);
    return max(left_height,right_height)+1;

}
//function to find the maximum  in this bst
int max_value(bst* root)
{
    if(root->right==NULL)
    return root->data;
    return max_value(root->right);
}
int min_value(bst *root)
{
    if(root->left==NULL)
    return root->data;
    return min_value(root->left);
}
//traversing in this bst using breadth first algorithm
void breadth_traversing(bst* root)
{   if(root==NULL)
        {
            cout<<"empty tree \n";
            return ;
        }
    queue<bst*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        
        bst* current=Q.front();
        Q.pop();//removing the front element from queue
        cout<<current->data<<" ";
        if(current->left!=NULL)
        {
            Q.push(current->left);
        }
        if(current->right!=NULL)
        {
            Q.push(current->right);
        }
        
    }
}
//traversing using depth first alog... (preordered)
void preordered(bst *root)
{
    if(root==NULL)
    return ;
    cout<<root->data<<" ";
    preordered(root->left);
    preordered(root->right);
}
//inorderd traversal
void inordered(bst *root)
{
    if(root==NULL)
    return;
    inordered(root->left);
    cout<<root->data<<" ";
    inordered(root->right);
}
void postordered(bst* root)
{
    if(root==NULL)
    return;
    postordered(root->left);
    postordered(root->right);
    cout<<root->data<<" ";
}
//function for checkin fi the tree is binary searcg tree or not (not so efficient)
//function to check if the vlue in left sub-tree from root node passed from bst_util() is lesser or not
bool islesser(bst*  root,int val)
{
    if(root==NULL)
    return true;
    if((root->data<=val)&&(islesser(root->left,val))&&(islesser(root->right,val)))
    return true;
    else
    return false;
}
//function to check if the vlue in right sub-tree from root node passed from bst_util() is greater or not
bool isgreater(bst*  root,int val)
{
    if(root==NULL)
    return true;
    if((root->data>val)&&(isgreater(root->left,val))&&(isgreater(root->right,val)))
    return true;
    else
    return false;
}
//function to use islesser and isgreater function for finding the result
bool bst_util(bst *root)
{
    if(root==NULL)
    return true;
    if(islesser(root->left,root->data)&&(isgreater(root->right,root->data))&&bst_util(root->left)&&bst_util(root->right))
    return true;
    else
    return false;
    
}
//main function
int main()
{
    bst* root=NULL;
    root=insert_node(root,15);
    root=insert_node(root,10);
    root=insert_node(root,20);
    root=insert_node(root,25);
    root=insert_node(root,8);
    root=insert_node(root,12);
    if(search_node(root,25))
    {
        cout<<"found\n";
    }
    else
    {
        cout<<"Not found!\n";
    }
    cout<<"height is "<<height(root)<<endl;
    cout<<"max value in this bst is "<<max_value(root)<<endl;
    cout<<"min value in this bst is "<<min_value(root)<<endl;
    cout<<"breadth-traversal\n";
    breadth_traversing(root);
    cout<<"\npreorderd-traversal\n";
    preordered(root);
    cout<<"\ninorderd-traversal\n";
    inordered(root);
    cout<<"\npostordered-travarsa\n";
    postordered(root);
    if(bst_util(root))
    {
        cout<<"\nits a binary tree!"<<endl;
    }
    else
    {
        cout<<"\nnot  binary tree!"<<endl;
    }
    
    return 0;
}