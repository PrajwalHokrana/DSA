class Solution {
public:
    int firstUniqChar(string s) {
        int ans = -1;
        queue<int> q;
        unordered_map<char, int> m;
        for (int i = 0; i < s.length(); i++) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = 0;
                q.push(i);
            }
            m[s[i]]++;
        }

        while (!q.empty()) {
            if (m[s[q.front()]] > 1) {
                q.pop();
            } else {
                ans = q.front();
                return ans;
            }
        }
        return -1;
    }
};