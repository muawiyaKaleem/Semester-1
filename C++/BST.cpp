#include <iostream>
using namespace std;

//Tree Node class

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d)
	{
        data = d;
        left = NULL;
        right = NULL;
    }
 
//insert function
    
    Node* insert(Node* root, int data) 
	{
        if(root == NULL)
		{
            return new Node(data);
        }
     else
	 {
            Node* cur;
            if(data <= root->data) 
			{
                cur = insert(root->left, data);
                root->left = cur;
            }
            else 
			{
                cur = insert(root->right, data);
                root->right = cur;
            }
        return root;
     }
    }

    //Indorder traversal
    
	void inorder(Node* root)
	{
        if(root == NULL)
            return;
        
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    //Searching function
    Node* search(Node* root, int key)
	    {
            if(root == NULL || root->data == key )
            {
				return root;
			}
            search(root->left,key);
            search(root->right,key);
        }
         
	//deletenode function.

    Node* deletenode(Node* root, int k) 
    { 
        // Base case 
        if (root == NULL) 
            return root; 
        //If root->data is greater than k then we delete the root's subtree
        if(root->data > k)
		{ 
            root->left = deletenode(root->left, k); 
            return root; 
        } 
        else if(root->data < k)
		{ 
            root->right = deletenode(root->right, k); 
            return root; 
        } 
  

        // If one of the children is empty 
        if (root->left == NULL) { 
            Node* temp = root->right;
            delete root; 
            return temp; 
        } 
        else if (root->right == NULL) { 
            Node* temp = root->left; 
            delete root; 
            return temp; 
        } 
		else
		 {
            Node* Parent = root;
            // Find successor of the node
            Node *succ = root->right; 
            while (succ->left != NULL)
			{ 
                Parent = succ; 
                succ = succ->left; 
            } 

            if (Parent != root)
			{
                Parent->left = succ->right; 
			} 
            else
            {
                Parent->right = succ->right; 
			}

            // Copy Successor Data  
            root->data = succ->data; 

            // Delete Successor and return root 
            delete succ;          
            return root; 
        } 
    } 
};


 
int main()
{
    Node Tree(0);
    Node* root = NULL;
    //Number of nodes to be inserted
    int t,del,search;
    
    for(int i=1; i<=10; i++)
	{
    	cout<<"Value "<<i<<" => ";
    	cin>>t;
        root = Tree.insert(root,t);	
	}
	
//	cout<<"Tree => "<<Tree.inorder(root);
	cout<<"Tree => ";
	Tree.inorder(root);
	
	//deleting a value, in this case deleted value is 5, (list me5 ho ga to delete ho ga warna nahi)
	cout<<endl<<"What Number You want to Delete from the tree => ";
	cin>>del;
	Tree.deletenode(root,del);
	cout<<"\n\nNew Tree after Deleting "<<del<<" => ";
	Tree.inorder(root);
	    	
//searching a value from the tree,in this case searched value is 69, (list me 69 ho ga to delete ho ga warna nahi)
    cout<<endl<<"Enter the number you want to search => ";
    cin>>search;
	Node* d = Tree.search(root,search);
	if (search==d->data)
	{
		cout<<endl<<search<<" is in the Tree"; 	
	}
	else if (search!=d->data)
	{
		cout<<endl<<search<<" is not in the Tree";
	}
	
    return 0;
}