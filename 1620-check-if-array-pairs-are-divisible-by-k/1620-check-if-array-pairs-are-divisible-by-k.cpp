// class Solution {
// public:
//     bool canArrange(vector<int>& arr, int k) {
//         int n =  arr.size();

//         vector<int> v(n);
//         for(int i = 0; i<n; i++){
//             v[i] = ((arr[i]%k)+k)%k;   //modulo operation for negative numbers
//         }

//         unordered_map<int, int> mp;

//         for(auto& x: v){
//             mp[x]++;
//         }

//         int cnt =0 ;
//         for(int i = 0; i<n; i++){
//             int modval = v[i];

//             if(modval == 0 ){
//                 if(mp[modval] % 2 != 0) return false;
//                 cnt += mp[modval]/2;
//                 mp[modval] = 0;
//             }else{
//                 int remain = k - modval;
//                 if(mp[remain] != mp[modval]) return false;
//                   mp[remain]--;
//                   mp[v[i]]--;
                
//             }
//         }

// return cnt == n/2;
//     }
// };



class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
       vector<int> re(k, 0);

       for(auto& x: arr){
          int r = (x%k + k)%k; //hndle negative remainder
          re[r]++;
       }

        if(re[0] % 2 != 0) return false;


       for(int rmdr =  1; rmdr<=k/2; rmdr++){
        int cnn = k - rmdr;
        if(re[cnn] != re[rmdr]){
            return false;
        }
       }
       return true;
    }
};
