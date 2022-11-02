vector<int> twoSum(vector<int>& nums, int target) {
	int length = nums.size();
	vector<int> result;
	vector<int>::iterator be = nums.begin();
	int i = 0; int j;
	bool isBreakLoop = true;

	for (; i < length && isBreakLoop; i++) {
		for (j = i + 1; j < length && isBreakLoop; j++)
			if (*(be + i) + *(be + j) == target)
				isBreakLoop = false;
	}
	result.push_back(--i);
	result.push_back(--j);
	
	return result;
}
