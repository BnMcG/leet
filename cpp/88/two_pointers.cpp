class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums1Pointer = 0;
        int nums2Pointer = 0;

        // Do nothing if nums2 is 0 sized
        // O(1)
        if(n == 0) {
            return;
        }

        // Overwrite nums1 with nums2, if
        // nums1 is 0 sized (ie: there's no comparisons to make)
        // O(n)
        if(m == 0) {
            for(int i = 0; i < n; i++) {
                nums1[i] = nums2[i];
            }
            
            return;
        }
        
        // O(m + n)
        while(nums1Pointer < nums1.size()) {
            // We've finished merging if we've exhausted nums2
            if(!(nums2Pointer < n)) {
                break;
            }

            int nums1Val = nums1[nums1Pointer];
            int nums2Val = nums2[nums2Pointer];

            bool insertingIntoBuffer = true;
            for(int i = nums1Pointer; i < nums1.size(); i++) {
                if(nums1[i] != 0) {
                    insertingIntoBuffer = false;
                    break;
                }
            }

            if(nums2Val < nums1Val || insertingIntoBuffer) {
                // Shift nums1 values right by 1 place
                for(int i = nums1.size() - 1; i > nums1Pointer; i--) {
                    nums1[i] = nums1[i-1];
                }

                // Replace old nums1 value with nums2Value
                nums1[nums1Pointer] = nums2Val;
                nums2Pointer++;
            }

            nums1Pointer++;
        }
    }
};

