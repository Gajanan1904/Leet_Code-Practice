class Solution {
public:
    vector<string> ans;
    vector<string> mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void solve(string &digits,int i,string &curr){
        if(i==digits.size()){
            ans.push_back(curr);
            return;
        }

        string s=mp[digits[i]-'0'];

        for(char c:s){
            curr.push_back(c);
            solve(digits,i+1,curr);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        string curr="";
        solve(digits,0,curr);
        return ans;
    }
};