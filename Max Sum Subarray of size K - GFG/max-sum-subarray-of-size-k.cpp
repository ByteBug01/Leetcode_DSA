//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &Arr , int n){
        // code here 
        if(n==0 || k<=0 || k>n){
            return -1;
        }
        
       long long sum = 0; 
        for(int i=0; i<k; i++){
            sum = sum+Arr[i];
        }
        
        long long maxsum = sum;
        long long strt=0;
        
        for(int j = k; j<n; j++){
            sum = sum + Arr[j] - Arr[strt++];
            
            if(sum>maxsum){
                maxsum = sum;
            }
        }
        
        return maxsum;
        
        // int i=0,j=0;
        
        // long sum=0;
        // long ans=LLONG_MIN;
        
        // while(j<N){
        //     sum+=Arr[j];
            
        //     if((j-i+1)<K)j++;
        //     else if((j-i+1)==K){
        //         ans=max(ans,sum);
        //         sum-=Arr[i];
        //         i++;
        //         j++;
        //     }
        // }
        
        // return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends