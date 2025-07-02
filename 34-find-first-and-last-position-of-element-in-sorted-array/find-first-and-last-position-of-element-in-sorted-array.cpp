class Solution {
public:
vector<int> searchRange(vector<int>& nums, int target) {
auto ff=lower_bound(nums.begin(), nums.end(), target);
auto ll=upper_bound(nums.begin(), nums.end(), target);
if(ff==ll)return {-1,-1};
return {int(ff-nums.begin()), int(ll-nums.begin())-1};
}
};