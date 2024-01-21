#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main()
{
    int n;
    vector<pair<int, int>> schedule;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int st, end;
        cin >> st >> end;
        schedule.push_back({st, end});
    }
    sort(schedule.begin(), schedule.end(), cmp);
    
    int ans = 0;
    int end = 0;
    for(int i = 0; i < schedule.size(); ++i){
        if(schedule[i].first >= end){
            ans += 1;
            end = schedule[i].second;
        }
    }
    cout << ans;
    return 0;
}