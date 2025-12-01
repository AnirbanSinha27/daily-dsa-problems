class Solution {
    public:
    
        bool check(vector<int>& batteries,long long mid,int n){
            long long target=mid * n;
    
            for(int i=0;i<batteries.size();i++){
                target -= min((long long)batteries[i],mid);
    
                if(target<=0) return true;
            }
    
            return false;
        }
    
        long long maxRunTime(int n, vector<int>& batteries) {
            long long l= *min_element(batteries.begin(),batteries.end());
            long long r;
            long long sum= accumulate(batteries.begin(),batteries.end(),0LL);
            r=sum/n;
    
            long long result=0;
    
            while(l<=r){
                long long mid= l + (r-l)/2;
                if(check(batteries,mid,n)){
                    result=mid;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            return result;
        }
    };