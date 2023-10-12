#include<iostream>
using namespace std;
struct node{
    int data;
    node *forward;
    node *backward;
};

struct list{
    int count;
    node *head;
    node *rear;
};

class DLL{
    list *headnode;
    public:
    DLL(){
        headnode=NULL;
    }
    void createDLL(){
        headnode= new list;
        headnode->count=0;
        headnode->head=NULL;
        headnode->rear=NULL;
    }

    bool FullDLL(){
        node *temp;
        if(temp==new node){
            delete temp;
            return false;
        }
        else
            return true;
    }

    bool EmptyDLL(){
        if(headnode->count==0)
            return true;
        else
            return false;
    }
    bool searchList(node* &ppre,node* &ploc,int target){
        ppre=NULL;
        ploc=headnode->head;
        bool found;
        while(ploc!=NULL&& target>ploc->data){
            ppre=ploc;
            ploc=ploc->forward;
        }
        if(ploc==NULL)
            found=false;
        else if(target==ploc->data)
            found=true;
        else
            found=false;
        return found;
    }
    int insertDLL(int target){ 
        node *predecessor=NULL;
        node *successor=NULL;
        if(FullDLL())
            return 0;
        bool found=searchList(predecessor,successor,target);
        if(!found){ 
            ++(headnode->count);
            node *newnode=new node;
            newnode->data=target;
            if(predecessor==NULL){
                newnode->backward=NULL;
                newnode->forward=headnode->head;
                (headnode->head)=newnode;
            }
            else{
                newnode->forward=successor;
                newnode->backward=predecessor;
                predecessor->forward=newnode;
            }
            if(successor==NULL)
                headnode->rear=newnode;
            else
                successor->backward=newnode;
            return 1;
        }
        else
        return 2;
    }
    void DisplayFromHead(){
        node* temp=headnode->head;
        int a;
        while(temp!=NULL){
            cout<<temp->data<<"----->";
            temp=temp->forward;
        }
        cout<<endl;
    }
    void DisplayFromRear(){
        node* temp=headnode->rear;
        while(temp!=NULL){
            cout<<temp->data<<"<-----";
            temp=temp->backward;
        }
        cout<<endl;
    }
    void deleteDLL(node *deletenode){
        if(deletenode==NULL)
            cout<<"data not found";
        else{
            if(deletenode->backward!=NULL)
                deletenode->backward->forward=deletenode->forward;
            else
                headnode->head=deletenode->forward;
            if(deletenode->forward!=NULL)
                deletenode->forward->backward=deletenode->backward;
            else
                headnode->rear=deletenode->backward;
            delete deletenode;
            --(headnode->count);
        }
    }
    int searchDLLFromHead(int target){
        node *ploc=headnode->head;
        int pos=1;
        while(ploc!=NULL&& target>ploc->data){
            pos++;
            ploc=ploc->forward;
        }
        if(ploc==NULL)
            return -1;
        else{
            if(target==ploc->data)
                return pos;
            else
                return -1;
            }
        }
    int searchDLLFromRear(int target){
        node *ploc=headnode->rear;
        int pos=1;
        while(ploc!=NULL&& target<ploc->data){
            pos++;
            ploc=ploc->backward;
        }
        if(ploc==NULL)
            return -1;
        else{
            if(target==ploc->data)
                return pos;
            else
                return -1;
        }
    }
    void destroyDLL(){
        node* temp=headnode->head;
        node*temp1;
        while(temp!=NULL){
            temp1=temp;
            temp=temp->forward;
            delete temp1;
        }
        headnode->head=NULL;
        headnode->rear=NULL;
        headnode->count=0;
    }
};
int main(){ 
    DLL l1;
    int target;
    char ch;
    l1.createDLL();
    int choice;
    node *predecessor=NULL;
    node *loc=NULL;
    bool found;
    int pos;
    do{ 
        cout<<"1.insert\n2.delete\n3.searchDLLfromhead\n4.searchDLLfromrear\n5.destroyDLL\nEnter choice :";
        cin>>choice;
        switch(choice){ 
            case 1: cout<<"Enter inserting data\n";
                    cin>>target;
                    l1.insertDLL(target);
                    if(!l1.EmptyDLL())
                        l1.DisplayFromHead();
                    break;
            case 2:
                    cout<<"Enter deleting data\n";
                    cin>>target;
                    found=l1.searchList(predecessor,loc,target);
                    l1.deleteDLL(loc);
                    if(!l1.EmptyDLL())
                        l1.DisplayFromHead();
                    break;
            case 3:
                    cout<<"Enter searching data from head\n";
                    cin>>target;
                    pos= l1.searchDLLFromHead(target);
                    if(pos==-1)
                        cout<<"data not found";
                    else
                        cout<<"It is found at position "<<pos<<" from head \n";
                    break;
            case 4:
                    cout<<"Enter searching data from rear\n";
                    cin>>target;
                    pos= l1.searchDLLFromRear(target);
                    if(pos==-1)
                        cout<<"data not found";
                    else
                        cout<<"It is found at position "<<pos<<" from rear \n";
                    break;
            case 5: 
                    l1.destroyDLL();
                    break;
        }
        cout<<"con?";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    return 0;
}