class Solution {
public:
    int subtraceProductAndSum(int n) {
        int sum = 0, mul = 1;

        while (n > 0) {
            int num = n % 10;
            sum += num;
            mul *= num;
            num /= 10;
        }

        return mul - sum;
    }
};