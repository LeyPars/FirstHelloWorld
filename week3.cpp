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