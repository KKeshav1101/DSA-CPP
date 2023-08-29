//stack operations//keshav
#include<iostream>
#define size 5
using namespace std;
int dataOut;
class Stack{
	private:	
		int array[size],Top;
	public:
		Stack(){Top=-1;}
		bool EmptyStack(){
			if(Top==-1)
				return true;
			else
				return false;
		}
		bool FullStack(){
			if (Top==size-1)
				return true;
			else
				return false;
		}
		bool push(int data){
			if(FullStack())
				return false;
			else{
				Top++;
				array[Top]=data;
				return true;
			}
		}
		bool pop(int &dataOut){
			if(EmptyStack()){
				return false;
			}
			else{
				dataOut=array[Top];
				Top--;
				return true;
			}
		}
		bool StackTop(int &dataOut){
			if(EmptyStack()){
				return false;
			}
			else{
				dataOut=array[Top];
				return true;
			}	
		}
		void disp(){
			for(int i=Top;i>=0;i--)
				cout<<array[i]<<endl;
		}
};
int main(){
	Stack s1;
	int opt,data,op;
	
	do{
		cout<<"\nChoose the required operation\n1.Push\n2.Pop\n3.Empty\n4.Full\n5.Stacktop\n6.display\n";
		cin>>opt;
		switch(opt){
			case 1:{
				cout<<"Enter data :";
				cin>>data;
				if(s1.push(data))
					cout<<"Push success\n";
				else
					cout<<"Stack overflow\n";
				break;
			}
			case 2:{		
				if(s1.pop(dataOut))
					cout<<"Pop success\n";
				else
					cout<<"Stack underflow\n";
				break;	
			}
			case 3:{
				if(s1.EmptyStack())
					cout<<"Stack empty\n";
				else
					cout<<"Stack is not empty\n";
				break;
			}
			case 4:{
				if(s1.FullStack())
					cout<<"Stack is full\n";
				else
					cout<<"Stack not full\n";
				break;
			}
			case 5:{
				if(s1.StackTop(dataOut))
					cout<<dataOut<<endl;
				else
					cout<<"Underflow\n";
				break;
			}
			case 6:{
				s1.disp();
				break;
			}
			default:cout<<"INVALID OPTION\n";
		}
		cout<<"\nDo you want to continue?(1-> Yes else->no) :";
		cin>>op;
	}while(op==1);
	return 0;
}