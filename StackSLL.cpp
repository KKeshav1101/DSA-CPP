//stack implementation using sll
#include<iostream>
using namespace std;
struct node{
	int data;
	node *link;
};
struct stack_head{
	int count;
	node *top;
};
class Stack{
	stack_head *head;
	public:
	Stack(){
		head=NULL;
	}
	void createStack(){
		head=new stack_head;
		head->count=0;
		head->top=NULL;
	}
	bool pushStack(int data){
		if(fullstack())
			return false;
		else{
			node *t=new node;
			t->data=data;
			t->link=head->top;
			head->top=t;
			head->count=head->count+1;
			return true;
		}
	}
	bool popStack(int &dataOut){
		if(emptystack())
			return false;
		else{
			dataOut=head->top->data;
			node *t=head->top;
			head->top=t->link;
			delete t;
			head->count=head->count-1;
			return true;
		}
	}
	bool stackTop(int &dataOut){
		if(emptystack())
			return false;
		else{
			dataOut=head->top->data;
			return true;
		}
	}
	bool emptystack(){
		if(head->count==0)
			return true;
		else
			return false;
	}
	bool fullstack(){
		node *t=new node;
		if(t==NULL)
			return true;
		else
			return false;
	}
	void destroystack(){
		node *temp;
		while(head->top!=NULL){
			temp=head->top;
			head->top=temp->link;
			delete temp;
		}
		head->count=0;
	}
	void display(){
		if(emptystack())
			cout<<"Can't perform/n";
		else{
			node *t=head->top;
			while(t!=NULL){
				cout<<t->data<<endl;
				t=t->link;
			}
		}
	}
};
int main(){
	Stack s;
	int op,data,opt;
	int dataOut;
	s.createStack();
	do{
		cout<<"\nCHOOSE AN OPTION\n1.push\n2.pop\n3.stacktop\n4.emptystack\n5.destroy\n6.display\n";
		cin>>op;
		switch(op){
			case 1:   cout<<"\nEnter data :";
				cin>>data;
				if(s.pushStack(data))
					cout<<"Push success\n";
				else
					cout<<"Overflow\n";
				break;
			case 2:   if(s.popStack(dataOut))
					cout<<"Pop success\n";
				else
					cout<<"Underflow\n";
				break;
			case 3:   if(s.stackTop(dataOut))
					cout<<dataOut;
				else
					cout<<"Stack Empty\n";
				break;
			case 4:   if(s.emptystack())
					cout<<"Stack Empty\n";
				else
					cout<<"Not empty\n";
				break;
			case 5:   s.destroystack();
				cout<<"Done\n";
				break;
			case 6:   s.display();
				break;
			default:  cout<<"INVALID OPTION try again\n";
		}
		cout<<"Press 1 to continue :";
		cin>>opt;
	}while(opt==1);
}
