class Solution {
public:
    //Dutch National Flag
    void sortColors(vector<int>& arr)
   {
//         int n = arr.size();
// int low = 0, mid = 0, high = n - 1; // 3 pointers

//     while (mid <= high) 
//     {
//         if (arr[mid] == 0) 
//         {
//             swap(arr[low], arr[mid]);
//             low++;
//             mid++;
//         }
//         else if (arr[mid] == 1) 
//         {
//             mid++;
//         }
//         else {
//             swap(arr[mid], arr[high]);
//             high--;
//              }



//swap method:

int i = 0; //for 0
int j  = 0; // for 1
int k  =  arr.size() - 1; // for 2
    

    while(j<= k){
        if(arr[j] == 1){
            j++;
        }else if(arr[j] == 2){
            swap(arr[j], arr[k]);
            k--;
        }
        else{//arr[j] == 0
        swap(arr[j] , arr[i]);
        i++;
        j++;
        }
    }

    
  }
};