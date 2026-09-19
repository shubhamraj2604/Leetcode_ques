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
    // ListNode* solve(ListNode* head , stack<int>&st){
    //     if(head->next == NULL){
    //        st.push(head->val);
    //        return head;
    //    }

    //    ListNode* nxtnode = solve(head->next , st);
    //    if(!st.empty() && st.top() <= head->val){
    //       st.pop();
    //       st.push(head->val);
    //       head->next = nxtnode;
    //       return head;
    //    }

    //    return nxtnode;
    // }
    ListNode* removeNodes(ListNode* head) {
    //    if(head == nullptr){
    //      return nullptr;
    //    }
    //     stack<int>st;
    //    return solve(head , st);
    stack<ListNode*>st;
    while(head){
        while(!st.empty() && st.top()->val < head->val){
                st.pop();
            }
        st.push(head);
        head = head->next;
    }

      ListNode* dummy = new ListNode(0);
      ListNode* curr = dummy;

      while(!st.empty()){
          ListNode* top = st.top();
          st.pop();
          curr->next = top;
          curr = curr->next;
      }
      curr->next = nullptr;
      // reverse the list;

      ListNode* prev = nullptr;
      curr = dummy->next;
      while(curr){
         ListNode* nxtnode = curr->next;
         curr->next = prev;
         prev = curr;
         curr = nxtnode;
      }
      return prev;
    }
};