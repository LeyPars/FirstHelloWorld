/*
title:Product of Array Except Self
description:
	Given an array nums of n integers where n > 1,
	return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
Example:
	Input:  [1,2,3,4]
	Output: [24,12,8,6]
Constraint: 
	It's guaranteed that the product of the elements of any prefix or suffix of the array 
	(including the whole array) fits in a 32 bit integer.
Note: Please solve it without division and in O(n).
Follow up:
	Could you solve it with constant space complexity? 
	(The output array does not count as extra space for the purpose of space complexity analysis.)
*/
vector<int> productExceptSelf(vector<int>& nums) 
{
    const int n=nums.size();
    vector<int> ans(n,1);
    for(int i=1;i<n;++i) ans[i]=ans[i-1]*nums[i-1];
    int right=1;
    for(int i=n-1;i>=0;--i)
    {
        ans[i]*=right;
        right*=nums[i];
    }
    return ans;
}
/*
title: Valid Parenthesis String
description:
	Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:
	1.Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    2.Any right parenthesis ')' must have a corresponding left parenthesis '('.
    3.Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    4.'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
    5.An empty string is also valid.
Example 1:
	Input: "()"
	Output: True
Example 2:
	Input: "(*)"
	Output: True
Example 3:
	Input: "(*))"
	Output: True
Note:
    The string size will be in the range [1, 100].
*/
public boolean checkValidString(String s) 
{
    int lo = 0, hi = 0;
    for (char c: s.toCharArray()) {
        lo += c == '(' ? 1 : -1;
        hi += c != ')' ? 1 : -1;
        if (hi < 0) break;
        lo = Math.max(lo, 0);
    }
    return lo == 0;
}

/*
title:Number of Islands
description:
	Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
	You may assume all four edges of the grid are all surrounded by water.
Example 1:
	Input:
		11110
		11010
		11000
		00000
	Output: 1
Example 2:
	Input:
		11000
		11000
		00100
		00011
	Output: 3
*/
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
int numIslands(vector<vector<char>>& grid) {
    const int m=grid.size();
    if(m==0) return 0;
    const int n=grid[0].size();
    function<void(int,int)> dfs=[&](int x,int y)
    {
        grid[x][y]='0';
        for(int i=0;i<4;++i)
        {
            int xx=x+dx[i],yy=y+dy[i];
            if(xx<0||xx>=m||yy<0||yy>=n) continue;
            if(grid[xx][yy]=='0') continue;
            dfs(xx,yy);
        }
    };
    int ans=0;
    for(int i=0;i<m;++i) 
    {
        for(int j=0;j<n;++j)
        {
            if(grid[i][j]!='0')
            {
                ++ans;
                dfs(i,j);
            }
        }
    }
    return ans;
}

