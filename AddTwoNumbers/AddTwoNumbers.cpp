// ---- Program Info Start----
//FileName:     AddTwoNumbers.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-11 17:31:13
// ---- Program Info End  ----

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return ReverseList(l2);
        if(l2 == NULL) return ReverseList(l1);
        int  CF = 0;
        ListNode * p1 = l1, *p2 = l2, *pHead = new ListNode(-1), *p = pHead;
        while(p1 != NULL && p2 !=NULL){
            int sum = p1->val + p2->val + CF;
            CF = sum / 10;
            sum %= 10;
            ListNode * pTmp = new ListNode(sum);
            p->next = pTmp;
            p = pTmp;

            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1 != NULL){
            int sum = p1->val + CF;
            CF = sum / 10;
            sum %= 10;

            ListNode * pTmp = new ListNode(sum);
            p->next = pTmp;
            p = pTmp;

            p1 = p1->next;
        }
        while(p2 != NULL){
            int sum = p2->val + CF;
            if(sum >= 10){
                sum -= 10;
                CF = 1;
            }
            else
                CF = 0;

            ListNode * pTmp = new ListNode(sum);
            p->next = pTmp;
            p = pTmp;

            p2 = p2->next;
        }
        if(CF){
            ListNode * pTmp = new ListNode(1);
            p->next = pTmp;
            p = pTmp;
        }
        p = ReverseList(pHead->next);
        delete pHead;
        return p;
    }

    ListNode * ReverseList(ListNode * pListHead){
        if(pListHead == NULL) return pListHead;
        ListNode * pBefore = NULL;
        ListNode * p = pListHead;
        ListNode * pAfter = p->next;

        while(p -> next != NULL){
            p->next = pBefore;
            pBefore = p;
            p = pAfter;
            pAfter = p->next;
        }
        p ->next = pBefore;
        return p;
    }
};

int main(int argc, char *argv[])
{
    ifstream infile("Test",ios::in);
    string line;
    if(!infile){
        cerr<<"Open Test File Failed!"<<endl;
        return -1;
    }
    while(getline(infile, line)){
        istringstream streamLine(line);
        int number;
        ListNode * p1 = new ListNode(-1), * p2 = new ListNode(-1);
        ListNode * p = p1;
        while(streamLine >> number){
            if(number < 0)
                break;
            p->next = new ListNode(number);
            p = p->next;
        }
        p = p2;
        while(streamLine >> number){
            p->next = new ListNode(number);
            p = p->next;
        }
        Solution test;
        p = test.addTwoNumbers(p1->next, p2->next);
        while(p!=NULL){
            cout<<p->val<<" ";
            p = p->next;
        }
    }


    return 0;
}
