class Solution {
public:
    long long merge(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        long long cnt = 0;

        vector<int> L(n1), R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0;

        // count reverse pairs
        while (i < n1 && j < n2) {
            if ((long long)L[i] > 2LL * R[j]) {
                cnt += (n1 - i);
                j++;
            } else {
                i++;
            }
        }

        // merge step
        i = 0; 
        j = 0;
        int k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }

        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];

        return cnt;
    }

    long long mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        long long cnt = 0;

        cnt += mergeSort(arr, left, mid);
        cnt += mergeSort(arr, mid + 1, right);
        cnt += merge(arr, left, mid, right);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return (int)mergeSort(nums, 0, nums.size() - 1);
    }
};
