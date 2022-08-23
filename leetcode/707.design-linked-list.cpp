/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */


#include<iostream>



// @lc code=start



struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};


class MyLinkedList
{
private:
    Node* head;
public:
    MyLinkedList()
    {
    }

    int get(int index)
    {
        Node* prev=head;
        for(int i{0};i<index;++i)
        {
            prev=prev->next;
        }
        return prev->val;
    }

    void addAtHead(int val)
    {
        Node *node= new Node(val);
        node->next=head;
        head=node;
        
    }

    void addAtTail(int val)
    {
        Node *node= new Node(val);
        Node *ptr=head;
        while (ptr->next)
        {
            ptr=ptr->next;
        }
        ptr->next=node;

        
    }

    void addAtIndex(int index, int val)
    {
        Node* prev=head;
        for(int i{1};i<index;++i)
        {
            prev=prev->next;
        }
        Node *curl = new Node(val);
        curl->next=prev->next;
        prev->next=curl;

    }

    void deleteAtIndex(int index)
    {
        Node* prev=head;
        for(int i{1};i<index;++i)
        {
            prev=prev->next;
        }
        prev->next=prev->next->next;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

int main()
{
    MyLinkedList* myLinkedList = new MyLinkedList();
    myLinkedList->addAtHead(1);
    myLinkedList->addAtTail(3);
    myLinkedList->addAtIndex(1, 2); // linked list becomes 1->2->3
    std::cerr<<myLinkedList->get(1);           // return 2
    myLinkedList->deleteAtIndex(1); // now the linked list is 1->3
    std::cerr<<myLinkedList->get(1);           // return 3
    return 0;
}
