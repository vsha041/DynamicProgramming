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
    
    return 0;
}