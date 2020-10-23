#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <string>
#include <math.h>
#include "reload.h"
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {
  }
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

ostream& operator<<(ostream& stream, ListNode* list_node) {
  stream << '[';
  ListNode *current = list_node;
  while (current) {
    stream << current->val;
    current = current->next;
    if (current != nullptr) {
      stream << ", ";
    }
  }
  stream << ']';
  return stream;
}
int main() {
  Solution sol;
  ListNode* left3;
  ListNode* left2;
  ListNode* left1;
  left3 = new ListNode(9);
  left2 = new ListNode(4, left3);
  left1 = new ListNode(2, left2);
  ListNode* right3;
  ListNode* right2;
  ListNode* right1;
  ListNode* right0;
  right0 = new ListNode(9);
  right3 = new ListNode(4, right0);
  right2 = new ListNode(6, right3);
  right1 = new ListNode(5, right2);

  cout << sol.addTwoNumbers(left1, right1) << endl;

  return 0;
}

