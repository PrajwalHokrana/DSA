class Solution {
public:
    int GCD(int a , int b)
    {
        if(b==0) return a;

        return GCD(b, a%b);
    }
    int gcdOfOddEvenSums(int n) {
        int sumOdd=0;
        int sumEven=0;

        int eidx=2,oidx=1;
        for(int i=1;i<=n;i++)
        {
            sumOdd+=oidx;
            sumEven+=eidx;
            oidx+=2;
            eidx+=2;
        }

        return GCD(sumEven, sumOdd);
    }
};