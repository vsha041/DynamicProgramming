#include <iostream>
#include <string>
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
    string line("");
    while (getline(cin, line)) {
        vector<int> tokens = split_string(line);
        int counter = 0;
        int n = tokens[0];
        int k = tokens[1];

        while (true) {
            n = n - k + 1;
            if (n <= 0) {
                cout << tokens[0] + counter << endl;
                break;
            }
            else {
                ++counter;
            }
        }
    }
    return 0;
}