class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>& longestVec = m > n ? nums1 : nums2;
        vector<int>& shortestVec = m > n ? nums2 : nums1;
        // Need to define a separate variable for these, we can't use .size()
        // because .size() includes the total number of elements in the array (inc. 0s which
        // are set for "spare" capacity to return the merged vecs in-place)
        int longestSize = m > n ? m : n; 
        int shortestSize = m > n ? n : m;

        vector<int> mergedVec(m + n);
        int mergedVecPointer = 0;
        int shortestVecPointer = 0;

        for(int longestVecPointer = 0; longestVecPointer < longestSize; longestVecPointer++) {
            // ?O(m + n) We don't iterate over the entire vec each time, so we should traverse each vec once.
            while(shortestVecPointer < shortestSize && shortestVec[shortestVecPointer] < longestVec[longestVecPointer]) {
                mergedVec[mergedVecPointer] = shortestVec[shortestVecPointer];
                mergedVecPointer++;
                shortestVecPointer++;
            }

            mergedVec[mergedVecPointer] = longestVec[longestVecPointer];
            mergedVecPointer++;
        }

        // Overwrite nums1 as dictated by the question
        // Can we operate in-place instead?
        for(int i = 0; i < nums1.size(); i++) {
            nums1[i] = mergedVec[i];
        }
    }
};

