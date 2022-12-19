#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i,m;
    cout<<"How Much Elements are in Your Heap: ";
    cin>>n;

    long H[n+5],Delete;
    cout<<"Enter All Elements of Heap in Sequential Representation:"<<endl;
    for(i=1;i<=n;i++){
        cin>>H[i];
    }
    cout<<endl;

    cout<<"Before Deletion:"<<endl;
    for(i=1;i<=n;i++){
        cout<<H[i]<<" ";
    }
    cout<<endl<<endl;

    cout<<"What will you Delete Now: ";
    cin>>Delete;
    cout<<endl;

    for(i=1;i<=n;i++)if(H[i]==Delete){
        m=i;
        H[i]=H[n];
    }

    for(i=m;i<n/2;i){
        if(H[2*i]>H[(2*i)+1]&&H[2*i]>H[i]){
            swap(H[i],H[2*i]);
            i=2*i;
            cout<<" B "<<i;
        }
        else if(H[2*i]<H[(2*i)+1]&&H[(2*i)+1]>H[i]){
            swap(H[i],H[(2*i)+1]);
            i=(2*i)+1;
        }
        else break;
    }
    n=n-1;

    cout<<"After Deletion:"<<endl;
    for(i=1;i<=n;i++){
        cout<<H[i]<<" ";
    }
    cout<<endl;
    return 0;
}
