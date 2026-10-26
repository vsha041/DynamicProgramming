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
#include <limits>
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
    int n = 0, numOfActivities = 3;
    cin >> n;
    vector<vector<int>> activities(n, vector<int>(numOfActivities, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < numOfActivities; ++j)
        {
            cin >> activities[i][j];
        }
    }

    for (int i = 1; i < n; ++i)
    {
        vector<int> dayOptions(numOfActivities, 0);
        for (int j = 0; j < numOfActivities; ++j)
        {
            int current = activities[i][j];
            int find_max = INT_MIN;
            for (int k = 0; k < numOfActivities; ++k)
            {
                if (k != j)
                {
                    find_max = max(activities[i - 1][k], find_max);
                }
            }

            dayOptions[j] = find_max + current;
        }
        activities[i] = dayOptions;
    }
    int maxPoints = *max_element(activities[n-1].begin(), activities[n-1].end());
    cout << maxPoints << endl;
    return 0;
}