/*
title:Subarray Sum Equals K
description:
	Given an array of integers and an integer k, 
	you need to find the total number of continuous subarrays whose sum equals to k.
Example 1:
	Input:nums = [1,1,1], k = 2
	Output: 2
Note:
    The length of the array is in range [1, 20,000].
    The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/
int subarraySum(vector<int>& nums, int k) {
        map<int,int> ssum;
        ssum[0]=1;
        int ans=0,sum=0;
        for(auto v:nums)
        {
            sum+=v;
            if(ssum.count(sum-k)!=0) ans+=ssum[sum-k];
            ssum[sum]++;
        }
        return ans;
    }
	
/*
title:Bitwise AND of Numbers Range
description:
	Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
Example 1:
	Input: [5,7]
	Output: 4
Example 2:
	Input: [0,1]
	Output: 0
*/
//the left most common prefix of bits
int rangeBitwiseAnd(int m, int n) {
        int cnt=0;
        while(m!=n)
        {
            ++cnt;
            m>>=1;
            n>>=1;
        }
        return m<<cnt;
    }
	
int rangeBitwiseAnd(int m,int n)
{
	int mask=INT_AMX;
	while((mask&m)!=(mask&n))
	{
		mask<<=1;
	}
	return mask&m;
}