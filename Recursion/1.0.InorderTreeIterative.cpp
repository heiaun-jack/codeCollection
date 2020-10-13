//#include <stdio.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>

using namespace std;

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    // from https://leetcode-cn.com/problems/binary-tree-inorder-traversal/ 
    
    // Translate recursive format into iterative format
    /* 
        There are two Start Points from perspective of while-loop 
     
            inorder(node->left)     -- (1) cur nullptr;
            action();               -- (2) cur not nullptr;
            inorder(node->right)    -- (3) return (meainngless)

        There are two kinds of Loop Pre-points 
            
            (3)->(2)
            (4)->(1)

        Backtrace Path: when a node finished  

            father of right
                direct dependency
            father of left
                indirect dependency - left^* right


    */
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;

        stack<TreeNode*> s;
        auto cur = root;
        while(!s.empty() || cur){
            if(cur){
                s.push(cur);    //Dependency Order
                cur = cur->left; //Base case 1: when left ready, it father node 
                continue;
            }
            //cur is nullptr;

            if(!cur){
                cur = s.top();s.pop();
                res.push_back(cur->val);
            }
                
            if(cur->right){
                cur = cur->right; // (3)
            }else{
                cur = nullptr; // (4) Base Case 2: when right ready, its father tree is ready  
            }
        }

        return res;

    }

     vector<int> inorderTraversal_refined(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ret;
        while(root || !st.empty()){
            if(root){
                st.push(root);
                root = root->left;
            }else{
                auto x = st.top();
                st.pop();
                ret.push_back(x->val);
                root = x->right;
            }
        }

        return ret;
    }
};

int main(int argc, char** argv)
{
    Solution s;
    s.inorderTraversal(nullptr);
    return 0;
}
