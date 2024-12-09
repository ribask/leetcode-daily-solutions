/* 3152. Special Array II

An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that 
subarraynums[fromi..toi] is special or not.

Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.*/

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> indexes;
        vector<bool> answers;

        int flag_bef = (nums[0] % 2 == 0) ? 1 : -1;

        for (int i = 1; i < nums.size(); i++) {
            int flag_curr = (nums[i] % 2 == 0) ? 1 : -1;
            if (flag_curr == flag_bef) {
                indexes.push_back(i - 1);
                indexes.push_back(i);
            }
            flag_bef = flag_curr;
        }

        for (const auto& query : queries) {
            int from = query[0], to = query[1];
            bool is_special = true;

            for (int i = 0; i < indexes.size(); i += 2) {
                if (indexes[i] >= from && indexes[i + 1] <= to) {
                    is_special = false;
                    break;
                }
            }

            answers.push_back(is_special);
        }

        return answers;
    }
};
