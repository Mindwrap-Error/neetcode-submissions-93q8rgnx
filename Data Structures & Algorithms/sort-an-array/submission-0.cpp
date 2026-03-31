class Solution {
public:
    void merge(vector<int>& nums, int l, int m, int r)
    {
        vector<int> L(nums.begin() + l, nums.begin() + m + 1);
        vector<int> R(nums.begin() + m + 1, nums.begin() + r + 1);
        int i = l, j = 0, k = 0;

        while(j < L.size() && k < R.size())
        {
            if(L[j] <= R[k])
            {
                nums[i] = L[j];
                j++;
            }
            else
            {
                nums[i] = R[k];
                k++;
            }
            i++;
        }

        while(j < L.size())
        {
            nums[i] = L[j];
            j++; i++;
        }

        while(k < R.size())
        {
            nums[i] = R[k];
            k++; i++;
        }
    }

    void mergeSort(vector<int>& nums, int l, int r)
    {
        if(l == r) return;

        int m = (l+r)/2;
        mergeSort(nums, l, m);
        mergeSort(nums, m+1, r);
        merge(nums, l, m, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};