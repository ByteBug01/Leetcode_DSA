class Solution {
public:
int func(int n,int &s)
{
    int cnt=0;
    for(int i=1;i<=n/2;i++)
    {
        if(n%i==0){
            s+=i;
        cnt++;}
        if(cnt>4)
        {break;}
    }
    s+=n;
     return cnt+1;
}
    int sumFourDivisors(vector<int>& nums) {
        int k=nums.size();
        int i;int ans=0;
        for(i=0;i<k;i++)
        {
            int s=0;
            if(func(nums[i],s)==4)
            ans+=s;
        }
        return ans;
    }
};