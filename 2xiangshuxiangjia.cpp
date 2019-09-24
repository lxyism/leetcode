/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 1;
        int len2 = 1;
        ListNode* p = l1;  //定义链表l1的头部指针为p
        ListNode* q = l2;  //定义链表l2的头部指针为q
        while(p-> next != NULL) //当l1不为空时，计算l1的长度
        {
            len1++;
            p = p->next;
        }
        while(q-> next != NULL) //计算l2的长度
        {
            len2++;
            q = q->next;
        }
        if(len1 > len2){    //当l1的长度大于l2的长度时
            for(int i=1; i<= len1-len2; i++)
            {
                q->next = new ListNode(0); //l2创建新的节点，val=0
                q = q->next;  //指针指向下一个节点
            }
        }
        else  //反之对l1进行补0
        {
            for(int i=1; i<= len2-len1; i++)
            {
                p->next = new ListNode(0);
                p = p->next;
            }
        }
        p = l1;  //l1的头部指针p
        q = l2; //l2的头部指针q
        bool count = false; //进位标志
        ListNode* l3 = new ListNode(-1);  //初始化一个一个链表l3
        ListNode* w=l3;     //定义链表l3的头部指针为w
        int i=0;
        while(p!=NULL && q!=NULL)   //当l1和l2都不为空时
        {
            i = count + p->val+q->val;      //这儿加count是加进位
            w->next = new ListNode(i%10);   //
            count = i >= 10 ? true:false;   //大于10就将进位标志设置为1
            w = w->next;        //w下一个节点
            p = p->next;        //p下一个节点
            q = q->next;        //q下一个节点
        }
        if(count)
        {
            w->next = new ListNode(1); //如果进位标志为1，则w的下一个节点新建一个val=1的节点
            w = w->next; 
        }
        return l3->next;    
    }
};

class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);  //存放结果的链表
        ListNode* h = head; //移动指针
        int sum = 0;    //每个位的家和结果
        bool carry = false; //进位标志
        while (l1 != NULL || l2 != NULL)
        {
            sum = 0;
            if(l1 != NULL)
            {
                sum += l1->next;
                l1 = l1->next;
            }
            if(l2 != NULL)
            {
                sum += l2->next;
                l2 = l2->next;
            }
            if(carry)
                sum++;
            h->next = new ListNode(sum%10);
            h = h->next;
            carry = sum >= 10 ?true : false; 
        }
        if(carry)
            h->next = new ListNode(1);
        return head->next;
    }
};