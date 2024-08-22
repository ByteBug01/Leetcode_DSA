import java.util.Arrays;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        //   int n = nums.length;

        // Integer[] idxArr= new Integer[n];
        
        // for (int i = 0; i < n; i++) {
        //     idxArr[i] = i;
        // }
        
        // Arrays.sort(idxArr, (a, b) -> Integer.compare(nums[a], nums[b])); //sort doesn't work with primitive types like int[] directly. Instead, it works with object types.
        // int i = 0, j = n - 1;
        // int[] ans = new int[2];
        
        // while (i < j) {
        //     int sum = nums[idxArr[i]] + nums[idxArr[j]];
        //     if (sum == target) {
        //         ans[0] = idxArr[i];
        //         ans[1] = idxArr[j];
        //         return ans;
        //     } else if (sum < target) {
        //         i++;
        //     } else {
        //         j--;
        //     }
        // }
        
        // return ans;
        
        int n = nums.length;

        Map<Integer, Integer> mp = new HashMap<>();

        for(int i = 0; i<n; i++){
            int remain = target - nums[i];
            if(mp.containsKey(remain)){
                return new int[] {mp.get(remain), i};
            }
            mp.put(nums[i], i);
        }
        return null;
    }
}