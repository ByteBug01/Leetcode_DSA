class Solution {
    public void rotate(int[] nums, int k) {
        int n  = nums.length;
       // ArrayList[] v = new ArrayList<> ();
         
         int[] v = new int[n];
         
         k = k % n;
        for(int i = 0; i<n; i++){
            v[(i+k) % n] = nums[i];
        }

        for(int i =0; i<n; i++){
            nums[i] = v[i];
        }

    }
}