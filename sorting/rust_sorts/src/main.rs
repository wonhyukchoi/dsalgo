fn main() {
    return ();
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
