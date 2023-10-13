#include<iostream>
using namespace std;
struct node{
    node *left;
    int data;
    node *right;
};
class BST{
    public:
        node *root;
        BST(){
            root=NULL;
        }
        node *insert(node *root,int d){
            if(root==NULL){
                node *nn=new node;
                nn->data=d;
                nn->left=NULL;
                nn->right=NULL;
                root=nn;
                return root;
            }
            if(d<root->data){
                root->left=insert(root->left,d);
            }
            else
                root->right=insert(root->right,d);
            return root;
        }
        void inorder(node *root){
            if(root!=NULL){
                inorder(root->left);
                cout<<root->data<<" ";
                inorder(root->right);
            }
        }
        void preorder(node *root){
            if(root!=NULL){
                cout<<root->data<<" ";
                preorder(root->left);
                preorder(root->right);
            }
        }
        void postorder(node *root){
            if(root!=NULL){
                postorder(root->left);
                postorder(root->right);
                cout<<root->data<<" ";
            }
        }
        void findsmallest(node *root){
            if(root->left==NULL)
                cout<<root->data;
            else    
                findsmallest(root->left);
        }
        void findlargest(node *root){
            if(root->right==NULL)
                cout<<root->data;
            else   
                findlargest(root->right);
        }
        node *Delete(node *root,int d){
            if(root==NULL)
                return root;
            if(d<root->data)
                root->left=Delete(root->left,d);
            else if(d>root->data)
                root->right=Delete(root->right,d);
            else if(root->left==NULL){
                node *delptr=root;
                root=root->right;
                delete delptr;
                return root;
            }
            else if(root->right==NULL){
                node *delptr=root;
                root=root->left;
                delete delptr;
                return root;
            }
            else{
                node *delptr=root->left;
                while(delptr->right!=NULL)
                    delptr=delptr->right;
                root->data=delptr->data;
                root->left=Delete(root->left,delptr->data);
            }
            return root;
        }
};
int main(){
    BST t;
    int d,opt,op;
    do{
        cout<<"1.INSERT\n2.TRAVERSAL\n3.FIND SMALLEST\n4.FIND LARGEST\n5.DELETION\nENTER OPTION :";
        cin>>opt;
        switch(opt){
            case 1:
                    cout<<"Enter data to insert :";
                    cin>>d;
                    t.root=t.insert(t.root,d);
                    break;
            case 2:
                    cout<<"INORDER :";
                    t.inorder(t.root);
                    cout<<endl<<"PREORDER :";
                    t.preorder(t.root);
                    cout<<endl<<"POSTORDER :";
                    t.postorder(t.root);
                    cout<<endl;
                    break;
            case 3: 
                    t.findsmallest(t.root);
                    break;
            case 4:
                    t.findlargest(t.root);
                    break;
            case 5:
                    cout<<"Enter data to delete";
                    cin>>d;
                    t.root=t.Delete(t.root,d);
                    break;
            default: 
                    cout<<"INVALID OPTION";
        }
        cout<<endl<<"Do you want to continue(1/0) ?";
        cin>>op;
    }while (op==1);    
}