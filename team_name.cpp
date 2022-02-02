#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
int main(){
    int t;
    cin>>t;
    vector<int> ans;
    while(t--){
        int n;
        cin>>n;
        vector<string> funny;
        string temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            funny.push_back(temp);
        }
        char shift;
        string temp2;
        int soln=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(funny[i][0]!=funny[j][0]){
                    temp = funny[i];
                    temp2 = funny[j];
                    shift= temp[0];
                    temp[0] = temp2[0];
                    temp2[0]=shift;
                    if(temp2!=funny[i]){
                    if(find(funny.begin(),funny.end(),temp)==funny.end()&&find(funny.begin(),funny.end(),temp2)==funny.end()){
                        soln+=2;
                    }
                    }
                }
            }
        }
        ans.push_back(soln);
    }
    for(auto i=ans.begin();i!=ans.end();i++){
        cout<<*i<<endl;
    }
}
