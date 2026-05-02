#include <limits.h>

double findMedianSortedArrays(int* nums1, int nums1size, int* nums2, int nums2size) {

    // Always binary search on smaller array
    if (nums1size > nums2size)
        return findMedianSortedArrays(nums2, nums2size, nums1, nums1size);

    int low = 0, high = nums1size;

    while (low <= high) {
        int partitionx = (low + high) / 2;
        int partitiony = (nums1size + nums2size + 1) / 2 - partitionx;

        int maxleftx = (partitionx == 0) ? INT_MIN : nums1[partitionx - 1];
        int minrightx = (partitionx == nums1size) ? INT_MAX : nums1[partitionx];

        int maxlefty = (partitiony == 0) ? INT_MIN : nums2[partitiony - 1];
        int minrighty = (partitiony == nums2size) ? INT_MAX : nums2[partitiony];

        if (maxleftx <= minrighty && maxlefty <= minrightx) {

            if ((nums1size + nums2size) % 2 == 0) {
                return ((maxleftx > maxlefty ? maxleftx : maxlefty) +
                        (minrightx < minrighty ? minrightx : minrighty)) / 2.0;
            } else {
                return (maxleftx > maxlefty ? maxleftx : maxlefty);
            }
        }
        else if (maxleftx > minrighty) {
            high = partitionx - 1;
        }
        else {
            low = partitionx + 1;
        }
    }

    return 0.0;
}