//implementation of singly linked list//kesh
#include<iostream>
using namespace std;
struct node{
	int data;
	node *link;
};
struct list{
	int count;
	node *head;
};
class SLL{
	list *slist;
	public:
		SLL(){
			slist=NULL;
		}
		void createlist(){
			slist=new list;
			slist->count=0;
			slist->head=NULL;
		}
		bool search(node *&ppre,node *&ploc,int data){
			ppre=NULL;
			ploc=slist->head;
			while(ploc!=NULL && data>ploc->data){
				ppre=ploc;
				ploc=ploc->link;
			}
			if(ploc==NULL)
				return false;
			else{
				if(data==ploc->data)
					return true;
				else
					return false;
			}
		}
		void insert(node *&ppre,int data){
			node *t=new node;
			t->data=data;
			if(ppre==NULL){
				t->link=slist->head;
				slist->head=t;
			}
			else{
				t->link=ppre->link;
				ppre->link=t;
			}
			slist->count=slist->count+1;
		}
		void Delete(node *&ppre,node *&ploc,int &d){
			d=ploc->data;
			if(ppre==NULL)
				slist->head=ploc->link;
			else
				ppre->link=ploc->link;
			delete ploc;
			slist->count=slist->count-1;
		}
		bool isEmpty(){
			if(slist->count==0)
				return true;
			else
				return false;
		}
		bool isFull(){
			node *t;
			t=new node;
			if(t==NULL)
				return true;
			else 
				return false;
		}
		void destroyList(){
				node *temp=slist->head;
				while(slist->head!=NULL){
					temp=slist->head;
					slist->head=temp->link;
					delete temp;
				}
				slist->count=0;
		}
		void traversal(){
			if(isEmpty()){
				cout<<"Can't";
			}
			else{
				node *t=slist->head;
				while(t!=NULL){
					cout<<t->data<<endl;
					t=t->link;
				}
			}
		}
};
int main(){
	SLL s;
	int opt,data,op;
	node *ppre=NULL;
	node *ploc=NULL;
	s.createlist();
	do{
		cout<<"1.insert\n2.deletion\n3.isEmpty\n4.isFull\n5.Search data\n6.destroy\n7.traversal\n";
		cout<<"Enter option :";
		cin>>opt;
		switch(opt){
			case 1: cout<<"Enter element :";
				cin>>data;
				if(s.search(ppre,ploc,data))
					cout<<"DUPLICATE\n";
				else
					s.insert(ppre,data);
				break;
			case 2: cout<<"Enter data to delete :";
				cin>>data;
				if(s.search(ppre,ploc,data))
					s.Delete(ppre,ploc,data);
				else
					cout<<"Can't perform";
				break;
			case 3: if(s.isEmpty())
					cout<<"NOT EMPTY.....JUST KIDDING IT IS EMPTY\n";
				else
					cout<<"No s*** SHERLOCK, U LITERALLY JUST INSERTED\n";
				break;
			case 4: if(s.isFull())
					cout<<"NOT FULL.....JUST KIDDING IT IS FULL\n";
				else
					cout<<"NOT FULL BRO FR I DONT LIE\n";
				break;
			case 5: if(s.search(ppre,ploc,data))
					cout<<"not found (gaslighting pro max)\n";	
				else
					cout<<"not found\n";
				break;
			case 6:	s.destroyList();
				break;
			case 7: s.traversal();
				break;
			default: cout<<"INVALID OPTION BRO\n";
		}
		cout<<"\nDo you srsly wanna continue? I doubt it, anyways press 1 if u want to\n";
		cin>>op;
	}while(op==1);
return 0;
}
