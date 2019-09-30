/**
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 示例：
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 *
 * 说明：
 * 给定的 n 保证是有效的。
 *
 * 进阶：
 * 你能尝试使用一趟扫描实现吗？
 */
#include <iostream>
#include "../define.h"
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

void display(ListNode* head){
    while (head != nullptr){
        cout << head->val;
        head = head->next;
        if (head != nullptr){
            cout << "->";
        }
    }

    cout << endl;
}

ListNode* arrayToList(int arr[], int length){
    ListNode* list = new ListNode(arr[0]);
    ListNode* temp = list;


    for (int i = 1; i < length; ++i) {
        temp->next =  new ListNode(arr[i]);
        temp = temp->next;
    }


    return list;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1 = head;
        ListNode* p2 = head;

        while (p1 != nullptr){
            p1 = p1->next;
            if (n > -1){
                --n;
            }else{
                p2 = p2->next;
            }
        }
        if (n == 0){
            head = head->next;
        }else {
            p2->next = p2->next->next;
        }

        return head;
    }
};

#ifdef TEST_PROBLEM19
int main(){
    int arr[] = {1, 2};
    ListNode* list = arrayToList(arr, sizeof(arr) / sizeof(int));

    display(list);

    Solution solution;
    display(solution.removeNthFromEnd(list, 2));

    return 0;
}
#endif