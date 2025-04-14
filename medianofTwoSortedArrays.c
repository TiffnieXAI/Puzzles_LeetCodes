double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    int totalSize = nums1Size + nums2Size;
    int index1 = 0, index2 = 0;
    int mergedArray[totalSize];

    // Merge the two sorted arrays into mergedArray
    for (int i = 0; i < totalSize; i++) {
        if (index1 < nums1Size && (index2 >= nums2Size || nums1[index1] <= nums2[index2])) {
            mergedArray[i] = nums1[index1];
            index1++;
        } else {
            mergedArray[i] = nums2[index2];
            index2++;
        }
    }

    // Now, find the median
    double median = 0.0;
    if (totalSize % 2 == 1) {
        // Odd total size, take the middle element
        median = mergedArray[totalSize / 2];
    } else {
        // Even total size, take the average of the two middle elements
        median = (mergedArray[totalSize / 2 - 1] + mergedArray[totalSize / 2]) / 2.0;
    }

    return median;
}
