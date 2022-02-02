#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int undone(vector<int>::iterator beg,vector<int>::iterator end,int begin,int weight){
    int left=0;
    int cnt=count(beg,end,begin);
    if(cnt==0){
        return 0;
    }else if(weight%cnt!=0){
        return weight;
    }else{
        vector<int>::iterator temp=beg;
        for(int i=0;i<cnt;i++){
            temp=find(temp,end,begin);
            int p=temp-beg+2;
            left+=undone(temp,end,p,weight/cnt);
            temp++;
        }
        return left;
    }
};

int main(){
    int n;
    cin>>n;
    int temp;
    vector<int> array;
    for(int i=1;i<n;i++){
        cin>>temp;
        array.push_back(temp);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int begin;
        int weight;
        cin>>begin>>weight;
        int left = undone(array.begin(),array.end(),begin,weight);
        cout<<left;
    }

}