#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int,int> pii;
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer;

        // pair的first存放下标,second存放温度
        stack<pii> stk;
        for (int i=temperatures.size()-1;i>=0;i--) {
            int target = temperatures[i];

            while (!stk.empty()) {
                if (stk.top().second <= target) {
                    stk.pop();
                } else {
                    break;
                }
            }

            if (!stk.empty()) {
                answer[i] = stk.top().first - i;
            } else {
                answer[i] = 0;
            }

            stk.push(make_pair(i,target));
        }

        return answer;
    }
};

int main() {
    unordered_map<int,int> mp;
    mp[1] = 99;
    cout << mp.find(1)->second << endl;
    auto it = mp.find(2);
    if (it == nullptr) {
        cout << "null poniter" << endl;
    }

    return 0;
}
