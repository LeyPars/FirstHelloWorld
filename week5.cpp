/*
title:Binary Tree Maximum Path Sum
description:
	Given a non-empty binary tree, find the maximum path sum.
	For this problem, a path is defined as any sequence of nodes from some starting node to any node 
	in the tree along the parent-child connections. The path must contain at least one node and does 
	not need to go through the root.
Example 1:
Input: [1,2,3]

       1
      / \
     2   3
Output: 6
Example 2:
Input: [-10,9,20,null,null,15,7]
   -10
   / \
  9  20
    /  \
   15   7
Output: 42
*/
class Solution {
public:
    int dfs(TreeNode* rt,int& ans)
    {
        if(rt==NULL) return 0;
        int l=dfs(rt->left,ans),r=dfs(rt->right,ans);
        ans=max(ans,l+r+rt->val);
        return max(max(l,r)+rt->val,0);
    }
    int maxPathSum(TreeNode* root) {
        int ans=root->val;
        dfs(root,ans);
        return ans;
    }
};