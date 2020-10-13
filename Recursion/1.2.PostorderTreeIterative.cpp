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
    vector<int> postorderTraversal(TreeNode* root) {
        list<int> res;

        stack<TreeNode*> s;
        auto cur = root;
        while(!s.empty() || cur){
            if(cur){
                //cur is nullptr;
                res.push_front(cur->val);

                s.push(cur);

                if(cur->right){
                    cur = cur->right;
                    continue;
                }

            }

            cur = s.top(); s.pop();

            if(cur->left){
                cur = cur->left;
            }else{
                cur = nullptr;
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};

int main(int argc, char** argv)
{
    Solution s;
    s.postorderTraversal(nullptr);
    return 0;
}
