#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};

int main() {
    Solution solution;
    
    // Alternative initialization without initializer list
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    
    int val = 3;

    int newLength = solution.removeElement(nums, val);
    cout << "New Length: " << newLength << endl;

    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " "; // Output the modified array
    }
    cout << endl;

    return 0;
}
