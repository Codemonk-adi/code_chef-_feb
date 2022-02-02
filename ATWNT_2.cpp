#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// int undone(vector<int>::iterator beg,vector<int>::iterator end,int begin,int weight){
//     int left=0;
//     int cnt=count(beg,end,begin);
//     if(cnt==0){
//         return 0;
//     }else if(weight%cnt!=0){
//         return weight;
//     }else{
//         vector<int>::iterator temp=beg;
//         for(int i=0;i<cnt;i++){
//             temp=find(temp,end,begin);
//             int p=temp-beg+2;
//             left+=undone(temp,end,p,weight/cnt);
//             temp++;
//         }
//         return left;
//     }
// };
struct node{
    vector<node*> child;
};

node *newnode(){
    node* temp=new node;
    return temp;
};
int undone(node *root, int weight){
    int left=0;
    int cnt=root->child.size();
    if(cnt==0){
        return 0;
    }else if(weight%cnt!=0){
        return weight;
    }else{
        for(int i=0;i<cnt;i++){
            node *temp=root->child[i];
            left+=undone(temp,weight/cnt);
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
    node **root=new node*[n];

    for(int i=0;i<n;i++)
    root[i]=newnode();

    vector<int>::iterator itr;
    int i=1;
    itr=array.begin();
    while(itr!=array.end()){
        root[(*itr)-1]->child.push_back(root[i]);
        itr++;
        i++;
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int begin;
        int weight;
        cin>>begin>>weight;
        int left = undone(root[begin-1],weight);
        cout<<left;
    }
    for(int i=0;i<n;i++){
        delete root[i];
    }
}