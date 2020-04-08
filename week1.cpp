/*
Title:
	Single Number
Description:
	Given a non-empty array of intergers,every element appears twice except for one. Find that single one.
Note:
	Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
example 1:
	Input: [2,2,1]
	Output: 1
example 2:
	Input: [4,1,2,1,2]
	Output: 4
*/

int singleNumber(vector<int>& nums)
{
	int ans=0;
	for(int v:nums) ans^=v;
	return ans;
}

/*
Title:
	Happy Number
Description:
	Write an algorithm to determine if a number n is "happy".
	A happy number is a number defined by the following process: Starting with any positive integer,
	replace the number by the sum of the squares of its digits, and repeat the process until the 
	number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. 
	Those numbers for which this process ends in 1 are happy numbers.
	Return True if n is a happy number, and False if not.
example:
	Input: 19
	Output: true
	Explanation: 
		12 + 92 = 82
		82 + 22 = 68
		62 + 82 = 100
		12 + 02 + 02 = 1
*/
bool isHappy(int n) 
{
    unordered_set<int> candi;   
    while(n!=1)
    {
        if(candi.count(n)) return false;
        candi.insert(n);
        int tmp=0;
        while(n>0)
        {
            int di = n%10;
            tmp+=(di*di);
            n/=10;
        }
        n=tmp;
    }
    return true;
}

/*
Title:
	Maximum Subarray
Description:
	Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
example :
	Input: [-2,1,-3,4,-1,2,1,-5,4],
	Output: 6
	Explanation: 
		[4,-1,2,1] has the largest sum = 6.
follow up:
	If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/
int maxSubArray(vector<int>& nums) 
{
    int ans=INT_MIN;
    int pre = 0;
    for(int i=0;i<nums.size();++i)
    {
        pre = max(pre+nums[i],nums[i]);
        ans=max(ans,pre);
    }
    return ans;
}

/*
Title:
	Move Zeroes
Description:
	Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
example :
	Input: [0,1,0,3,12]
	Output: [1,3,12,0,0]
notes:	
    1.You must do this in-place without making a copy of the array.
    2.Minimize the total number of operations.
*/
void moveZeroes(vector<int>& nums) 
{
    const int n=nums.size();
    int idx=0;
    for(int i=0;i<n;++i)
    {
        if(nums[i]!=0) swap(nums[i],nums[idx++]);
    }
}
/*
Title:
	Best Time to Buy and Sell Stock II
Description:
	Say you have an array prices for which the ith element is the price of a given stock on day i.
	Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
	(i.e., buy one and sell one share of the stock multiple times).
notes:	
    You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
example 1:
	Input: [7,1,5,3,6,4]
	Output: 7
	Explanation: 
		Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
        Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
example 2:
	Input: [1,2,3,4,5]
	Output: 4
	Explanation: 
		Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
        Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
        engaging multiple transactions at the same time. You must sell before buying again.
example 3:
	Input: [7,6,4,3,1]
	Output: 0
	Explanation: 
		In this case, no transaction is done, i.e. max profit = 0.
Constraints:	
    1 <= prices.length <= 3 * 10 ^ 4
    0 <= prices[i] <= 10 ^ 4
*/
int maxProfit(vector<int>& prices) 
{
    int ans=0;
    for(int i=1;i<prices.size();++i)
    {
        if(prices[i-1]<prices[i]) ans+=prices[i]-prices[i-1];
    }
    return ans;
}

/*
Title:
	Group Anagrams
Description:
	Given an array of strings, group anagrams together.
example :
	Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
	Output:
		[
			["ate","eat","tea"],
			["nat","tan"],
			["bat"]
		]
notes:	 
    1.All inputs will be in lowercase.
    2.The order of your output does not matter.
*/
vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    vector<vector<string>> ans;
    unordered_map<string,int> candi;
    for(int i=0;i<strs.size();++i)
    {
        string tmp = strs[i];
        sort(begin(tmp),end(tmp));
        if(!candi.count(tmp))
        {
            candi[tmp] = ans.size();
            ans.emplace_back();
        }
        ans[candi[tmp]].push_back(strs[i]);
    }
    return ans;
}

/*
Title:
	Counting Elements
Description:
	Given an integer array arr, count element x such that x + 1 is also in arr.
	If there're duplicates in arr, count them seperately.
example 1:
	Input: arr = [1,2,3]
	Output: 2
	Explanation: 1 and 2 are counted cause 2 and 3 are in arr.
example 2:
	Input: arr = [1,1,3,3,5,5,7,7]
	Output: 0
	Explanation: No numbers are counted, cause there's no 2, 4, 6, or 8 in arr.
example 3:
	Input: arr = [1,3,2,3,5,0]
	Output: 3
	Explanation: 0, 1 and 2 are counted cause 1, 2 and 3 are in arr.
example 4:
	Input: arr = [1,1,2,2]
	Output: 2
	Explanation: Two 1s are counted cause 2 is in arr.
Constraints:	   
    1 <= arr.length <= 1000
    0 <= arr[i] <= 1000
*/

int countElements(vector<int>& arr) 
{
    unordered_map<int,int> cnt;
    for(auto v:arr) cnt[v]++;
    int ans=0;
    for(auto [u,v]:cnt) if(cnt.count(u+1)) ans+=v;
    return ans;
}