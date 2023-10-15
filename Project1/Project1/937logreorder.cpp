#include<iostream>
#include<string>
#include <vector>
#include <algorithm>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::iterator;
using std::sort;
using std::strtok;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letters, digits;
        for (int i = 0; i < logs.size(); ++i) {
            int idx = logs[i].find(' ');

            if (isdigit(logs[i][idx + 1]))
                digits.push_back(logs[i]);
            else
                letters.push_back(logs[i]);
        }
        sort(letters.begin(), letters.end(), [](const string& a, const string& b) {
            int aSpace = a.find(' ');
            int bSpace = b.find(' ');

            string id1 = a.substr(aSpace);
            string id2 = b.substr(bSpace);
            return id1 == id2 ? a < b : id1 < id2;
            });
        vector<string>::iterator it = letters.insert(letters.end(), digits.begin(), digits.end());
        return letters;
    }
};


int main() {
    Solution s;
    vector<string> v = { "dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero" };
    v = s.reorderLogFiles(v);
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << endl;
    return 0;
}