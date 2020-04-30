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
/*
title:Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree
description:Given a binary tree where each path going from the root to any leaf form a valid sequence, 
	check if a given string is a valid sequence in such binary tree. 
	We get the given string from the concatenation of an array of integers arr and the concatenation 
	of all values of the nodes along a path results in a sequence in the given binary tree.
Example 1:
	Input: root = [0,1,0,0,1,0,null,null,1,0,0], arr = [0,1,0,1]
	Output: true
	Explanation: 
	The path 0 -> 1 -> 0 -> 1 is a valid sequence (green color in the figure). 
	Other valid sequences are: 
	0 -> 1 -> 1 -> 0 
	0 -> 0 -> 0
*/
class Solution {
public:
    int n;
    bool dfs(TreeNode* root,int idx,vector<int>& arr)
    {
        if(idx==n-1&&root!=NULL&&root->left==NULL&&root->right==NULL&&
          arr[idx]==root->val) return true;
        if(idx==n-1||root==nullptr||root->val!=arr[idx]) return false;
        return dfs(root->left,idx+1,arr)||dfs(root->right,idx+1,arr);
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        n=arr.size();
        return dfs(root,0,arr);
    }
};