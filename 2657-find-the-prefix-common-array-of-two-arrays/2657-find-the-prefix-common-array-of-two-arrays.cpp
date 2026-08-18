class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n);
        vector<int> freq(n + 1, 0);
        int commonCount = 0;

        for (int i = 0; i < n; ++i) {
            // If element A[i] was already seen in B
            if (++freq[A[i]] == 2) {
                commonCount++;
            }
            // If element B[i] was already seen in A
            if (++freq[B[i]] == 2) {
                commonCount++;
            }

            ans[i] = commonCount;
        }

        return ans;
    }
};