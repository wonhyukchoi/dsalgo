function partition(nums: number[],
	low: number, 
	high: number): number {
	const pivot = nums[high];
	let smallIdx = low - 1;
	for (let idx = low; idx < high; idx++) {
		if (nums[idx] < pivot) {
			++smallIdx;
			[nums[smallIdx], nums[idx]] = [nums[idx], nums[smallIdx]];
		}
	}
	const partitionIdx = smallIdx + 1;
	[nums[partitionIdx], nums[high]] = [nums[high], nums[partitionIdx]];
	return partitionIdx;
};

function quickSort(nums: number[],
	low: number, 
	high: number) {
	if (high <= low)
		return;
	const partitionIdx = partition(nums, low, high);
	quickSort(nums, low, partitionIdx-1);
	quickSort(nums, partitionIdx+1, high);
};

function sortArray(nums: number[]): number[] {
	quickSort(nums, 0, nums.length-1);
	return nums;
};
