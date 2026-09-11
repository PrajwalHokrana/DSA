class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int, int> m; // digit,freq
        for (int digit : digits) {
            if (m.find(digit) == m.end()) {
                m[digit] = 0;
            }
            m[digit]++;
        }

        int count = 0;

        for (int number = 100; number <= 998; number += 2) {
            int temp_freq[10];
            for (int j = 0; j < 10; j++) {
                temp_freq[j] = m[j];
            }

            int num = number;

            bool valid = true;

            for (int i = 0; i < 3; ++i) {
                int current_digit = num % 10;
                num /= 10;

                temp_freq[current_digit]--;

                if (temp_freq[current_digit] < 0) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                count++;
            }
        }

        return count;
    }
};