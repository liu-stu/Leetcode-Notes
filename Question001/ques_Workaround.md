# 问题描述

给定一个整数数组 `nums` 和一个整数目标值 `target`，请你在该数组中找出 **和为目标值** *`target`* 的那 **两个** 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

**示例1:**

```late
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
```

**示例2：**

```late
输入：nums = [3,2,4], target = 6
输出：[1,2]
```

**示例3：**

```late
输入：nums = [3,3], target = 6
输出：[0,1]
```

**提示**

- ```la
  2 <= nums.length <= 104
  ```

- ```la
  -109 <= nums[i] <= 109
  ```

- ```la
  109 <= target <= 109
  ```

- **只会存在一个有效答案**

---



## 解题思路：

#### 方法一、暴力穷举法

用两个for循环完成。

**代码**

```c++
//暴力枚举，即用两个for循环来实现
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
```

**复杂度分析**

- 时间复杂度为 *O(N<sup>2</sup>)*，其中*N*表示数组中元素的个数，最坏情况下数组中任意两个数都要被匹配一次。
- 空间复杂度为*O(1)*，

---

#### 方法二、哈希表算法

时间复杂度为O(N)

- 解析：

**代码**

```c++
vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> hashtable;
	for (int i = 0; i < nums.size(); ++i) {
		auto it = hashtable.find(target - nums[i]);
		if (it != hashtable.end()) {
			return { it->second, i };
		}
		hashtable[nums[i]] = i;
	}
	return {};
}
```

**复杂度分析**

- 时间复杂度：*O(N)*，其中*N*表示数组中元素的个数
- 空间复杂度：*O(N)*，其中*N*是数组中的元素数量。主要为哈希表的开销。
