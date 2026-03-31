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

    bool sameTree(TreeNode* root1, TreeNode* root2)
    {
        vector<int> Tree1, Tree2;
        preorder(root1, Tree1);
        preorder(root2, Tree2);
        return Tree1 == Tree2;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(sameTree(root, subRoot))
        {
            return true;
        }

        if(root == nullptr)
        {
            return false;
        }

        if(subRoot == nullptr)
        {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
