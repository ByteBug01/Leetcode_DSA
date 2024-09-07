class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
         int n1=coordinate1[0]-'a'+1;
        int n2=coordinate2[0]-'a'+1;
        int m1=coordinate1[1]-'0'+1;
        int m2=coordinate2[1]-'0'+1;
        int f1=0,f2=0;
        if((n1+m1)%2==0){
        f1=1;}
        if((n2+m2)%2==0)
        {
            f2=1;
        }
        return f1 == f2;
    }
};