/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void preorder(TreeNode* root, vector<int>& sequence)
    {
        if(root == nullptr)
        {
            sequence.push_back(200);
            return;
        }

        sequence.push_back(root->val);
        preorder(root->left, sequence);
        preorder(root->right, sequence);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> pValues, qValues;
        preorder(p, pValues);
        preorder(q, qValues);

        return pValues == qValues;
    }
};
