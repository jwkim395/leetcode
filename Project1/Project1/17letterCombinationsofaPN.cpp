class Solution {
public:
    vector<string> phoneDigits = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> ans;
public:
    void dfs(string digits, int num, string pn) {
        if (digits.length() == num) {
            ans.push_back(pn);
            return;
        }
        for (int i = 0; i < phoneDigits[(int)(digits[num] - '0')].length(); ++i) {
            dfs(digits, num + 1, pn + phoneDigits[(int)(digits[num] - '0')][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0)
            return ans;
        dfs(digits, 0, "");
        return ans;
    }
};