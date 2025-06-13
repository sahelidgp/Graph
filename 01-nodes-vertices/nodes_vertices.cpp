// User function Template for C++
class Solution {
  public:
    long long count(int n) {
        // your code here
         long long x = n * (n - 1) / 2;

    // Function to calculate
    // (2^x) % mod
    return pow(2, x);
    }
};