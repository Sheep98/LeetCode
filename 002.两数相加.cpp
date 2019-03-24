#include<iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
        ListNode *head1 = l1;
        ListNode *head2 = l2;
        ListNode *node = new ListNode(0);
        int temp=0, sum=0;
        while(head1->next!=NULL&&head2->next!=NULL){
            sum = head1->val + head2->val+sum/10;
            head1->val = sum % 10;
            head1 = head1->next;
            head2 = head2->next;
        }
        temp = sum / 10;
        if(head1->next==NULL&&head2->next!=NULL){
            while(head2->next!=NULL){
                node->val = (temp + head2->val)%10;
                temp = (temp + head2->val) / 10;
                head1->next=node;
                head1 = node;
                head2 = head2->next;
            }
        }
        else if(head1->next!=NULL&&head2->next==NULL){
            while(head1->next!=NULL){
                sum = temp + head1->val;
                head1->val = sum % 10;
                temp = sum / 10;
                head1 = head1->next;
            }
        }
        else{
            sum=head1->val += head2->val+temp;
            if(sum>9){
                head1->val = sum - 10;
                node->val = 1;
                head1->next = node;
                head1 = node;
            }
            else{
                head1->val += head2->val;
            }
        }
        return head1;
    }
};

void printList(ListNode *head){
    while(head!=NULL){
        cout << head->val;
        head = head->next;
    }
    cout << endl;
}

int main(){
    Solution s;
    ListNode *head1 = new ListNode(2);
    ListNode *head2 = new ListNode(5);
    ListNode *head;
    int a[] = {4, 3};
    int b[] = {6, 4};
    head = head1;
    ListNode *node;
    for (int i = 0; i < 2;i++){
        node = new ListNode(a[i]);
        head->next = node;
        head = node;
    }
    head = head2;
    for (int i = 0; i < 2; i++)
    {
        node = new ListNode(b[i]);
        head->next = node;
        head = node;
    }
    printList(head1);
    printList(head2);
    s.addTwoNumbers(head1, head2);
    printList(head1);
    system("pause");
    return 0;
}