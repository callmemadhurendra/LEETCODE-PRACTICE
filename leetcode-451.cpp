#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;

        // Step 1: Count frequency of each character
        for (char c : s) {
            freqMap[c]++;
        }

        // Step 2: Store characters and their frequencies in a vector
        vector<pair<char, int>> freqVector;
        for (auto& entry : freqMap) {
            freqVector.push_back(entry);
        }

        // Step 3: Sort the vector based on frequency (brute force way)
        sort(freqVector.begin(), freqVector.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;  // Sorting in descending order of frequency
        });

        // Step 4: Construct the result string
        string result = "";
        for (auto& p : freqVector) {
            result.append(p.second, p.first);  // Append the character 'p.second' times
        }

        return result;
    }
};

int main() {
    Solution solution;
    string s = "tree";
    cout << "Sorted string by frequency: " << solution.frequencySort(s) << endl;
    return 0;
}