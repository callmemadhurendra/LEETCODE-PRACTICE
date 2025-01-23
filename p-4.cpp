#include <iostream>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int ml = maxDepth(root->left);
        int mr = maxDepth(root->right);
        return max(ml, mr) + 1;
    }
};

int main() {
    // Create a simple binary tree for testing
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Create a Solution object and call maxDepth
    Solution sol;
    int depth = sol.maxDepth(root);

    cout << "The maximum depth of the binary tree is: " << depth << endl;

    // Clean up the dynamically allocated memory (optional but good practice)
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
