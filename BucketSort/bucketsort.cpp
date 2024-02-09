#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
struct node{
    float data;
    node * link;
    node(){
        data=0;
        link=NULL;
    }
};
struct headnode{
    node* first;
    headnode(){
        first=NULL;
    }
};
void insert_order(node *&first,float x,int &count){
    node *n=new node();
    n->data=x;
    node *temp=first;
    if (first==NULL or first->data >= x){
        n->link=first;
        first=n;
        return;
    }
    while(temp->link != NULL and temp->link->data < x){
        count++;
        temp=temp->link;
    }
    n->link=temp->link;
    temp->link=n;
    return;
}
void bucket_sort(float a[],float out[],int size,int &count){
    int i,j=0;
    headnode* b[size];
    node *temp;
    for(i=0;i<size;i++){
        b[i]=new headnode();
    }
    for(i=0;i<size;i++){
        count++;
        int f=floor(size*a[i]);
        insert_order(b[f]->first,a[i],count);
    }
    for(i=0;i<size;i++){
        count++;
        temp=b[j]->first;
        if(temp==NULL){
            i--;
            j++;
            continue;
        }
        out[i]=temp->data;
        b[j]->first=b[j]->first->link;
    }
}
int main(){
    float arr[10000],out[10000];
    float val;
    int i=0,count=0;
    ifstream fin("input_bsort.txt");
    while(i<10000){
        fin>>val;
        arr[i]=val;
        i++;
    }
    fin.close();
    bucket_sort(arr,out,10000,count);
    ofstream fout("bucketsorted.txt");
    for(i=0;i<10000;i++){
        fout<<out[i]<<"\t";
    }
    fout.close();
    cout<<"For 10000 numbers: "<<count<<endl;
}