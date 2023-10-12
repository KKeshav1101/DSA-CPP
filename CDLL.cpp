#include<iostream>
using namespace std;
struct node
{
	int data;
	node *forward;
	node *backward;
};
struct list
{
	int count;
	node *head;
	node *rear;
	
};
class CDLL{ 	
    list *headnode;
    public:
    CDLL(){
	    headnode=NULL;
    }
    void createCDLL(){
	    headnode= new list;
	    headnode->count=0;
	    headnode->head=NULL;
	    headnode->rear=NULL;
	}
    bool FullCDLL(){
	    node *temp;
	    if(temp== new node){
		    delete temp;
		    return false;
        }
	    else
	        return true;
    }
    bool EmptyCDLL(){
	    if(headnode->count==0)
	        return true;
	    else
	        return false;
    }
    bool searchList(node* &ppre,node* &ploc,int target){
	    ppre=NULL;
	    ploc=headnode->head;
	    bool found;
	    if(ploc==NULL)
	        return false;
	    if(ploc->data==target)
	        return true;
	    if(target<ploc->data)
	        return false;
	    ppre=ploc;
	    ploc=ploc->forward;
	    while(ploc!=headnode->head&& target>ploc->data){
		    ppre=ploc;
		    ploc=ploc->forward;
	    }
	    if(ploc==headnode->head)
	        found=false;
	    else{
	 	    if(target==ploc->data)
	 	        found=true;
	 	    else
	 	        found=false;
	    }
	    return found;
    }   
    int insertCDLL(int target){
	    node *predecessor=NULL;
	    node *successor=NULL;
	    if(FullCDLL()) 
	    return 0;
	    bool found;  found=searchList(predecessor,successor,target);
	    if(!found){  
	        node *newnode=new node;
		    newnode->data=target;
		    if(predecessor==NULL){
		        if(headnode->count==0){
		            headnode->head=newnode;
		            headnode->rear=newnode;
			    }
			    else{
	                headnode->head->backward=newnode;
	                headnode->rear->forward=newnode;
			    }
                newnode->backward=headnode->rear;
		        newnode->forward=headnode->head;
	            headnode->head=newnode; 
		    }
		    else{
	   	        newnode->forward=successor;
	   	        newnode->backward=predecessor;
	   	        predecessor->forward=newnode;
	   	  	    if(successor==headnode->head){
		            headnode->rear=newnode;
	   	        }
	   	        successor->backward=newnode;
	        }
	   	    ++(headnode->count);
	        return 1;
        }
	    else
	        return 2;
    }
    void DisplayFromHead(){
		node* temp=headnode->head;
		if(temp!=NULL){
		    cout<<temp->data<<"----->";
		    temp=temp->forward;
		}
		while(temp!=headnode->head){
		    cout<<temp->data<<"----->";
		    temp=temp->forward;
		}
		cout<<endl;
	}
    void DisplayFromRear(){
		node* temp=headnode->rear;
		if(temp!=NULL){
			cout<<temp->data<<"<-----";
			temp=temp->backward;
		}
		while(temp!=headnode->head){
			cout<<temp->data<<"<-----";
			temp=temp->backward;
		}
		cout<<endl;
	}
	void deleteCDLL(int target){
	    node *predecessor=NULL;
	    node *deletenode=NULL;
		bool  found;
        found=searchList(predecessor,deletenode,target);
		if(found){
	        if(headnode->count==1){
	            headnode->head=NULL;
	            headnode->rear=NULL;
			}
	        else{
	            if(predecessor!=NULL){
                    predecessor->forward=deletenode->forward;
	                deletenode->forward->backward=predecessor;
	                if(deletenode==headnode->rear)
	                    headnode->rear=predecessor;
                }
		        else{
		            headnode->head=deletenode->forward;
                    deletenode->forward->backward=deletenode->backward;
                    headnode->rear->forward=deletenode->forward;
		        }
		    }
            delete deletenode;	
            --(headnode->count);
	    }
	    else
	        cout<<"data not found";
	}
    int searchCDLLFromHead(int target){
	    node *ploc=headnode->head;
	    int pos=1;
	    if(ploc==NULL)
	        return -1;
	    if(target==ploc->data)
	        return pos;
        ploc=ploc->forward;
	    pos++;
	    while(ploc!=headnode->head&& target>ploc->data){
		    pos++;
		    ploc=ploc->forward;
	    }
	 	if(target==ploc->data)
	 	  return pos; 
	 	else
	 	  return -1;
    }
    int searchCDLLFromRear(int target){
	    node *ploc=headnode->rear;
	    int pos=1;
		if(ploc==NULL)
	        return -1;
	    if(target==ploc->data)
	        return pos;
	    ploc=ploc->backward;
	    pos++;
	    while(ploc!=headnode->rear&& target<ploc->data){
		    pos++;
		    ploc=ploc->backward;
        }
	 	if(target==ploc->data)
	 	  return pos; 
	 	else
	 	  return -1;
    }
    void destroyCDLL(){
	    node* temp=headnode->head;
	    node* temp1;
	    if(headnode->count!=0){
            temp1=temp;
	        temp=temp->forward;
	        delete temp1;
            while(temp!=headnode->head){
	            temp1=temp;
	            temp=temp->forward;
	            delete temp1;
            }
        }
        headnode->head=NULL;
        headnode->rear=NULL;
        headnode->count=0;
    }
};
int main(){
	CDLL l1;
	int target;
	char ch;
	l1.createCDLL();
	int choice;
	node *predecessor=NULL;
	node *loc=NULL;
	bool found;
	int pos;
	do{
		cout<<"1.insert 2.delete 3.searchCDLLfromhead 4.searchCDLLfromrear 5.destroyCDLL 6.display\n";
		cin>>choice;
	    switch(choice){
		case 1:
		        cout<<"Enter inserting data\n";
	            cin>>target;
	            l1.insertCDLL(target);
		        if(!l1.EmptyCDLL())
	                l1.DisplayFromHead();
	            break;
        case 2:
		        cout<<"Enter deleting data\n";
	            cin>>target;
	            l1.deleteCDLL(target);
	            if(!l1.EmptyCDLL())
	                l1.DisplayFromHead();
	            break;
	    case 3:
	            cout<<"Enter searching data from head\n";
	            cin>>target;
	  	        pos= l1.searchCDLLFromHead( target);
	  	        if(pos==-1)
	  	            cout<<"data not found";
	  	        else
                    cout<<"It is found at position "<<pos<<" from head \n";
                break;
        case 4:
	            cout<<"Enter searching data from rear\n";
                cin>>target;
	  	        pos= l1.searchCDLLFromRear( target);
	  	        if(pos==-1)
	  	            cout<<"data not found";
	  	        else
                    cout<<"It is found at position "<<pos<<" from rear \n";
                    break;
        case 5:
     	        l1.destroyCDLL();
     	        break;
     	case 6:
                l1.DisplayFromRear();
     		    break; 
        }
	    cout<<"con?";
	    cin>>ch;
   }while(ch=='y'||ch=='Y');
   return 0;
}





	




