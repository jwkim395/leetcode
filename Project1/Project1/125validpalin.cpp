#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    bool isPalindrome(string s) {
        string converted;
        // 알파벳 변환(공백, 특수문자 제거, 다 소문자로 변환)
        for (int i = 0; i < s.size(); ++i) {
            if (isalpha(s[i]) || isdigit(s[i])) {
                if (s[i] >= 'A' && s[i] <= 'Z')
                    converted.push_back(tolower(s[i]));

                else
                    converted.push_back(tolower(s[i]));
            }
        }
        // 문자열 비교
        for (int i = 0; i < converted.size() / 2; i++) {
            if (converted[i] != converted[converted.size() - 1 - i])
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome("0P") << endl;
    return 0;
}