/**
* 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
* 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
* 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*
* 示例：
* 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
* 输出：7 -> 0 -> 8
* 原因：342 + 465 = 807
*/


#include <iostream>
#include "../define.h"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * 初始化链表
 * @param arr
 * @param length
 * @return
 */
ListNode* initList(int arr[], int length){
    ListNode* head = nullptr;

    for (int i = 0; i < length; ++i) {
        auto value = new ListNode(arr[i]);
        if (head == nullptr){
            head = value;
        }else{
            value->next = head;
            head = value;
        }
    }

    return head;
}
/**
 * 打印链表
 * @param list
 */
void printListNode(ListNode* list){
    while (list != nullptr){
        cout << list->val << endl;
        list = list->next;
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        //链表最后一个元素
        ListNode* tail = result;
        //进位
        int carryBit = 0;
        while (l1 != nullptr || l2 != nullptr){
            int x = l1 == nullptr ? 0 : l1->val;
            int y = l2 == nullptr ? 0 : l2->val;
            int sum = x + y + carryBit;
            carryBit = sum / 10;
            auto value = new ListNode(sum % 10);

            if (tail == nullptr){
                result = tail = value;
            } else {
                tail->next = value;
                tail = value;
            }
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }
        if (carryBit > 0 ){
            auto value = new ListNode(carryBit);

            if (tail == nullptr){
                result = tail = value;
            } else {
                tail->next = value;
                tail = value;
            }
        }


        return result;
    }
};

#ifdef TEST_PROBLEM2

int main(){
    int arr1[] = {3, 4, 2};
    int arr2[] = {4, 6, 5};

    ListNode* l1 = initList(arr1, 3);
    ListNode* l2 = initList(arr2, 3);

    Solution solution;
    auto result = solution.addTwoNumbers(l1, l2);
    printListNode(result);

    return 0;
}

#endif