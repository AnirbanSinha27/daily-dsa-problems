class Solution {
    public:
    
        unordered_map<string, bool> memo;
    
        bool solve(string curr,unordered_map<string, vector<char>>& mp,int idx,string above){
            if(curr.length()==1) return true;
    
            if (idx == 0 && memo.count(curr)) return memo[curr];
    
            if(idx== curr.length()-1) return memo[curr] = solve(above,mp,0,"");
    
            string pair = curr.substr(idx,2);
            if(mp.find(pair)==mp.end()) return false;
    
            for(auto &el:mp[pair]){
                above.push_back(el);
    
                if(solve(curr,mp,idx+1,above)) return memo[curr]= true;
                above.pop_back();
            }
            return memo[curr] =false;
        }
    
        bool pyramidTransition(string bottom, vector<string>& allowed) {
            unordered_map<string, vector<char>> mp;
    
            for(auto &el: allowed){
                mp[el.substr(0,2)].push_back(el[2]);
            }
    
            return solve(bottom,mp,0,"");
        }
    };