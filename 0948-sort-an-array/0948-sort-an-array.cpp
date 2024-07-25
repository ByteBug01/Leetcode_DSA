
class Solution {
public:
    void merge(vector<int>& nums, int l, int mid, int h) {
        int n1 = mid - l + 1;
        int n2 = h - mid;

       vector<int> left(n1), right(n2);

        for (int i = 0; i < n1; i++) {
            left[i] = nums[l + i];
        }

        for (int i = 0; i < n2; i++) {
            right[i] = nums[mid + 1 + i];
        }

        int p1 = 0, p2 = 0, ii = l;

        while (p1 < n1 && p2 < n2) {
            if (left[p1] <= right[p2]) {
                nums[ii] = left[p1++];
            } else {
                nums[ii] = right[p2++];
            }
            ii++;
        }

        while (p1 < n1) {
            nums[ii++] = left[p1++];
        }

        while (p2 < n2) {
            nums[ii++] = right[p2++];
        }
    }

    void mergeSort(vector<int>& nums, int l, int h) {
        if (l >= h) return;

        int mid = l + (h - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, h);

        merge(nums, l, mid, h);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
