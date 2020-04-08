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