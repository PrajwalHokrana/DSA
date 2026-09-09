class Solution {
public:
    long long countCommas(long long n) {
        long long commas = 0;
        long long base = 1000;
        
        while (n >= base) {
            // Add one comma for every number greater than or equal to the current base
            commas += (n - base + 1);
            
            // Prevent long long overflow (since LLONG_MAX is ~9.22 * 10^18)
            // If base is larger than 10^15, multiplying by 1000 again might overflow.
            if (base > 1000000000000000LL) {
                break;
            }
            
            base *= 1000;
        }
        
        return commas;
    }
};