#include<iostream>
#include<string>
#include <vector>
#include <algorithm>
#include <map>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::iterator;
using std::sort;
using std::strtok;
using std::map;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> sorted;
        for (int i = 0; i < strs.size(); ++i) {
            string word = strs[i];
            sort(word.begin(), word.end());
            sorted[word].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        map<string, vector<string>>::iterator it;
        for (it = sorted.begin(); it != sorted.end(); ++it)
            ans.push_back(it->second);
        return ans;
        
    }
};


int main() {
    Solution s;
    vector<string> v = { "eat","tea","tan","ate","nat","bat" };
    vector<vector<string>>answer = s.groupAnagrams(v);
    for (int i = 0; i < answer.size(); ++i)
        for(int j = 0; j < answer[i].size(); ++j)
            cout << answer[i][j] << endl;
    return 0;
}