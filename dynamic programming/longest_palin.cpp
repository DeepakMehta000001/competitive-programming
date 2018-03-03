//problem - https://leetcode.com/problems/longest-palindromic-substring/description/
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        if(n==0)
            return "";
        if(n==1)
            return s;
        int res=0; 
        int start=-1;
        for(int i=1;i<n;++i){
            int j=i;
            int k=i-1;
            int tempRes=0;
            while(s[j]==s[k] && j<n && k>=0){
                tempRes+=2;
                j++;
                k--;
            }
            //res=max(res,tempRes);
            if(tempRes>res){
                start=k+1;
                res=tempRes;
            }
            j=  i+1;  
            k = i-1;
            tempRes=1;
            while(s[j]==s[k] && j<n && k>=0){
                tempRes+=2;
                j++;
                k--;
            }
            if(tempRes>res){
                start=k+1;
                res=tempRes;
            }
        }

        return s.substr(start,res);
    }
};