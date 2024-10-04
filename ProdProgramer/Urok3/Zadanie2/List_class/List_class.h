#pragma once
#include <iostream>

//проверяемый класс
struct ListNode
{
public:
    ListNode(int, ListNode*, ListNode*);
public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List();
    virtual ~List();
    bool Empty(); 
    unsigned long Size();
    void PushFront(int);  
    void PushBack(int); 
    int PopFront(); 
    int PopBack();   
    void Clear();  
private:
    ListNode* extractPrev(ListNode*); 
private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};