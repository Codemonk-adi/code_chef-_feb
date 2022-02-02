#include<iostream>

using namespace std;

int main(){

    int t=0;
    int *arr = new int[t];
    int temp;
    int i=0;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int *str = new int[n];
        for(int i=0;i<n;i++){
            cin>>str[i];
        }
        int max,min;
        max=str[0];
        min=str[0];
        for(int i=0;i<n;i++){
            temp=str[i];
            if(temp>max)
            max=temp;
            if(temp<min)
            min=temp;
        }
        arr[i]=2*(max-min);
        i++;

    }
    for(int j=0;j<i;j++){
        cout<<arr[j]<<endl;
    }  
}