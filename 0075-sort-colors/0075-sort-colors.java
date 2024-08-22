class Solution {
    public void sortColors(int[] nums) {

//--------java doesn't have built-in swap function---------
        int n = nums.length;

        int i = 0; //0
        int j = 0; //1
        int k = n-1; //2

      while(j <= k){
        if(nums[j] == 1){
            j++;
        }else if(nums[j] == 2){
            int temp = nums[j];
            nums[j] = nums[k];
            nums[k] = temp;

            k--;
        }else{
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            i++;
            j++;
        }
      }
        
    }
}