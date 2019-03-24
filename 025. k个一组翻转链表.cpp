#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
  public:
    ListNode *reverseKGroup(ListNode *head, int k){
        ListNode *cur=head;
        int cur_k = 0;
        while(cur!=nullptr&&cur_k!=k){
            ++cur_k;
            cur = cur->next;
        }
        if(cur_k==k){
            cur=reverseKGroup(cur, k);
            ListNode *temp;
            while (cur_k-- > 0)
            {
                temp = head->next;
                head->next = cur;
                cur = head;
                head = temp;
            }
            head = cur;
        }
        return head;
    }
};

void print(ListNode *head){
    if(head==nullptr)
        cout << "The List is empty!" << endl;
    while(head->next!=nullptr){
        cout << head->val << "->";
        head = head->next;
    }
    cout << head->val << endl;
}

int main(){
    ListNode *head = new ListNode(1);
    ListNode *head1 = head;
    ListNode *node;
    int a[] = {2, 3, 4, 5};
    for(auto n:a){
        node = new ListNode(n);
        head->next = node;
        head = node;
    }
    Solution solution;
    print(head1);

    print(solution.reverseKGroup(head1, 3));
    delete head;
    system("pause");
    return 0;
}