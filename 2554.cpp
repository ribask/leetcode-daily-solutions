/* 2554. Maximum Number of Integers to Choose From a Range I

You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:

The chosen integers have to be in the range [1, n].
Each integer can be chosen at most once.
The chosen integers should not be in the array banned.
The sum of the chosen integers should not exceed maxSum.
Return the maximum number of integers you can choose following the mentioned rules. */

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        std::vector<int> diff;
        std::vector<int> full;
        for (int i = 1; i <= n; i++) {
            full.push_back(i);
        }

        sort(banned.begin(), banned.end());

        std::set_difference(
            full.begin(), full.end(),
            banned.begin(), banned.end(),
            std::back_inserter(diff));

        int i = 0;
        int sum = 0;

        while(i < diff.size()) {
            if((sum + diff[i]) <= maxSum) {
                sum += diff[i];
                i++;
            } else {
                break;
            }
        }
        return i;
    }
};
