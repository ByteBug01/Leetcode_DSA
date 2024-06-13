class Solution {
public:
    int nthUglyNumber(int n) {
    vector<int> t(n+1);

    int i2,i3,i5 ;

    i2 = i3 = i5 = 1;

    t[1] = 1;

    for(int i =2; i<=n; i++){
       int i2_ugly = t[i2]*2;
       int i3_ugly = t[i3]*3;
       int i5_ugly = t[i5]*5;

       t[i] = min({i2_ugly, i3_ugly, i5_ugly});

       if(t[i] == i2_ugly){
        i2++;
       }

       if(t[i] == i3_ugly){
        i3++;
       }

       if(t[i] == i5_ugly){
        i5++;
       }
    }

       return t[n];

    }
};