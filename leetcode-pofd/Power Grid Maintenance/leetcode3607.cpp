class Solution {
    public:
    
        void dfs(int node,int id,vector<vector<int>> &adj,vector<int> &visited,unordered_map<int,set<int>> &IdElements,vector<int> &componentId){
    
            visited[node]=1;
            componentId[node]=id;
            IdElements[id].insert(node);
    
            for(auto el:adj[node]){
                if(!visited[el]){
                    dfs(el,id,adj,visited,IdElements,componentId);
                }
            }
        }
    
        vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
            vector<vector<int>> adj(c+1);
            for(auto el: connections){
                int u=el[0];
                int v=el[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }   
    
            vector<int> visited(c+1,0);
            unordered_map<int,set<int>> IdElements;
            vector<int> componentId(c+1,0);
    
            for(int node=1;node<=c;node++){
                if(!visited[node]){
                    int id=node;
                    dfs(node,id,adj,visited,IdElements,componentId);
                }
            }  
    
            vector<int> result;
    
            for(auto query: queries){
                int type=query[0];
                int station=query[1];
    
                if(type==1){
                    int idx=componentId[station];
                    if(IdElements[idx].find(station)!=IdElements[idx].end()){
                        result.push_back(station);
                    }
                    else if(!IdElements[idx].empty()){
                        result.push_back(*IdElements[idx].begin());
                    }
                    else{
                        result.push_back(-1);
                    }
                }
                else{
                    int idx=componentId[station];
                    IdElements[idx].erase(station);
                }
            }
            return result;
        }
    };