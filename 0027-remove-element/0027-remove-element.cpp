#include <queue>
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        queue<int> found;
        int N = nums.size();
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (nums[i] == val)  {
                found.push(i);
                count++;
            } else if (found.size()) {
                nums[found.front()] = nums[i];
                found.pop();
                found.push(i);
            }
        }

        return N-count;
    }
};