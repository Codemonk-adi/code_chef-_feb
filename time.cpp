#include<iostream>
#include<string>
using namespace std;
struct time{
    int hours;
    int mins;
};

struct time conv(string s){
    struct time ans;
    int i=0;
    ans.mins=10*(s[3]-48)+s[4]-48;
    ans.hours=10*(s[0]-48)+s[1]-48;
    if(s[6]=='A'){
        if(ans.hours==12){
            ans.hours=0;
        }
    }else if(s[6]=='P'){
        if(ans.hours!=12){
            ans.hours+=12;
        }
    }
    return ans;
}
struct time conv(char s[]){
    struct time ans;
    int i=0;
    ans.mins=10*(s[3]-48)+s[4]-48;
    ans.hours=10*(s[0]-48)+s[1]-48;
    if(s[6]=='A'){
        if(ans.hours==12){
            ans.hours=0;
        }
    }else if(s[6]=='P'){
        if(ans.hours!=12){
            ans.hours+=12;
        }
    }
    return ans;
}

bool operator<=(time lhs,time rhs){
    if(lhs.hours<rhs.hours){
        return true;
    }else if(lhs.hours==rhs.hours){
        if(lhs.mins<=rhs.mins)
        return true;
    }else{
        return false;
    }
    return false;
};

int main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        do{
        getline(cin,s);
        }while(s=="");
        time meet;
        time bg;
        time ed;
        meet=conv(s);
        int n;
        cin>>n;
        string ans;
        string temp;
        char beg[10];
        char end[10];
        for(int i=0;i<n;i++){
            do{
                getline(cin,temp);
            }while(temp=="");
            temp.copy(beg,8,0);
            beg[8]='\0';
            temp.copy(end,8,9);
            end[8]='\0';
            bg=conv(beg);
            ed=conv(end);
            if(meet<=ed&&bg<=meet){
                ans = ans.append("1");
            }else{
                ans = ans.append("0");
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}