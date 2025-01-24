#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        if (numRows == 0) return result;

        // Start with the first row
        result.push_back(vector<int>(1, 1));

        for (int i = 1; i < numRows; i++) {
            vector<int> newRow(i + 1, 1); // Create a row with all elements as 1
            for (int j = 1; j < i; j++) {
                newRow[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(newRow);
        }

        return result;
    }
};

int main() {
    Solution solution;
    int numRows;

    // Input the number of rows for Pascal's Triangle
    cout << "Enter the number of rows for Pascal's Triangle: ";
    cin >> numRows;

    // Generate Pascal's Triangle
    vector<vector<int> > pascalsTriangle = solution.generate(numRows);

    // Output the Pascal's Triangle
    cout << "Pascal's Triangle with " << numRows << " rows:" << endl;
    for (size_t i = 0; i < pascalsTriangle.size(); i++) {
        for (size_t j = 0; j < pascalsTriangle[i].size(); j++) {
            cout << pascalsTriangle[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}