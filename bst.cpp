#include <bits/stdc++.h>
#include <queue>
using namespace std;
 
class node
{
                int data = -1;
                node* left;
                node* right;
        public :
                node()
                {
                        this->left = NULL;
                        this->right = NULL;                     
                }
                node(int val)   
                {
                        this->data = val;
     tr                   this->left = NULL;
                        this->right =  NULL;
                }
                friend class Binary_Tree;               
};
 
class Binary_Tree
{
                node* root;
        public :
                Binary_Tree()                   {root = NULL;}
                node* getroot()                 {return root;}
                void insert (int data);
                void BST_insert(int data);
                
                //recursive traversals
                void preorder (node*);                 
                void inorder (node*);                 
                void postorder (node*);                 
                void level_order (); 
                
                //iterative traversals
                void iter_preorder();
                void iter_inorder();
                void iter_postorder();
                
                int height_of_tree (node*); 
                node* clone (node*);
                node* mirror_image(node*);
                bool check_equal (node* , node*);  
                
                node* search(node*, int);
                node* delete_node(node*, int);
                node* buildTree(int in[], int pre[], int inStrt, int inEnd);

                         
};
 
void Binary_Tree :: insert(int data)
{
        node * ptr = new node(data);
        if(root == NULL)        root = ptr;
        else
        {
                node* temp = root;
                int choice;
                while(1)
                {
                        cout<<"press 0 for inserting as left subtree of "<<temp->data<<endl;
                        cout<<"press 1 for inserting as right subtree of "<<temp->data<<endl;
                        cin>>choice;
                        if(choice == 0)
                        {
                                if(temp->left == NULL)          {temp->left = ptr; break;}
                                else    temp = temp->left;
                        }
                        else
                        {       
                                if(temp->right == NULL)         {temp->right = ptr; break;}
                                else    temp = temp->right;
                        }                                               
                }
        }                                    
}       
 
void Binary_Tree :: BST_insert (int data)
{
        node* ptr = new node(data);
        if (root == NULL)       root = ptr;
        else
        {
                node*temp = root;
                while(1)
                {
                        if (data < temp->data)
                        {
                                if(temp->left == NULL)         
                                {
                                        temp->left = ptr;
                                        break;
                                 }
                                else                            temp = temp->left;
                        }
                        else
                        {
                                if(temp->right == NULL)         
                                {
                                        temp->right = ptr;
                                        break;
                                 }
                                else                            temp = temp->right;
                        }
                 }
        }
}
 
void Binary_Tree :: preorder(node* Root)                //recursive
{
        if(Root!= NULL)
        {
                cout<<Root->data<<",";
                preorder(Root->left);
                preorder(Root->right);
        }
}
 
void Binary_Tree :: inorder(node* Root)                 //recursive
{
        if(Root!= NULL)
        {
                inorder(Root->left);
                cout<<Root->data<<",";            
                inorder(Root->right);
        }
}
 
void Binary_Tree :: postorder(node* Root)              //recursive
{
        if(Root!= NULL)
        {              
                postorder(Root->left);
                postorder(Root->right);
                cout<<Root->data<<",";
        }
}
 
void Binary_Tree :: level_order()
{
        queue<node*> lvl;
        lvl.push(root);
        if(lvl.empty())         cout<<"tree is empty"<<endl;
        else
        {
                while(!lvl.empty())
                {
                        node* x = lvl.front();
                        lvl.pop();
                        cout<<x->data<<",";
                        if(x->left != NULL)     lvl.push(x->left);
                        if(x->right != NULL)    lvl.push(x->right);
                }
        }       
}
 
//iterative traversal
 
