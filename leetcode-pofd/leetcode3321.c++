class Solution {
    public:
    
        void removeFromSet(const pair<int,int> &p,long long &sum,
                           set<pair<int,int>> &main, set<pair<int,int>> &sec,int x){
            if(main.find(p)!=main.end()){
                sum -= 1LL * p.first * p.second;
                main.erase(p);
                if(!sec.empty()){
                    auto largest = *sec.rbegin();
                    sum += 1LL * largest.first * largest.second;
                    main.insert(largest);
                    sec.erase(largest);
                }
            }
            else{
                sec.erase(p);
            }
        }
    
        void insertInSet(const pair<int,int> &p,long long &sum,
                         set<pair<int,int>> &main, set<pair<int,int>> &sec,int x){
            if(main.size()<x || p > *main.begin()){
                sum += 1LL * p.first * p.second;
                main.insert(p);
                if(main.size() > x){
                    auto smallest = *main.begin();
                    sum -= 1LL * smallest.first * smallest.second;
                    main.erase(smallest);
                    sec.insert(smallest);
                }
            }
            else{
                sec.insert(p);
            }
        }
    
        vector<long long> findXSum(vector<int>& nums, int k, int x) {
            vector<long long> result;
            long long sum = 0;
            
            unordered_map<int,int> mpp;
            set<pair<int,int>> main;
            set<pair<int,int>> sec;
    
            int n = nums.size();
            int i = 0;
            int j=0;
    
            while(j < n){
                if(mpp[nums[j]]>0){
                    removeFromSet({mpp[nums[j]],nums[j]},sum,main,sec,x);
                }
                mpp[nums[j]]++;
                insertInSet({mpp[nums[j]],nums[j]},sum,main,sec,x);
    
                if(j-i+1 == k){
                    result.push_back(sum);
                    
                    removeFromSet({mpp[nums[i]],nums[i]},sum,main,sec,x);
                    mpp[nums[i]]--;
                    if(mpp[nums[i]]==0){
                        mpp.erase(nums[i]);
                    }
                    else{
                        insertInSet({mpp[nums[i]],nums[i]},sum,main,sec,x);
                    }
                    i++;
                }
                j++;
            }
    
            return result;
        }
    };
    