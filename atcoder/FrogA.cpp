#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <limits.h>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <sstream>

using namespace std;

vector<int> split_string(const string& str) {
    stringstream ss(str);
    string token;
    vector<int> words;
    while (ss >> token) {
        words.push_back(stoi(token));
    }
    return words;
}

// https://atcoder.jp/contests/dp/tasks/dp_a

int main() {
    int n = 0;
    cin >> n;
    vector<int> costs, dp;
    for (int i = 0; i < n; i++) {
        int cost;
        cin >> cost;
        costs.push_back(cost);
        dp.push_back(0);
    }

    dp[0] = 0;
    for (int i = 1; i < int(costs.size()); i++)
    {
        int previous = INT_MAX, beforePrevious = INT_MAX;
        if (i - 1 >= 0) {
            previous = dp[i - 1] + abs(costs[i] - costs[i -1]);
        }
        if (i - 2 >= 0) {
            beforePrevious = dp[i - 2] + abs(costs[i] - costs[i - 2]);
        }

        dp[i] = min(previous, beforePrevious);
    }

    cout << dp[dp.size() - 1] << endl;

    return 0;
}