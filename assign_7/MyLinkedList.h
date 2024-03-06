// MyLinkedList.h
#pragma once

#include <iostream>

class sllnode
{
public:
    int val;
    sllnode *next;

    sllnode(int x = -1, sllnode *p = nullptr)
    {
        val = x;
        next = p;
    }

    ~sllnode()
    {
        val = -1;
        next = nullptr;
    }
};

class sll
{
    sllnode *sllHead;
    int nodeCnt;

public:
    sll(sllnode *p = nullptr)
    {
        sllHead = p;
        nodeCnt = 0;
    }

    ~sll()
    {
        while (sllHead != nullptr)
        {
            sllnode *temp = sllHead;
            sllHead = sllHead->next;
            delete temp;
        }
        nodeCnt = 0;
    }

    void delsll();

    int sllAddBeg(int x);

    void sllDisplay();
};

// MyLinkedList.cpp
#include "MyLinkedList.h"

void sll::delsll()
{
    while (sllHead != nullptr)
    {
        sllnode *temp = sllHead;
        sllHead = sllHead->next;
        delete temp;
    }
    nodeCnt = 0;
}

int sll::sllAddBeg(int x)
{
    sllnode *newNode = new sllnode(x, sllHead);
    sllHead = newNode;
    nodeCnt++;
    return 1; // assuming success
}

void sll::sllDisplay()
{
    sllnode *temp = sllHead;
    while (temp != nullptr)
    {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
