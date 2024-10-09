class Solution {
public:

string iTOs(int x){
    string bin = "";
if(x == 0) return "0" ;
   while(x>0){
        bin += (x%2 == 0 ? "0" : "1");
        x/=2;
    }

    reverse(bin.begin(), bin.end()); //imp
    return bin;
}

int sTOi(string x){
    int ans = 0;

    for(int i=0; i<x.length(); i++){
        ans = ans*2 + (x[i] - '0');
    }

    return ans;
}


    int maxGoodNumber(vector<int>& nums) {


        string a = iTOs(nums[0]);
        string b = iTOs(nums[1]);
        string c = iTOs(nums[2]);


return max({
    sTOi(a+b+c),
     sTOi(b+c+a),
      sTOi(b+a+c),
       sTOi(a+c+b),
        sTOi(c+b+a),
         sTOi(c+a+b),
});

    }
};