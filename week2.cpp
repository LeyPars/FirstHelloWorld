/*
title:
	Middle of the Linked List
decripition:
	Given a non-empty,singly linked list with head node head,return a middle node of linked list
	If there are two middle nodes, return the second middle node.
example 1:
	Input:[1,2,3,4,5]
	output: Node 3 from this list (Serialization: [3,4,5])
	Explanation:
		The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
		Note that we returned a ListNode object ans, such that:
		ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
example 2:
	Input:[1,2,3,4,5,6]
	output: Node 4 from this list (Serialization: [4,5,6])
	Explanation:
		Since the list has two middle nodes with values 3 and 4, we return the second one.
Note:
    The number of nodes in the given list will be between 1 and 100.
*/
ListNode* middleNode(ListNode* head) 
{
    ListNode* slow = head,*fast = head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/*
title:Backspace String Compare
description:Given two string S and T,return if they are equal when both are typed into empty text editors.# means a backspace character.
Example 1:
	Input:S="ab#c",T="ad#c"
	Output: true
	Explanation:Both S and T become "ac".
Note:
	1. 1<=S.length()<=200
	2. 1<=T.length()<=200
	3. S and T only contain lowercase letters and '#' charaters.
Follow up:
	can you solve it in O(N) time and O(1) space?
*/

bool backspaceCompare(string S, string T) {
    int i=S.length()-1,j=T.length()-1;
    int cnt1=0,cnt2=0;
    while(i>=0||j>=0)
    {
        while(i>=0&&(S[i]=='#'||cnt1)) S[i--]=='#'?++cnt1:--cnt1;
        while(j>=0&&(T[j]=='#'||cnt2)) T[j--]=='#'?++cnt2:--cnt2;
        if(i<0||j<0) return i==j;
        if(S[i--]!=T[j--]) return false;
    }
    return i==j;
}
