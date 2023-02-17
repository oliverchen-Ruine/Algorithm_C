#include <iostream>
#include <vector>

using std::vector;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
	int i = 0, prod = 1, ans = 0;
	for (int j = 0; j < nums.size(); ++j) {
		prod *= nums[j];
		while (i <= j && prod >= k) {
			prod /= nums[i];
			++i;
		}
		ans += j - i + 1;
	}
	return ans;
}

//void main() {
//	vector<int>nums = { 10,5,2,6 };
//	int res = numSubarrayProductLessThanK(nums, 100);
//	std::cout << res << std::endl;
//}