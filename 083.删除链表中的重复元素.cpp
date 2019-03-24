#include<iostream>
#include<set>
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
    ListNode *deleteDuplicates(ListNode *head)
    {

        if (head == NULL || head->next == NULL)
            return head;
        /*
         *这段注释代码是我以为是非排序链表所写，虽然也能通过不过效率偏低
         *新代码已更新
         */
        // set<int> m_set;
        // ListNode *node = head;
        // m_set.insert(head->val);
        // while(node->next!=NULL){
        //     if(m_set.find(node->next->val)!=m_set.end()){
        //         node->next = node->next->next;
        //     }
        //     else{
        //         m_set.insert(node->next->val);
        //         node = node->next;
        //     }

        // }
        ListNode *node=head;
        while(node!=NULL&&node->next!=NULL){
            if(node->val==node->next->val){
                node->next = node->next->next;
            }
            else{
                node=node->next;
            }
        }
        return head;
    }
};

void print(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


int main(){
    Solution solution;
    ListNode *head = new ListNode(1);
    ListNode *node;
    ListNode *head1;
    head1 = head;
    for (int i = 1; i < 3; ++i)
    {
        node = new ListNode(1);
        head->next = node;
        head = node;
    }

    print(head1);
    solution.deleteDuplicates(head1);
    print(head1);
    system("pause");
    return 0;
}