void Binary_Tree :: iter_preorder()
{
    if (root == NULL)        return;
 
    stack<node*> St;
    St.push(root);
 
    while (St.empty() == false)
    {
         node* curr = St.top();
         cout<<curr->data<<" ";
         St.pop();
 
         if (curr->right != NULL)             St.push(curr->right);
         if (curr->left  != NULL)             St.push(curr->left);
    }
}
 
 
void Binary_Tree :: iter_inorder()
{
        
    stack< node*> st;
    node *curr = root;
 
    while (curr != NULL || st.empty() == false)
    {
        while (curr !=  NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
 
        cout << curr->data << " ";  
        curr = curr->right;
     }
}
 
void Binary_Tree :: iter_postorder()
{
        stack <node*> st1,st2;
        node* curr = NULL;
        st1.push(root);
        while(st1.empty() == false)
        {
                curr = st1.top();
                st2.push(curr);
                st1.pop();
                if(curr->left  != NULL)           st1.push(curr->left);
                if(curr->right != NULL)           st1.push(curr->right);
        }
        
        curr = NULL;
        
        while(st2.empty() == false)
        {
                curr = st2.top();
                cout<<curr->data<<" ";
                st2.pop();
        }
 
}
 
int Binary_Tree :: height_of_tree (node* Root)
{
        if(Root == NULL)        return 0;
        else
        {
                int l = height_of_tree (Root->left);
                int r = height_of_tree (Root->right);
                return max(l,r) + 1;
        }
}
 
node* Binary_Tree :: clone (node* Root)
{
        if (Root == NULL)       return NULL;
        else
        {
                node* ptr = new node (Root->data);
                node* x = clone(Root->left);
                node* y = clone(Root->right);
                ptr->left  = x;
                ptr->right = y;
                delete Root;
                return ptr;
        }
}
 
node* Binary_Tree :: mirror_image(node* Root)
{
        if (Root == NULL)       return NULL;
        else
        {
                node* ptr = new node (Root->data);
                node* x = mirror_image(Root->left);
                node* y = mirror_image(Root->right);
                ptr->left  = y;
                ptr->right = x;
                return ptr;
        }
}
 
bool Binary_Tree :: check_equal (node* Root1 , node* Root2)
{
        if (Root1 == Root2)     return 1;
        else if (Root1 == NULL && Root2 != NULL)        return 0;
        else if (Root1 != NULL && Root2 == NULL)        return 0;
        else
        {
                if (Root1->data == Root2->data)
                {
                        bool x = check_equal(Root1->left, Root2->left);
                        if (x== 1)    
                        {
                                bool y = check_equal(Root1->right, Root2->right);
                                if (y== 1)      return 1;
                         } 
                }
                else return 0;
        }       
}


node* Binary_Tree :: search( node* Root,int value)
{
        if (root->data > value)
    {
        if (root->left == NULL)
            return NULL;
        if (root->left->data == value)
            return root;
        else
            return search(root->left, value);
    }
    else
    {
        if (root->right == NULL)
            return NULL;
        if (root->right->data == value)
            return root;
        else
            return search(root->right, value);
    }
}


node* Binary_Tree :: delete_node( node* root, int key)
{
    if (root == NULL)
        return root;

    if (root->data > key) 
    {
        root->left = delete_node(root->left, key);
        return root;
    }
    else if (root->data < key)
    {
        root->right = delete_node(root->right, key);
        return root;
    }
 
    // If one of the children is empty
    if (root->left == NULL) 
    {
        node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL)
    {
        node* temp = root->left;
        delete root;
        return temp;
    }
 
    // If both children exist
    else
     {
       node *temp = root->right;

	  while (temp->left != NULL)
	    temp = temp->left;

	  root->data = temp->data;

	  root->right = delete_node(root->right, temp->data);
        return root;
      }
}

int search_index(int arr[], int strt, int end, int value)
{
    for (int i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
    
}
 
node* Binary_Tree :: buildTree(int in[], int pre[], int inStrt, int inEnd)
{
    static int preIndex = 0;
 
    if (inStrt > inEnd)
        return NULL;
 
    node* tNode = new node(pre[preIndex++]);
 
    if (inStrt == inEnd)
        return tNode;
 
    int inIndex = search_index(in, inStrt, inEnd, tNode->data);
 
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
 
    return tNode;
    
}
 

 
int main()
{
        Binary_Tree tree;
        int data;
        
        int choice;
        int ch;
        int cho;
        int height;
        node* mirror = NULL;
        node* copy = NULL;
        bool equal;
        int key = 0;

        int In_array[1000];
        int Pre_array[1000];

        int x;
        
        
        int size ;
        
        cout<<"1. Binary Tree"<<endl;
        cout<<"2. Binary Search Tree"<<endl;
	cin>>cho;
	if (cho == 1)
	{
	        do
	        {	        
		        cout<<"1. Insert"<<endl;
		        cout<<"2. Traversal "<<endl;
		        cout<<"3. Height of tree "<<endl;
		        cout<<"4. Mirror image of tree "<<endl;
		        cout<<"5. Check equality of trees "<<endl;
		        cout<<"6. Make Clone of tree "<<endl;
		        cout<<"7. Delete a node "<<endl;
                        cout<<"8. construct tree from traversals "<<endl;
		        cout<<"9. EXIT"<<endl;
		        cout<<"Enter the choice : ";		
		        cin>>choice;
		        cout<<endl;
		        
		        switch(choice)
		        {
			        case 1: 
			                cout<<"enter the data :";
			                cin>>data;
			                tree.insert(data);								               
				        break;
				        
			        case 2:			        
		                        do{
		                                bool flag = true;
		                                cout<<"1. preorder"<<endl;
		                                cout<<"2. inorder "<<endl;
		                                cout<<"3. postorder"<<endl;
		                                cout<<"4. level order"<<endl;
		                                cout<<"5. Iterative preorder"<<endl;
		                                cout<<"6. Iterative inorder"<<endl;
		                                cout<<"7. Iterative postorder"<<endl;
		                                cout<<"8. Exit"<<endl;
		                                cin>>ch;
			                        switch(ch)
			                        {
			                                case 1:			                        
			                                        tree.preorder(tree.getroot());
			                                        cout<<endl;
			                                        break;
			                                case 2:			                        
			                                        tree.inorder(tree.getroot());
			                                        cout<<endl;
			                                        break;
			                                case 3:			                        
			                                        tree.postorder(tree.getroot());
			                                        cout<<endl;
			                                        break;
			                                case 4:
			                                        tree.level_order();//tree.getroot());
			                                        cout<<endl;
			                                        break;	
			                                case 5:
			                                        tree.iter_preorder();//tree.getroot());
			                                        cout<<endl;
			                                        break;
			                                case 6:
			                                        tree.iter_inorder();//tree.getroot());
			                                        cout<<endl;
			                                        break;
			                                case 7:
			                                        tree.iter_postorder();//tree.getroot());
			                                        cout<<endl;
			                                        break;
			                                case 8:
			                                        flag = false;
			                                        break;
			                                default :
			                                        flag = false;
			                                        break;                        
			                        }
			                        if(!flag) break;		                        
			                  
			                }    while(0 < ch <= 8);
			                
			        case 3 :			        
			                height = tree.height_of_tree(tree.getroot());
			                cout<<"Height of tree is :"<<height<<endl;
			                break;    
			            
			        case 4 :
			                mirror = tree.mirror_image(tree.getroot());
			                tree.inorder(mirror);
			                cout<<endl;
			                break;
			                
			        case 5 :
			                equal = tree.check_equal(tree.getroot(), copy);
			                if (equal == 1)         cout<<"trees are equal "<<endl;
			                else                    cout<<"trees are not equal "<<endl;
			                break;
			        
			        case 6: 
			                copy = tree.clone(tree.getroot());
			                
			                equal = tree.check_equal(tree.getroot(), copy);
			                if (equal == 1)         cout<<"trees are equal "<<endl;
			                else                    cout<<"trees are not equal "<<endl;
			                
			                break;
			                	
			        case 7:
			                cout<<"Enter the node to be deleted : ";
			                cin>>key;
			                tree.delete_node(tree.getroot(), key);
			                break;
			                
                                case 8:
                                        cout<<"Enter the number of nodes :";
                                        cin>>size;
                                        
                                        cout<<"Enter the inorder traversal :";
                                        for( int i=0; i <size; i++)  
                                        {    
                                              cin>>In_array[i];
                                        }


                                        cout<<"Enter the preorder traversal :";
                                        for( int i=0; i <size; i++)
                                        {       
                                               cin>> Pre_array[i];
                                        }

                                        copy = tree.buildTree(In_array, Pre_array, 0, size-1);
                                        cout<<"inorder is: ";
                                        tree.inorder(copy);
                                        cout<<endl;
                                        cout<<"preorder is: ";
                                        tree.preorder(copy);
                                        cout<<endl;
                                        
                                        break;

			        default :
			                  exit(0);		
		        }
	        } while (0 < choice < 9);      
	}
	
	else
	{
	        do
	        {	        
		        cout<<"1. Insert"<<endl;
		        cout<<"2. Traversal "<<endl;
		        cout<<"3. Height of tree "<<endl;
		        cout<<"4. Mirror image of tree "<<endl;
		        cout<<"5. Check equality of trees "<<endl;
		        cout<<"6. Make Clone of tree "<<endl;
		        cout<<"7. Delete a node "<<endl;
                        cout<<"8. construct tree from traversals "<<endl;
		        cout<<"9. EXIT"<<endl;
		        cout<<"Enter the choice : ";		
		        cin>>choice;
		        cout<<endl;

		        switch(choice)
		        {
			        case 1: 
			                cout<<"enter the data :";
			                cin>>data;
                                        tree.BST_insert(data);
				        break;
				        
			        case 2:			        		               			        
		                        do{
		                                bool flag = true;
		                                cout<<"1. preorder"<<endl;
		                                cout<<"2. inorder "<<endl;
		                                cout<<"3. postorder"<<endl;
		                                cout<<"4. level order"<<endl;
		                                cout<<"5. Iterative preorder"<<endl;
		                                cout<<"6. Iterative inorder"<<endl;
		                                cout<<"7. Iterative postorder"<<endl;
		                                cout<<"8. Exit"<<endl;
		                                cin>>ch;
			                        switch(ch)
			                        {
			                                case 1:			                        
			                                        tree.preorder(tree.getroot());
			                                        cout<<endl;
			                                        break;
			                                case 2:			                        
			                                        tree.inorder(tree.getroot());
			                                        cout<<endl;
			                                        break;
			                                case 3:			                        
			                                        tree.postorder(tree.getroot());
			                                        cout<<endl;
			                                        break;
			                                case 4:
			                                        tree.level_order();//tree.getroot());
			                                        cout<<endl;
			                                        break;	
			                                case 5:
			                                        tree.iter_preorder();//tree.getroot());
			                                        cout<<endl;
			                                        break;
			                                case 6:
			                                        tree.iter_inorder();//tree.getroot());
			                                        cout<<endl;
			                                        break;
			                                case 7:
			                                        tree.iter_postorder();//tree.getroot());
			                                        cout<<endl;
			                                        break;
			                                case 8:
			                                        flag = false;
			                                        break;
			                                default :
			                                        flag = false;
			                                        break;                        
			                        }
			                        if(!flag) break;		                        			                  
			                }while(0 < ch <= 8);

			        case 3 :			        
			                height = tree.height_of_tree(tree.getroot());
			                cout<<"Height of tree is :"<<height<<endl;
			                break;    
			            
			        case 4 :
			                mirror = tree.mirror_image(tree.getroot());
			                tree.inorder(mirror);
			                cout<<endl;
			                break;
			                
			        case 5 :
			                equal = tree.check_equal(tree.getroot(), mirror);
			                if (equal == 1)         cout<<"trees are equal "<<endl;
			                else                    cout<<"trees are not equal "<<endl;
			                break;
			        
			        case 6: 
			                copy = tree.clone(tree.getroot());
			                
			                equal = tree.check_equal(tree.getroot(), copy);
			                if (equal == 1)         cout<<"trees are equal "<<endl;
			                else                    cout<<"trees are not equal "<<endl;
			                
			                break;	
			                
			        case 7:
			                cout<<"Enter the node to be deleted : ";
			                cin>>key;
			                tree.delete_node(tree.getroot(), key);
			                break;
			                
                                case 8:
                                        cout<<"Enter the number of nodes :";
                                        cin>>size;
                                        
                                        cout<<"Enter the inorder traversal :";
                                        for( int i=0; i <size; i++)  
                                        {    
                                              cin>>In_array[i];
                                        }


                                        cout<<"Enter the preorder traversal :";
                                        for( int i=0; i <size; i++)
                                        {       
                                               cin>> Pre_array[i];
                                        }

                                        copy = tree.buildTree(In_array, Pre_array, 0, size-1);
                                        cout<<"inorder is: ";
                                        tree.inorder(copy);
                                        cout<<endl;
                                        cout<<"preorder is: ";
                                        tree.preorder(copy);
                                        cout<<endl;
                                        break;

			        default :
			                  exit(0);		
		        }
	        } while (0 < choice < 9);      
        }
        
        return  0;
}