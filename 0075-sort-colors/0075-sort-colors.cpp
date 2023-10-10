class Solution {
public:
    //selection sort // TC = n^2
    void sortColors(vector<int>& a) {
//          int mini, i, j;
//     for( i = 0; i<a.size()-1; i++){
//         mini = i;
//         for( j=i+1; j<a.size(); j++){
//             if(a[j]<a[mini]){
//                 mini=j;
//             }
            
//         }
//         if(mini!=i)
//     swap(a[i], a[mini]);
        
        
//     }
        int n= a.size();
        int key;
        for(int i = 1; i<n; i++){
            key = a[i];
            int j = i-1;
            while(j>=0 && a[j]>key){
                a[j+1] = a[j];
                j--;
            }
            a[j+1]=key;
        } // Insertion Sort TC=o(n^2)
    } 
};