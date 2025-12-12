class Solution {
    public:
    
        void applyMention(vector<int> &mentions,vector<int> &offline,vector<string>& event){
            int timestamp= stoi(event[1]);
    
            vector<string> ids;
    
            stringstream ss(event[2]);
            string token;
    
            while(ss >> token){
                ids.push_back(token);
            }
    
            for(string id: ids){
                if(id=="ALL"){
                    for(int i=0;i<mentions.size();i++){
                        mentions[i]++;
                    }
                }
                else if(id=="HERE"){
                    for(int i=0;i<mentions.size();i++){
                        if(offline[i]==0 || offline[i]+60<=timestamp){
                            mentions[i]++;
                        }
                    }
                }
                else{
                    mentions[stoi(id.substr(2))]++;
                }
            }
        }
    
        vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
            vector<int> mentions(numberOfUsers);
            vector<int> offline(numberOfUsers,0);
    
            auto lambda=[](auto &vec1, auto &vec2){
                int t1= stoi(vec1[1]);
                int t2= stoi(vec2[1]);
    
                if(t1==t2){
                    return vec1[0][1]>vec2[0][1];
                }
                return t1<t2;
            };
    
            sort(events.begin(),events.end(),lambda);
    
            for(auto &event: events){
                if(event[0]=="MESSAGE"){
                    applyMention(mentions,offline,event);
                }
                else{
                    int timestamp=stoi(event[1]);
                    int id=stoi(event[2]);
                    offline[id]=timestamp;
                }
            }
            return mentions;
        }
    };