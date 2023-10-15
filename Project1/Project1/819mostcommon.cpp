#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>


using std::string;
using std::vector;
using std::strcpy;
using std::stringstream;
using std::getline;
using std::map;
using std::transform;
using std::find;
using std::make_pair;
using std::replace;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        vector<string> words;
        map<string, int> wordsCnt;
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), [](unsigned char c) { return tolower(c); });
        replace(paragraph.begin(), paragraph.end(), '!', ' ');
        replace(paragraph.begin(), paragraph.end(), '?', ' ');
        replace(paragraph.begin(), paragraph.end(), '\'', ' ');
        replace(paragraph.begin(), paragraph.end(), ';', ' ');
        replace(paragraph.begin(), paragraph.end(), ',', ' ');
        replace(paragraph.begin(), paragraph.end(), '.', ' ');
        stringstream ss(paragraph);

        string word;
        while (getline(ss, word, ' '))
            words.push_back(word);
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == "")
                continue;
            if (find(banned.begin(), banned.end(), words[i]) == banned.end()) {
                if (wordsCnt.find(words[i]) != wordsCnt.end())
                    ++wordsCnt[words[i]];
                else
                    wordsCnt.insert(make_pair(words[i], 1));
            }
        }
        map<string, int>::iterator it = wordsCnt.begin();
        int maxi = 0;
        string answer;
        for (; it != wordsCnt.end(); ++it) {
            if (maxi < it->second) {
                maxi = it->second;
                answer = it->first;
            }
        }
        return answer;
    }
};

int main() {
    Solution s;
    vector<string> v = { "a" };
    std::cout << s.mostCommonWord("a, a, a, a, b,b,b,c, c", v);
    return 0;
}