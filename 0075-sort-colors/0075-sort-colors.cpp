class Solution {
public:
    void sortColors(vector<int>& a) {
         int mini, i, j;
    for( i = 0; i<a.size()-1; i++){
        mini = i;
        for( j=i+1; j<a.size(); j++){
            if(a[j]<a[mini]){
                mini=j;
            }
            
        }
        if(mini!=i)
    swap(a[i], a[mini]);
    }
    }
};