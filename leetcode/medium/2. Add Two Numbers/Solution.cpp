/*
 * 2. Add Two Numbers

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

https://leetcode.com/problems/add-two-numbers/
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  int getListLen(ListNode *p_node) const {
    int len = 0;
    ListNode *current = p_node;
    while (current) {
      len++;
      current = current->next;
    }
    return len;
  }

  int getSum(ListNode *l1, ListNode *l2) const {
    int lenL1 = getListLen(l1);
    int lenL2 = getListLen(l2);
    int sum = 0;

    if (lenL1 != lenL2 && lenL1 > lenL2) {
      while (lenL1 != lenL2 && lenL1--) {
        sum += l1->val * pow(10, lenL1);
        l1 = l1->next;
      }
    } else if (lenL1 != lenL2 && lenL1 < lenL2) {
      while (lenL1 != lenL2 && lenL2--) {
        sum += l2->val * pow(10, lenL1);
        l2 = l2->next;
      }
    }
    while (lenL1--) {
      sum += (l1->val + l2->val) * pow(10, lenL1);
      l1 = l1->next;
      l2 = l2->next;
    }
    return sum;
  }

  int getFirstNumeral(int sum) {
    while (sum > 10) {
      sum /= 10;
    }
    if (sum == 10) {
      return 1;
    }
    return sum;
  }

  int updateSum(int x) {
    int sum = x;
    int div = 0;
    while (sum > 10) {
      sum /= 10;
      div++;
    }
    int p = pow(10, div);
    p =  x - p * sum;
    return p;
  }

  ListNode* updateList(ListNode *node, int num, bool flag) {
    ListNode *current;
    current = node;
    if (flag) {
      current = new ListNode();
      node->next = current;
      current = node->next;
    }
    current->val = num;
    current->next = nullptr;
    return current;
  }

  ListNode* _addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode *current;
    current = new ListNode();
    ListNode *ret = current;
    int sum = getSum(l1, l2);
    bool flag = false;
    while (sum) {
      current = updateList(current, sum % 10, flag);
      flag = true;
      sum /= 10;
    }

    return ret;
  }

  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    ListNode *current;
    current = new ListNode();
    ListNode *ret = current;
    ListNode *l, *r;
    l = l1;
    r = l2;
    int div = 0;
    bool flag = false;
    while (l != nullptr || r != nullptr) {
      int lval = (l != nullptr) ? l->val : 0;
      int rval = (r != nullptr) ? r->val : 0;
      int sum = div + lval + rval;
      div = sum / 10;
      current = updateList(current, sum % 10, flag);
      flag = true;
      l = (l != nullptr) ? l->next : nullptr;
      r = (r != nullptr) ? r->next : nullptr;
    }
    if (div > 0) {
      current->next = new ListNode(div);
    }
    return ret;
  }
};
