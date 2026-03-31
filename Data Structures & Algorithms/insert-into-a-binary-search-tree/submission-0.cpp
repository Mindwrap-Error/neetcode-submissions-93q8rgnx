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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* x = root; TreeNode* y = nullptr;
        while(x != nullptr)
        {
            y = x;
            if(x->val > val)
            {
                x = x->left;
            }
            else
            {
                x = x->right;
            }
        }

        if(y == nullptr)
        {
            return new TreeNode(val);
        }

        if(y->val > val)
        {
            y->left = new TreeNode(val);
        }
        else
        {
            y->right = new TreeNode(val);
        }

        return root;
    }
};