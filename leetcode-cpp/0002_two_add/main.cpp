#include <iostream>
using namespace std;

// 单链表节点的定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0); // 虚拟头节点，简化边界处理
        ListNode* cur = dummy;
        int carry = 0; // 进位

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
        }
        return dummy->next; // 跳过虚拟头节点
    }
};

// 辅助函数：根据数组创建链表（逆序存储）
ListNode* createList(const int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for (int i = 1; i < n; ++i) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}

// 辅助函数：打印链表
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // 示例 1: l1 = [2,4,3], l2 = [5,6,4] -> 输出 [7,0,8]
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    ListNode* l1 = createList(arr1, 3);
    ListNode* l2 = createList(arr2, 3);
    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);
    cout << "示例1结果: ";
    printList(result); // 期望: 7 -> 0 -> 8

    // 示例 2: l1 = [0], l2 = [0] -> 输出 [0]
    int arr3[] = {0};
    int arr4[] = {0};
    l1 = createList(arr3, 1);
    l2 = createList(arr4, 1);
    result = sol.addTwoNumbers(l1, l2);
    cout << "示例2结果: ";
    printList(result); // 期望: 0

    // 示例 3: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9] -> 输出 [8,9,9,9,0,0,0,1]
    int arr5[] = {9,9,9,9,9,9,9};
    int arr6[] = {9,9,9,9};
    l1 = createList(arr5, 7);
    l2 = createList(arr6, 4);
    result = sol.addTwoNumbers(l1, l2);
    cout << "示例3结果: ";
    printList(result); // 期望: 8 -> 9 -> 9 -> 9 -> 0 -> 0 -> 0 -> 1

    return 0;
}