#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(int x,int y){
    return y<x;
}
class Solution {
  
public:
     
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> m;
        vector<int> temp,res;
        for(int i=0;i<mat.size();i++){
            int ctr=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1)
                    ctr++;
            }
            m.push_back({i,ctr});
        }
        std::sort(m.begin(), m.end(), this->sortbysec); 
        for (int i=0; i<m.size(); i++) 
        { 
            cout << m[i].first << " "
                 << m[i].second << endl; 
        } 
        return res;
    };
    
    
      bool sortbysec(const pair<int,int> a,const pair<int,int> b){
        return (a.second < b.second);         
    };
};
int main(){
    vector<vector<int>> g={{1,1,0,0},{1,0,0,0},{1,1,1,1},{0,0,0,0}};
    Solution a;
    for(int i :a.kWeakestRows(g,3))
    cout<<i;
    return 0;
}