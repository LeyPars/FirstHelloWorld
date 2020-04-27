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
/*
title:LRU
*/
class LRUCache {
public:
    struct ListNode
    {
        int key,val;
        ListNode* prv,*nxt;
        ListNode(int k,int v):key(k),val(v),prv(NULL),nxt(NULL){}
    };
    int cap,si;
    ListNode* head,*end;
    unordered_map<int,ListNode*> ma;
    
    void link(ListNode* l,ListNode* r)
    {
        l->nxt=r;
        r->prv=l;
    }
    void print()
    {
        for(ListNode* cur=head;cur!=end;cur=cur->nxt)
        {
            cout<<cur->val<<"->";
        }
        cout<<endl;
    }
    LRUCache(int capacity) {
        cap=capacity;si=0;
        head = new ListNode(0,0);
        end = new ListNode(0,0);
        link(head,end);
    }
    
    int get(int key) {
        //print();
        if(ma.count(key)==0) return -1;
        ListNode* cur = ma[key];
        link(cur->prv,cur->nxt);
        link(cur,head->nxt);
        link(head,cur);
        return cur->val;
    }
    
    void put(int key, int value) {
        if(ma.count(key))
        {
            get(key);
            ma[key]->val=value;
            return;
        }
        //print();
        if(si+1>cap)
        {
            //先删除尾结点
            ListNode* de = end->prv;
            link(de->prv,end);
            ma.erase(de->key);
            delete de;
            si--;
        }
        si++;
        ListNode* cur = new ListNode(key,value);
        link(cur,head->nxt);
        link(head,cur);
        ma.insert({key,cur});
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 
 /*
 title:Jump Game
 description:
	Given an array of non-negative integers, you are initially positioned at the first index of the array.
	Each element in the array represents your maximum jump length at that position.
	Determine if you are able to reach the last index.
Example 1:
	Input: [2,3,1,1,4]
	Output: true
	Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:
	Input: [3,2,1,0,4]
	Output: false
	Explanation: You will always arrive at index 3 no matter what. Its maximum
        jump length is 0, which makes it impossible to reach the last index.
 */
 bool canJump(vector<int>& nums) {
        const int n=nums.size();
        int cur=0,nxt=0,ans=0;
        for(int i=0;i<n;++i)
        {
            if(cur<i)
            {
                ++ans;
                if(nxt<i) return false;
                cur=nxt;
            }
            nxt=max(nxt,i+nums[i]);
        }
        return true;
    }
/*
title:longest common subsequence
description:
	Given two strings text1 and text2, return the length of their longest common subsequence.
	A subsequence of a string is a new string generated from the original string with some characters(can be none) 
	deleted without changing the relative order of the remaining characters. (eg, "ace" is a subsequence of "abcde"
	while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.
	If there is no common subsequence, return 0.
Example 1:
	Input: text1 = "abcde", text2 = "ace" 
	Output: 3  
	Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:
	Input: text1 = "abc", text2 = "abc"
	Output: 3
	Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:
	Input: text1 = "abc", text2 = "def"
	Output: 0
	Explanation: There is no such common subsequence, so the result is 0.
Constraints:

    1 <= text1.length <= 1000
    1 <= text2.length <= 1000
    The input strings consist of lowercase English characters only.
*/
int longestCommonSubsequence(string text1, string text2) {
        const int m=text1.size();
        const int n=text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
        return dp[m][n];
    }
	
/*
title: Maximal Square
description:Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
Example:
	Input: 
		1 0 1 0 0
		1 0 1 1 1
		1 1 1 1 1
		1 0 0 1 0
	Output: 4
*/
int maximalSquare(vector<vector<char>>& matrix) {
        const int m=matrix.size();
        if(m==0) return 0;
        const int n=matrix[0].size();
        if(n==0) return 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        int edge = 0;
        for(int i=0;i<m;++i) for(int j=0;j<n;++j)
        {
            if(matrix[i][j]=='0') continue;
            dp[i+1][j+1]=1+min({dp[i][j+1],dp[i+1][j],dp[i][j]});
            edge = max(edge,dp[i+1][j+1]);
        }
        return edge*edge;
    }





