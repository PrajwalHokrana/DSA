class Solution {
public:
    int mirrorDistance(int n) {
        int rev=0,num=n;
        while(n>0)
        {
            int rem=n%10;
            rev= (rev*10 +rem);
            n/=10;
        }

        return abs(rev-num);
    }
};