#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";  // If the vector is empty, no common prefix exists.
        
        // Sort the vector to bring the lexicographically smallest and largest strings together.
        sort(strs.begin(), strs.end());
        
        // Take the first and last strings from the sorted array
        string first = strs[0], last = strs.back(), result = "";
        
        // Compare characters of the first and last strings to find common prefix
        for (int i = 0; i < first.size(); i++) {
            if (i < last.size() && first[i] == last[i]) {
                result += first[i];  // Add the matching character to the result
            } else {
                break;  // If characters don't match, break the loop
            }
        }
        
        return result;  // Return the common prefix
    }
};

int main() {
    Solution solution;
    
    // Create the vector and add elements with push_back
    vector<string> strs;
    strs.push_back("flower");
    strs.push_back("flow");
    strs.push_back("flight");

    cout << "Longest Common Prefix: " << solution.longestCommonPrefix(strs) << endl;

    return 0;
}
