class Solution {
public:

    double helper(double x, long long n){
        if(n==0) return 1.0;
        double half=helper(x, (n/2));
        if(n%2!=0){
            return half*half*x;
        }
        else return half*half;
    }

    double myPow(double x, int n) {
        long long exponent=n;
        if(n<0){
            return 1.0/(helper(x, -exponent));
        }
        return helper(x, exponent);
    }
};