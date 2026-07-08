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
private: 
    int max_dia = 0;
    int height_n_diameter(TreeNode* root){
        if(root == nullptr) return 0;
        int l_height = height_n_diameter(root -> left);
        int r_height = height_n_diameter(root -> right);

        int currLen = l_height + r_height;
        max_dia = max(currLen, max_dia);
        return 1 + max(l_height, r_height);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        height_n_diameter(root);
        return max_dia;
    }
};