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

int main() {
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> costs(n);
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        int track = INT_MAX;
        for (int j = i - k; j < i; j++) {
            if (j >= 0) {
                int costDiff = abs(costs[i] - costs[j]);
                int totalCostAtI = dp[j] + costDiff;
                track = min(track, totalCostAtI);
            }
        }
        dp[i] = track;
    }

    cout << dp[n - 1] << endl;

    return 0;
}