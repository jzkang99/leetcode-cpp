#include <stdlib.h>
#include "TreeNode.cpp"

class q226 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;

        TreeNode* leftNode = invertTree(root->left);
        TreeNode* rightNode = invertTree(root->right);

        root->left = rightNode;
        root->right = leftNode;
        return root;
    }
};