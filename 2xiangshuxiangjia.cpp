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
        ListNode* p = l1;  //��������l1��ͷ��ָ��Ϊp
        ListNode* q = l2;  //��������l2��ͷ��ָ��Ϊq
        while(p-> next != NULL) //��l1��Ϊ��ʱ������l1�ĳ���
        {
            len1++;
            p = p->next;
        }
        while(q-> next != NULL) //����l2�ĳ���
        {
            len2++;
            q = q->next;
        }
        if(len1 > len2){    //��l1�ĳ��ȴ���l2�ĳ���ʱ
            for(int i=1; i<= len1-len2; i++)
            {
                q->next = new ListNode(0); //l2�����µĽڵ㣬val=0
                q = q->next;  //ָ��ָ����һ���ڵ�
            }
        }
        else  //��֮��l1���в�0
        {
            for(int i=1; i<= len2-len1; i++)
            {
                p->next = new ListNode(0);
                p = p->next;
            }
        }
        p = l1;  //l1��ͷ��ָ��p
        q = l2; //l2��ͷ��ָ��q
        bool count = false; //��λ��־
        ListNode* l3 = new ListNode(-1);  //��ʼ��һ��һ������l3
        ListNode* w=l3;     //��������l3��ͷ��ָ��Ϊw
        int i=0;
        while(p!=NULL && q!=NULL)   //��l1��l2����Ϊ��ʱ
        {
            i = count + p->val+q->val;      //�����count�Ǽӽ�λ
            w->next = new ListNode(i%10);   //
            count = i >= 10 ? true:false;   //����10�ͽ���λ��־����Ϊ1
            w = w->next;        //w��һ���ڵ�
            p = p->next;        //p��һ���ڵ�
            q = q->next;        //q��һ���ڵ�
        }
        if(count)
        {
            w->next = new ListNode(1); //�����λ��־Ϊ1����w����һ���ڵ��½�һ��val=1�Ľڵ�
            w = w->next; 
        }
        return l3->next;    
    }
};

class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);  //��Ž��������
        ListNode* h = head; //�ƶ�ָ��
        int sum = 0;    //ÿ��λ�ļҺͽ��
        bool carry = false; //��λ��־
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