/*
title:Minimum Path Sum
decription:
	Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which 
	minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
Example:
	Input:
	[
	[1,3,1],
	[1,5,1],
	[4,2,1]
	]
	Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
int minPathSum(vector<vector<int>>& grid) 
{
    int m=grid.size();
    if(m==0) return 0;
    int n=grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
    dp[0][0]=grid[0][0];
    for(int i=0;i<m;++i) for(int j=0;j<n;++j)
    {
        if(i==0&&j==0) continue;
        if(i>0) dp[i][j]=min(dp[i][j],grid[i][j]+dp[i-1][j]);
        if(j>0) dp[i][j]=min(dp[i][j],grid[i][j]+dp[i][j-1]);
    }
    return dp[m-1][n-1];
}
/*
title:Search in Rotated Sorted Array
description:
	Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
	(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
	You are given a target value to search. If found in the array return its index, otherwise return -1.
	You may assume no duplicate exists in the array.
	Your algorithm's runtime complexity must be in the order of O(log n).
Example 1:
	Input: nums = [4,5,6,7,0,1,2], target = 0
	Output: 4
Example 2:
	Input: nums = [4,5,6,7,0,1,2], target = 3
	Output: -1
*/
int search(vector<int>& nums, int target) 
{
    const int n=nums.size();
    int l=0,r=n-1;
    while(l<=r)
    {
        int mid = (l+r)>>1;
        if(nums[mid]==target) return mid;
        if(nums[mid]<nums[r])
        {
            if(nums[mid]<target&&target<=nums[r]) l=mid+1;
            else r=mid-1;
        }
        else
        {
            if(nums[l]<=target&&target<nums[mid]) r=mid-1;
            else l=mid+1;
        }
    }
    return -1;
}
/*
title:Construct Binary Search Tree from Preorder Traversal
description:
	Return the root node of a binary search tree that matches the given preorder traversal.
	(Recall that a binary search tree is a binary tree where for every node, any descendant of 
	node.left has a value < node.val, and any descendant of node.right has a value > node.val. 
	Also recall that a preorder traversal displays the value of the node first, then traverses 
	node.left, then traverses node.right.)
Example 1:
	Input: [8,5,1,7,10,12]
	Output: [8,5,10,1,7,null,12]
Note: 
    1 <= preorder.length <= 100
    The values of preorder are distinct.
*/
TreeNode* build(vector<int>& arr,int l,int r)
{
    if(l>r) return NULL;
    if(l==r) return new TreeNode(arr[l]);
    TreeNode* cur = new TreeNode(arr[l]);
    int edge;
    for(int i=l+1;i<=r;++i)
    {
        if(arr[i]>arr[l])
        {
            edge=i;
            break;
        }
    }
    cur->left=build(arr,l+1,edge-1);
    cur->right=build(arr,edge,r);
    return cur;
}
TreeNode* bstFromPreorder(vector<int>& preorder) 
{
    return build(preorder,0,preorder.size()-1);
}

/*
title:Leftmost Column with at Least a One
description:(This problem is an interactive problem.)
	A binary matrix means that all elements are 0 or 1. 
	For each individual row of the matrix, this row is sorted in non-decreasing order.
	Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed)
	with at least a 1 in it. If such index doesn't exist, return -1.You can't access the 
	Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:
		BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y) (0-indexed).
		BinaryMatrix.dimensions() returns a list of 2 elements [n, m], which means the matrix is n * m.
	Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  
	Also, any solutions that attempt to circumvent the judge will result in disqualification.
	For custom testing purposes you're given the binary matrix mat as input in the following four 
	examples. You will not have access the binary matrix directly.
Example 1:
	Input: mat = [[0,0],[1,1]]
	Output: 0
Example 2:
	Input: mat = [[0,0],[0,1]]
	Output: 1
Example 3:
	Input: mat = [[0,0],[0,0]]
	Output: -1
Example 4:
	Input: mat = [[0,0,0,1],[0,0,1,1],[0,1,1,1]]
	Output: 1

Constraints:
    1 <= mat.length, mat[i].length <= 100
    mat[i][j] is either 0 or 1.
    mat[i] is sorted in a non-decreasing way.	
*/
//hint 1:(Binary Search) For each row do a binary search to find the leftmost one on that row and update the answer.
//hint 2:(Optimal Approach) Imagine there is a pointer p(x, y) starting from top right corner. 
//p can only move left or down. If the value at p is 0, move down. If the value at p is 1, move left. Try to figure 
//out the correctness and time complexity of this algorithm.
class Solution {
public:
    int helper(BinaryMatrix &binaryMatrix,int l,int r,int row)
    {
        int mid;
        while(l<=r)
        {
            mid = (l+r)>>1;
            if(binaryMatrix.get(row,mid)==1) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> si=binaryMatrix.dimensions();
        int m=si[0],n=si[1];
        int ans=-1;
        for(int i=0;i<m;++i)
        {
            int spot = helper(binaryMatrix,0,n-1,i);
            if(spot!=n&&(ans==-1||spot<ans)) ans=spot;
            //cout<<spot<<" "<<ans<<endl;
        }
        return ans;
    }
};

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> si=binaryMatrix.dimensions();
        int m=si[0],n=si[1];
        int x=0,y=n-1,ans=-1;
        while(x<m&&y>=0)
        {
            if(binaryMatrix.get(x,y)==1)
            {
                ans=y;
                --y;
            }
            else
            {
                ++x;
            }
        }
        return ans;
    }
};