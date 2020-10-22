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
//function for checkin if the tree is binary searcg tree or not (not so efficient)
//function to check if the value in left sub-tree from root node passed from bst_util() is lesser or not
bool islesser(bst*  root,int val)
{
    if(root==NULL)
    return true;
    if((root->data<=val)&&(islesser(root->left,val))&&(islesser(root->right,val)))
    return true;
    else
    return false;
}
//function to check if the value in right sub-tree from root node passed from bst_util() is greater or not
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
//function to check if the tree is bst or not (efficient way)
bool binary_tree_utility(bst *root,long long int min_limit,long long int max_limit)
{
    if(root==NULL)
    return true;
    if((root->data>min_limit)&&(root->data<=max_limit)&&(binary_tree_utility(root->left,min_limit,root->data))&&(binary_tree_utility(root->right,root->data,max_limit)))
    return true;
    else
    {
        return false;
    }
    
}
bool isbinarysearchtree(bst *root)
{
    if(root==NULL)
    {
        return true;
    }
     return binary_tree_utility(root,INT64_MIN,INT64_MAX);
}
//function to find the minimum value root address
bst* min_node_add(bst* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}
//deleting a node in binary tree
bst* delete_node(bst *root,int data)
{
    if(root==NULL)
    {
        return root;
    }
    else if(root->data>data)
    {
        root->left=delete_node(root->left,data);
    }
    else if(root->data<data)
    {
        root->right=delete_node(root->right,data);
    }
    else
    {
        //for 0 child node
        if(root->left==NULL&&root->right==NULL)
        {
            delete root;
            root=NULL;
        }
        //for 1 child node
        //for right sub tree
        else if(root->right==NULL)
        {
            bst* temp=root;
            root=root->left;
            delete temp;
        }
        //for left sub tree
        else if(root->left==NULL)
        {
            bst *temp=root;
            root=root->right;
            delete temp;
        }
        //for two  child node
        else
        {
            bst *temp= min_node_add(root->right);
            root->data=temp->data;
            root->right=delete_node(root->right,temp->data);
        }
    }
    return root;
    
}
bst* Find(bst *root, int data) {
	if(root == NULL) return NULL;
	else if(root->data == data) return root;
	else if(root->data < data) return Find(root->right,data);
	else return Find(root->left,data);
}

//Function to find Node with minimum value in a BST
bst* FindMin(bst* root) {
	if(root == NULL) return NULL;
	while(root->left != NULL)
		root = root->left;
	return root;
}

//Function to find Inorder Successor in a BST
bst* Getsuccessor(bst* root,int data) {
	// Search the Node - O(h)
	bst *current = Find(root,data);
	if(current == NULL) return NULL;
	if(current->right != NULL) {  //Case 1: Node has right subtree
		return FindMin(current->right); // O(h)
	}
	else {   //Case 2: No right subtree  - O(h)
		bst* successor = NULL;
		bst* ancestor = root;
		while(ancestor != current) {
			if(current->data < ancestor->data) {
				successor = ancestor; // so far this is the deepest node for which current node is in left
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
	}
}

//main function

int main()
{
    bst* root=NULL;
    root=insert_node(root,5);
    root=insert_node(root,3);
    root=insert_node(root,1);
    root=insert_node(root,2);
    root=insert_node(root,0);
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
    
    if(isbinarysearchtree(root))
    cout<<"\nbinary tree\n";
    else
    cout<<"\nnot binary tree\n";

    root=delete_node(root,25);
    cout<<"after deletion of node\n";
    inordered(root);
    bst *successor=Getsuccessor(root,2);
    if(successor==NULL)
    {
        cout<<"\nno successor found\n";
    }
    else
    {
        cout<<"\nsuccessor found\n"<<successor->data;
    }
    
    return 0;
}