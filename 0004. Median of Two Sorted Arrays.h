/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
You may assume nums1 and nums2 cannot be both empty.

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int N1 = nums1.size();
    int N2 = nums2.size();
    if (N1 < N2) return findMedianSortedArrays(nums2, nums1);	// Make sure A2 is the shorter one.
    int lo = 0, hi = N2;
    int numleft= (N1 + N2)/2;

    while (lo <= hi) {  // 如果没有=， [] [1] 跑不过
        int mid2 = (lo + hi)/2;   // Try Cut 2 
        int mid1 = numleft - mid2 ;  // Calculate Cut 1 accordingly
        //注意防止越界
        double L1 = (mid1 == 0) ? INT_MIN : nums1[mid1-1];	// Get L1, R1, L2, R2 respectively
        double L2 = (mid2 == 0) ? INT_MIN : nums2[mid2-1];
        double R1 = (mid1 == N1) ? INT_MAX : nums1[mid1];
        double R2 = (mid2 == N2) ? INT_MAX : nums2[mid2];

        if (L1 > R2) lo = mid2 + 1;		// A1's lower half is too big; need to move C1 left (C2 right)
        else if (L2 > R1) hi = mid2 ;	// A2's lower half too big; need to move C2 left.
        else{
            if((N1+N2)%2==0)
                return (max(L1,L2) + min(R1, R2)) / 2;	// Otherwise, that's the right cut.
            else
                return min(R1,R2);
        } 
    }
    return -1;
}
