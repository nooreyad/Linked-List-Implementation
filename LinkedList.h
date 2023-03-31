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
    void sortedInsertion(int item);
};


class DLL{
private:
    nodeDLL *head, *tail;
public:
    DLL();
    ~DLL();
    bool isEmpty();
    bool search(int item);
    void addToHead(int item);
    void addToTail(int item);
    void addToIndex(int id, int item);
    void printList();
    void reversePrint();
    void removeFromHead();
    void removeFromTail();
    void removeFromMiddle(int item);
    void sortedInsertion(int item);
};
#endif //LINKEDLIST_LINKEDLIST_H
