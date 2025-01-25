#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector< vector<string> > groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string> > ans;

        for (size_t i = 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            ans[key].push_back(strs[i]);
        }

        vector< vector<string> > result;
        unordered_map<string, vector<string> >::iterator it;
        for (it = ans.begin(); it != ans.end(); it++) {
            result.push_back(it->second);
        }

        return result;
    }
};

int main() {
    // Input list of strings
    vector<string> strs;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");

    // Create an object of Solution class
    Solution solution;

    // Call groupAnagrams function
    vector< vector<string> > groupedAnagrams = solution.groupAnagrams(strs);

    // Print the grouped anagrams
    cout << "Grouped Anagrams: " << endl;
    for (size_t i = 0; i < groupedAnagrams.size(); i++) {
        cout << "[ ";
        for (size_t j = 0; j < groupedAnagrams[i].size(); j++) {
            cout << groupedAnagrams[i][j] << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}