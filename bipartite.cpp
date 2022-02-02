#include<iostream>
#include<queue>
#include<vector>
using namespace std;

char invert(char a){
    if(a=='r')
        return 'b';
    else 
        return 'r';
};
struct node{
    int pos;
    char p_col;
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        char colour[100]="";
        bool visited[100]={};
        int state = 0;
        //0 = inprocess
        //1 = success;  
        //2 = failure;
        queue<node> q;
        for(int i=0;i<graph.size();i++){
            if(colour[i]==0){
                colour[i]='r';
                q.push({i,'b'});
                while(!q.empty()){
                    node curr = q.front();
                    for(auto j :graph[curr.pos]){
                            if(colour[j]==0){
                                colour[j]=curr.p_col;
                                q.push({j,invert(curr.p_col)});
                            }else if(colour[j]==invert(curr.p_col)){
                                return false;
                            }
                            
                            
                        }
                    q.pop();
                }
            }
        }
    return true;
        
    }
};
int main(){
    vector<vector<int>> g={{1,2,3},{0,2},{0,1,3},{0,2}};
    Solution a;
    cout<<a.isBipartite(g);
    return 0;
}