// Returns index of number to be searched; if DNE, returns -1.
// Easily testable using many test cases available at https://leetcode.com/problems/binary-search/
function binarySearch(nums: number[], target: number): number {
    return binarySearchHelper(nums, 0, nums.length-1, target);
};

function binarySearchHelper(nums: number[], start: number, end: number, target:number): number {
    if (end < start)
        return -1;
        
    const midIndex = Math.floor((start + end)/2);
    const midElement = nums[midIndex];
    if (midElement == target)
        return midIndex;
    else if (midElement < target)
        return binarySearchHelper(nums, midIndex+1, end, target);
    else // target < midElement
        return binarySearchHelper(nums, start, midIndex-1, target);
};