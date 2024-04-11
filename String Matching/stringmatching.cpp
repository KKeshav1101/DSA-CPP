#include<iostream>
#include<cstring>
using namespace std;
class pattern{
    public:
        string p,t;
        int n,m;
        int pi[100];
        void create(){
            cout<<"Enter the text String :";
            cin>>t;
            cout<<"Enter the pattern string :";
            cin>>p;
            n=t.length();
            m=p.length();
        }
        int naive(){
            int count=0;
            for(int i=0;i<n-m;i++){
                int flag=0;
                for(int j=1;j<=m;j++){
                    count++;
                    if(p[j]!=t[i+j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                    cout<<"Pattern occurs with valid shift :"<<i<<endl;
            }
            return count;
        }
        char charcode(char a){
            switch(a){
                case 'a':
                    return 1;
                    break;
                case 'b':
                    return 2;
                    break;
                case 'c':
                    return 3;
                    break;
                case 'g':
                    return 4;
                    break;
                case 't':
                    return 5;
                    break;
                case 'x':
                    return 6;
                    break;
                default:
                    return '0';
            }
        }
        int preprocess(){
            int count=0;
            int pr=0;
            int d=10;
            int q=4999;
            for(int i=1;i<=m;i++){
                count++;
                pr=(d*pr+charcode(p[i]))%q;
            }
            cout<<"Preprocess :"<<count<<endl;
            return pr;
        }
        int rabinkarp(){
            int d=10;
            int q=4999;
            int h=1;
            int pe=preprocess();
            for(int i=1;i<m;i++)
                h=(h*d)%q;
            int count=0;
            int te=0;
            for(int i=1;i<=m;i++){
                count++;
                te=(d*te+charcode(t[i]))%q;
            }
            for(int s=0;s<=n-m;s++){
                int flag=0;
                count++;
                if(pe==te){
                    for(int j=1;j<=m;j++){
                        count++;
                        if(p[j]!=t[s+j]){
                            flag=1;
                            break;
                        }
                    }
                }
                if (s<n-m){
                    t=(d*(te-charcode(t[s+1])*h)+charcode(t[s+m+1]))%q;
                    if(te<0){
                        te=te%q;
                        te=q-te;
                    }
                }
            }
            return count;
        }
        int prefix(){
            pi[1]=0;
            int k=0;
            int count=0;
            for(int q=2;q<=m;q++){
                count++;
                while(k>0 && p[k+1]!=p[q]){
                    k=pi[k];
                    count++;
                }
                if(p[k+1]==p[q])
                    k++;
                pi[q]=k;
            }
            cout<<"Pre process: "<<count<<endl;
            return count;
        }
        int kmp(){
            int count=0;
            int q=0;
            for(int i=1;i<=n;i++){
                count++;
                while(q>0 && p[q+1]!=t[i]){
                    q=pi[q];
                    count++;
                }
                if(p[q+1]==t[i]){
                    q++;
                    if(q==m){
                        q=pi[q];
                    }
                }
            }
            return count;
        }
};
int main(){
    pattern s;
    int runn=0;
    while(runn==0){
        s.create();
        int a=s.naive();
        cout<<"Naive :";
        cout<<a<<endl;
        int b=s.rabinkarp();
        cout<<"Rabin Karp :";
        cout<<b<<endl;
        int c=s.prefix();
        b=s.kmp();
        cout<<"KMP :";
        cout<<b<<endl;
        cout<<"Enter 0 to run again";
        cin>>runn;
        cout<<endl;
    }
    return 0;
}