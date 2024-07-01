                            
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to perform iterative Morris
    // preorder traversal of a binary tree
    vector<int> getPreorder(TreeNode* root) {
        // Vector to store the
        // preorder traversal result
        vector<int> preorder;
        
        // Pointer to the current node,
        // starting with the root
        TreeNode* cur = root;

        // Iterate until the
        // current node becomes NULL
        while (cur != NULL) {
            // If the current node
            // has no left child
            if (cur->left == NULL) {
                // Add the value of the
                // current node to the preorder vector
                preorder.push_back(cur->val);
                
                // Move to the right child
                cur = cur->right;
            } else {
                // If the current node has a left child
                // Create a pointer to traverse to the
                // rightmost node in the left subtree
                TreeNode* prev = cur->left;
                
                // Traverse to the rightmost node in the
                // left subtree or until we find a node 
                // whose right child is not yet processed
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }
                
                // If the right child of the
                // rightmost node is NULL
                if (prev->right == NULL) {
                    // Set the right child of the
                    // rightmost node to the current node
                    prev->right = cur;
                    
                    // Move to the left child
                    cur = cur->left;
                } else {
                    // If the right child of the
                    // rightmost node is not NULL
                    // Reset the right child to NULL
                    prev->right = NULL;
                    
                    // Add the value of the
                    // current node to the preorder vector
                    preorder.push_back(cur->val);
                    
                    // Move to the right child
                    cur = cur->right;
                }
            }
        }
        
        // Return the resulting
        //preorder traversal vector
        return preorder;
    }
};


int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    Solution sol;
    
    vector<int> preorder = sol.getPreorder(root);

    cout << "Binary Tree Morris Preorder Traveral: ";
    for(int i = 0; i< preorder.size(); i++){
        cout << preorder[i] << " ";
    }
    cout << endl;

    return 0;
}
                            
                        