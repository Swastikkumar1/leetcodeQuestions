class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> result;
        std::stack<TreeNode*> s;
        TreeNode* curr = root;

        while (curr != nullptr || !s.empty()) {
            // Reach the leftmost node of the current node
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }
            
            // Current must be NULL at this point, so we pop from stack
            curr = s.top();
            s.pop();
            
            result.push_back(curr->val); // Process node
            
            // Now visit the right subtree
            curr = curr->right;
        }
        return result;
    }
};