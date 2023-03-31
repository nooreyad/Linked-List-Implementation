#include "LinkedList.h"
#include <bits/stdc++.h>

using namespace std;

SLL::SLL() {
    head = nullptr;
    tail = nullptr;
}

SLL::~SLL() {
    delete head;
    delete tail;
}

void SLL::addToHead(int item) {
    node *newNode = new node(item);
    if (head == nullptr){
        tail = head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void SLL::addToTail(int item) {
    node *newNode = new node(item);
    if (tail == nullptr){
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void SLL::removeFromHead() {
    node* ptr = head;
    if (head == tail){
        head = tail = nullptr;
    }
    else{
        head = head->next;
    }
    free(ptr);
}

void SLL::removeFromTail() {
    if (head == tail){
        head = tail = nullptr;
        return;
    }
    node *ptr = head;
    while (ptr->next->next != nullptr){
        ptr = ptr->next;
    }
    free(tail);
    tail = ptr;
    tail->next = nullptr;
}

void SLL::printList() {
    node *temp = head;
    if (isEmpty()){
        cout << "List is empty" << endl;
        return;
    }
    while (temp != nullptr){
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl;
}

void SLL::addToIndex(int id, int item) {
    if (id == 0){
        addToHead(item);
        return;
    }
    node *newNode = new node(item);
    int cnt=0;
    node *ptr;
    for (ptr = head; ptr != nullptr && cnt < id-1; cnt++){
        ptr = ptr->next;
    }
    if (ptr != nullptr && id > 0){
        node *tmp = ptr->next;
        ptr->next = newNode;
        newNode->next = tmp;
    }
    if (tail == ptr){
        tail = newNode;
    }
}

bool SLL::isEmpty() {
    return head == nullptr;
}

void SLL::removeFromMiddle(int data) {
    if (isEmpty()){
        cout << "List is empty!" << endl;
        return;
    }
    if (data == head->info){
        removeFromHead();
        return;
    }
    node *tmp = head;
    while (tmp->next->info != data){
        tmp = tmp->next;
    }
    tmp->next = tmp->next->next;
}

bool SLL::search(int data) {
    node* ptr = head;
    while (ptr != nullptr && ptr->info != data){
        ptr = ptr->next;
    }
    return ptr != nullptr;
}

void SLL::sortedAddition(int item) {
    if (head == nullptr){
        head = tail = new node(item);
    }
    else if (head->info > item){
        addToHead(item);
    }
    else{
        if (tail->info < item){
            addToTail(item);
        }
        else{
            node *tmp = head;
            node* newNode = new node(item);
            while (tmp->next->info < newNode->info){
                tmp = tmp->next;
            }
            newNode->next = tmp->next;
            tmp->next = newNode;
        }
    }
}

DLL::DLL() {
    head = nullptr;
    
}