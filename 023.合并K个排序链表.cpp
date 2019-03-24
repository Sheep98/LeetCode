#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution
{
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *newHead = new ListNode(0);
        ListNode *head = newHead;
        int min = INT_MAX;
        int notNullNum = 0;
        for (auto n : lists)
        {
            if (n != NULL)
                ++notNullNum;
            //cout << notNullNum << endl;
        }
        while (notNullNum > 0)
        {
            min = INT_MAX;
            vector<ListNode *>::iterator node;
            for (auto b = lists.begin(); b != lists.end(); ++b)
            {
                if ((*b) == NULL)
                    continue;
                if ((*b)->val < min)
                {
                    node = b;
                    min = (*b)->val;
                }
            }
            ListNode *newNode = new ListNode((*node)->val);
            head->next = newNode;
            head = newNode;
            if ((*node)->next == NULL)
            {
                --notNullNum;
                (*node) = NULL;
                continue;
            }
            (*node)->val = (*node)->next->val;
            (*node)->next = (*node)->next->next;
        }

        return newHead->next;
    }
};

void print(ListNode *node){
    while(node!=NULL){
        cout << node->val << "->";
        node = node->next;
    }
    cout << endl;
}

int main(){
    Solution solution;
    ListNode *head1 = new ListNode(1);
    int a[] = {4, 5};
    ListNode *head;
    head = head1;
    for(auto n:a){
        ListNode *node = new ListNode(n);
        head->next = node;
        head = node;
    }
    int b[] = {3, 4};
    ListNode *head2 = new ListNode(1);
    head = head2;
    for(auto n:b){
        ListNode *node = new ListNode(n);
        head->next = node;
        head = node;
    }
    ListNode *head3 = new ListNode(2);
    head = head3;
    ListNode *node = new ListNode(6);
    head->next = node;
    head = node;
    vector<ListNode *> lists;
    lists.push_back(head1);
    lists.push_back(head2);
    lists.push_back(head3);
    
    // for(auto n:lists){
    //     print(n);
    // }
    auto show = solution.mergeKLists(lists);
    print(show);
    system("pause");
    return 0;
}