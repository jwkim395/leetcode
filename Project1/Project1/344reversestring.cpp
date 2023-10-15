#include<iostream>
#include<string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::iterator;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int siz = s.size();
        for (int i = 0; i < siz / 2; ++i) {
            char temp = s[i];
            s[i] = s[siz - 1 - i];
            s[siz - 1 - i] = temp;
        }
    }
};


int main() {
    Solution s;
    vector<char> v = { 'h','e','l','l','o' };
    s.reverseString(v);
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << endl;
    return 0;
}