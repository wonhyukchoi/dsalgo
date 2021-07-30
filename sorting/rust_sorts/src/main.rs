fn main() {
    return ();
}

// Testable by https://leetcode.com/problems/sort-an-array/
fn merge_sort(nums: &[i32]) -> Vec<i32> {
    if nums.len() == 1 {
        return nums.to_vec();
    }
    let mid_idx : usize = nums.len() / 2;
    let left = merge_sort(&nums[..mid_idx]);
    let right = merge_sort(&nums[mid_idx..]);
    immutable_merge(&left, &right)
}

fn immutable_merge(nums1: &[i32], nums2: &[i32]) -> Vec<i32>{
    let mut merged : Vec<i32> = Vec::new();
    let (mut counter1, mut counter2) = (nums1.len(), nums2.len());
    while 0 < counter1 && 0 < counter2 {
        let (elem1, elem2) = (nums1[nums1.len() - counter1], nums2[nums2.len() - counter2]);
        if elem1 < elem2 {
            merged.push(elem1);
            counter1 -= 1;
        } else {
            merged.push(elem2);
            counter2 -= 1;
        }
    }
    while 0 < counter1 {
        merged.push(nums1[nums1.len() - counter1]);
        counter1 -= 1;
    }
    while 0 < counter2 {
        merged.push(nums2[nums2.len() - counter2]);
        counter2 -= 1;
    }
    merged
}

// Testable by https://leetcode.com/problems/merge-sorted-array/
// nums1 has size m +n 
fn merge (nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n:i32) {
    let mut backwards_idx: usize = (m + n - 1) as usize;
    let (m_size, n_size) = (m as usize, n as usize);
    let (mut m_idx, mut n_idx) = ((m-1) as usize, (n-1) as usize);
    while m_idx < m_size && n_idx < n_size {
        let (nums1_elem, nums2_elem) = (nums1[m_idx], nums2[n_idx]);
        if nums2_elem <= nums1_elem {
            nums1[backwards_idx] = nums1_elem;
            m_idx = m_idx - 1;
        } else {
            nums1[backwards_idx] = nums2_elem;
            n_idx = n_idx - 1;
        }
        backwards_idx = backwards_idx - 1;
    }
    while m_idx < m_size {
        nums1[backwards_idx] = nums1[m_idx];
        m_idx = m_idx - 1;
        backwards_idx = backwards_idx - 1;
    }
    while n_idx < n_size {
        nums1[backwards_idx] = nums2[n_idx];
        n_idx = n_idx - 1;
        backwards_idx = backwards_idx - 1;
    }
}
