#### 19. 删除链表的倒数第 N 个结点  
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。  
```c  
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m = 0;
        int index = 0;
        ListNode* new_head = head;
        while(new_head != nullptr) {
            new_head = new_head->next;
            m++;
        }
        new_head = head;
        if (m == 1 && n == 1) {
            head = nullptr;
            return head;
        }
        index = m - n;
        while(index!= 0 && --index) {
            if (new_head != nullptr)
                new_head = new_head->next;
        }
        ListNode* tmp;
        if (new_head != nullptr)
            tmp = new_head->next;
        if (m == n) {
            delete new_head;
            return tmp;
        }
        if (new_head != nullptr && new_head->next != nullptr) {
            new_head->next = new_head->next->next;          
        }
        delete tmp;
        return head;
    }
};
``` 

#### 链表结构梳理:
&ensp;&ensp;(1.链表的操作首先要区分头节点、从节点，因为这两种节点的逻辑不同，当然也可以再加入一个虚拟头节点，让头节点和从节点都变为从节点   
&ensp;&ensp;我做了这几道链表的题目，基本上都要单独区分头节点和从节点  
&ensp;&ensp;(2.链表结构的核心就是对指针的理解和使用  
&ensp;&ensp;(3.链表操作涉及到遍历，如果时间复杂度超过O(n2)，这个算法即使成功，题目系统肯定会超时，即时间复杂度只允许遍历一遍;   

