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
    int height(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return 1 + max(height(root->left), height(root->right));
    }
    bool SolutionDFS(TreeNode* root, TreeNode* subRoot){
        if(!subRoot && !root){
            return true;
        }
        
        if(root && subRoot && root->val == subRoot->val ){
            return SolutionDFS(root->left,subRoot->left) && SolutionDFS(root->right,subRoot->right);
        }
        else{
            return false;
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr){
            return false;
        }
        if(subRoot == nullptr){
            return true;
        }
        if(SolutionDFS(root,subRoot)){
            return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};
