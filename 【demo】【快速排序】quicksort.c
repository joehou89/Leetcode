int partitional(vector<int>& nums, int low, int high)
    {
        int mid = nums[low];
        while (low < high)
        {
            while (low < high && nums[high] >= mid)
            {
                high--;
            }
            nums[low] = nums[high];
            while (low < high && nums[low] <= mid)
            {
                low++;
            }
            nums[high] = nums[low];
        }
        nums[low] = mid;
        return low;
    }

    void quick_sort(vector<int>& nums, int low, int high)
    {
        if (low < high)
        {
            int mid = partitional(nums, low, high);
            quick_sort(nums, low, mid - 1);
            quick_sort(nums, mid + 1, high);
        }
        return;
    }
