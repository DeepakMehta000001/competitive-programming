//Problem - https://leetcode.com/problems/word-break/description/
//Nature -  DFS 
class Solution {
public:
   bool ok(map<int,vector<int> > pos,int i,int last){
    //cout<<"Am I hit?"<<endl;
    if(pos[i].size()==0)
            return false;

    stack<int> g;
    bool dp[last+1];
    memset(dp,false,sizeof(dp));
    for(int k=0;k<pos[i].size();++k){
            g.push(pos[i][k]+1);
    }
    while(!g.empty()){
        int top = g.top();
        g.pop();
         if(dp[top-1])
            continue;
        //cout<<"check "<<top<<endl;
        
        dp[top-1]=true;
        for(int k=0;k<pos[top].size();++k){
            g.push(pos[top][k]+1);
        }
    }
    return dp[last];
    }

    bool wordBreak(string s, vector<string> &wordDict) {
        if(wordDict.size()==0)
                return false;
        map<string,bool> has;
        map<int,vector<int> > pos;
        int n = (int)wordDict.size();
        for(int i=0;i<n;++i){
            has[wordDict[i]]=true;
        }

        for(int i=0;i<s.length();++i){
            for(int j=1;i+j-1<s.length();++j){
                if(has[s.substr(i,j)]){
                    pos[i].push_back(i+j-1);
                }
            }
        }

    /*
        map<int,vector<int> >::iterator it;
        for(it=pos.begin();it!=pos.end();++it){

    }*/


        if(ok(pos,0,s.length()-1))
            return true;
        else
            return false;

    }
};