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

typedef pair<int, int> pii;

const int size = 27;

static unordered_map<char, int> mapping;

static vector<vector<int> > v(size);
static unordered_map<int, int> task_weights;
static vector<int> top_sort;
static vector<int> dfs_num(size, 0);
static set<int> nodes;
static vector<int> distances(size, 0);

static void generate_mapping()
{
	int counter = 0;
	for (char c = 'A'; c <= 'Z'; c++)
	{
		mapping[c] = counter;
		++counter;
	}
}

static void dfs(int start)
{
	dfs_num[start] = 1;
	vector<int> neighbours = v[start];
	for (auto &neigh : neighbours)
	{
		if (dfs_num[neigh] == 0)
		{
			dfs(neigh);
		}
	}
	top_sort.emplace_back(start);
}

int main()
{
	ios::sync_with_stdio(false);
	int flag = 0;
	generate_mapping();
	string _cases("");
	getline(cin, _cases);
	int cases = stoi(_cases);
	string blank("");
	getline(cin, blank);
	for (int cas = 0; cas < cases; cas++)
	{
		if (flag == 1)
		{
			cout << endl;
		}
		flag = 1;
		v.clear();
		task_weights.clear();
		top_sort.clear();
		dfs_num.clear();
		nodes.clear();
		distances.clear();
		v.resize(size);
		dfs_num.resize(size, 0);
		distances.resize(size, 0);
		while (true)
		{
			string line("");
			getline(cin, line);
			if (line.compare("") == 0 || line.compare(" ") == 0)	break;
			stringstream ss(line);
			vector<string> tokens;
			string token("");
			while (ss >> token)
			{
				tokens.emplace_back(token);
			}

			if (tokens.size() == 2)
			{
				char task = tokens[0][0];
				int task_weight = stoi(tokens[1]);
				task_weights[mapping[task]] = -task_weight;
				// all those nodes with in-degree 0 should be initialized with their weight
				// that's because we will never be able to reach them while doing relaxation.
				// not doing it will be a problem if they are the starting nodes in topological ordering
				distances[mapping[task]] = -task_weight;
				nodes.insert(mapping[task]);
			}
			else if (tokens.size() == 3)
			{
				char task = tokens[0][0];
				int task_weight = stoi(tokens[1]);
				task_weights[mapping[task]] = -task_weight;
				nodes.insert(mapping[task]);
				for (size_t q = 0; q < tokens[2].length(); q++)
				{
					char edge = tokens[2][q];
					int _mapping = mapping[edge];
					v[_mapping].emplace_back(mapping[task]);
					nodes.insert(_mapping);
				}
			}
		}
		for (auto n : nodes)
		{
			if (dfs_num[n] == 0)
			{
				dfs(n);
			}
		}
		reverse(top_sort.begin(), top_sort.end());
		
		for (size_t i = 0; i < top_sort.size(); i++)
		{
			int v_in = top_sort[i];
			for (size_t j = 0; j < v[v_in].size(); j++)
			{
				int v_out = v[v_in][j];
				if (distances[v_in] + task_weights[v_out] < distances[v_out])
				{
					distances[v_out] = distances[v_in] + task_weights[v_out];
				}
			}
		}
		int answer = *min_element(distances.begin(), distances.end());
		cout << -answer << endl;
	}
	return 0;
}