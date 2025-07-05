class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 2; // we compare with mid^1 (neighbor)
        
        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == nums[mid ^ 1]) {
                // mid and its pair are correctly placed
                low = mid + 1;
            } else {
                // mismatch means single element is on the left
                high = mid - 1;
            }
        }
        return nums[low];
    }
};
