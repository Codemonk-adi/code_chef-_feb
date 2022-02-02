#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<int> ans;
    int track=t;
    while(t--){
        int n;
        cin>>n;
        vector<int> W;
        int L[10];
        map<int,int> mp;
        int temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            W.push_back(temp);
            mp.insert({W[i],i});
        }
        for(int i=0;i<n;i++){
            cin>>L[i];
        }
        sort(W.begin(),W.end());
        int step=0;
        int low_pos=0;
        int curr_pos=0;
        int inc;
        int i=0;
        while(i!=n-1){
        low_pos=mp.find(W[i])->second;
        curr_pos=mp.find(W[i+1])->second;
        if(curr_pos<=low_pos){
            inc=1+(low_pos-curr_pos)/L[curr_pos];
            step+=inc;
            mp.find(W[i+1])->second+=L[curr_pos]*inc;
        }
        i++;
        }
        ans.push_back(step);
    }
    for(int i=0;i<track;i++){
        cout<<ans[i]<<endl;
    }
}