#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <string>
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

  }
};


int main() {
  Solution sol;
  ListNode left(9);
  ListNode right(9);

  cout << sol.addTwoNumbers(&left, &right) << endl;

  return 0;
}

