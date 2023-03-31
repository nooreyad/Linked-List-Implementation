#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

struct node{
    int info;
    node* next;
    node(){
        next = nullptr;
        info = 0;
    }
    node(int data){
        next = nullptr;
        info = data;
    }
};

struct nodeDLL{
    int info;
    nodeDLL *next;
    nodeDLL *prev;
    nodeDLL(){
        next = nullptr;
        prev = nullptr;
        info = 0;
    }
    nodeDLL(int data){
        next = nullptr;
        prev = nullptr;
        info = data;
    }
};

class SLL{
private:
    node *head, *tail;
public:
    SLL();
    ~SLL();
    void addToHead(int item);
    void addToTail(int item);
    void addToIndex(int id, int item);
    void removeFromHead();
    void removeFromTail();
    void removeFromMiddle(int data);
    void printList();
    bool isEmpty();
    bool search(int data);
    void sortedAddition(int item);
};


class DLL{
private:
    node *head, *tail;
public:
    DLL();
    ~DLL();
};
#endif //LINKEDLIST_LINKEDLIST_H
