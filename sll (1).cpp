//SLL by keshav
#include<iostream>
using namespace std;
struct node{    
	int data;
	node *link;
};    
class SLL{  
	node *first;
	public:
		SLL(){
			first=NULL;
		}
		void insertBeg(int d){
			node*t=new node;
			t->data=d;
			if(first==NULL){
				t->link=NULL;
				first=t;
			}
			else{
				t->link=first;
				first=t;
			}
		}
		void insertEnd(int d){
			node* t=new node;
			t->data=d;
			if(first==NULL){
				t->link=NULL;
				first=t;
			}
			else{
			node* temp=first;
			while(temp->link!=NULL)
				temp=temp->link;
			temp->link=t;
			t->link=NULL; 
			}
		}
		void insertAtLoc(int d,int loc){
			if(first==NULL)
				cout<<"\ncan't perform\n";
			else{
				node* t=new node;
				t->data=d;
				int c=0;
				node* temp=first;
				while(c<loc-1){
					temp=temp->link;
					c++;
				}
				t->link=temp->link;
				temp->link=t;
			}
		}
		void deleteBeg(){
			if(first==NULL)
				cout<<"\nCan't perform\n";
			else{
				node* t=first;
				first=first->link;
				delete t;
			}
		}
		void deleteAtloc(int loc){
			if(first==NULL)	
				cout<<"\ncan't perform\n";
			else{
				int c=1;
				node* t1=first;
				node* t2;
				while(c<loc){
					t2=t1;
					t1=t1->link;
					c++;
				}
				t2->link=t1->link;
				delete t1;		
			}
		}
		void traversal(){
			if(first==NULL)
				cout<<"\ncan't perform\n";
			else{
				node* t=first;
				while(t!=NULL){
					cout<<t->data<<endl;
					t=t->link;
				}	
			}
		}
		void linearsearch(int d){
			if(first==NULL)
				cout<<"\ncan't perform\n";
			else{
				node* t=first;
				int flag=0;
				while(t!=NULL){
					if(t->data==d){
						cout<<t->data<<"present"<<endl;
						flag=1;
					}	
					t=t->link;
				}
				if(flag==0)
					cout<<"Absent";	
			}
		}
};
int main(){
	SLL s;
	int opt,data,loc;
	do{
		cout<<"1.Insert at Beg\n2.Insert at end\n3.Inser at loc\n4.delete Beg\n5.delete given node\n6.traversal\n7.search\n";
		cout<<"Enter the option :";
		cin>>opt;
		switch(opt){
			case 1: cout<<"Enter data :";
		       		cin>>data;
		       		s.insertBeg(data);
		       		break;
			case 2: cout<<"Enter data :";
		       		cin>>data;
		       		s.insertEnd(data);
		       		break;
			case 3: cout<<"Enter data and loc :";
		       		cin>>data>>loc;
		       		s.insertAtLoc(data,loc);
		       		break;
			case 4: s.deleteBeg();
		       		break;
			case 5: cout<<"Enter the node number to delete :";
		       		cin>>loc;
		       		s.deleteAtloc(loc);
		       		break;
			case 6: s.traversal();
		       		break;
		       	case 7: cout<<"Enter data";
		       		cin>>data;
		       		s.linearsearch(data);
			default: cout<<"Invalid option";
			}
			cout<<"Do you want to continue (1/0)? :";
			cin>>opt;
	}while(opt==1);
}
