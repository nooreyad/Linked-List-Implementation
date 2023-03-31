#include "LinkedList.h"
#include <bits/stdc++.h>

using namespace std;

SLL::SLL() {
    head = nullptr;
    tail = nullptr;
}

SLL::~SLL() {
    node *current = head;
    while (current != nullptr){
        node* tmp = current;
        current = current->next;
        free(tmp);
    }
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
        return;
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
    tail = nullptr;
}

DLL::~DLL() {
    nodeDLL *current = head;
    while (current != nullptr){
        nodeDLL *tmp = current;
        current = current->next;
        free(tmp);
    }
}

bool DLL::isEmpty() {
    return head == nullptr;
}

bool DLL::search(int item) {
    nodeDLL *ptr = head;
    while (ptr != nullptr && ptr->info != item){
        ptr = ptr->next;
    }
    return ptr != nullptr;
}

void DLL::addToHead(int item) {
    nodeDLL *newNode = new nodeDLL (item);
    if (head == nullptr){
        head = tail = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}

void DLL::printList() {
    nodeDLL *temp = head;
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

void DLL::addToTail(int item) {
    nodeDLL *newNode = new nodeDLL(item);
    if (head == nullptr){
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void DLL::addToIndex(int id, int item) {
    if (id == 0){
        addToHead(item);
        return;
    }
    nodeDLL *newNode = new nodeDLL(item);
    nodeDLL *ptr;
    int cnt=0;
    for (ptr = head; ptr != nullptr && cnt < id-1; cnt++){
        ptr = ptr->next;
    }
    if (ptr != nullptr && id > 0){
        nodeDLL *tmp = ptr->next;
        ptr->next = newNode;
        newNode->prev = ptr;
        newNode->next = tmp;
        tmp->prev = newNode;
    }
    if (ptr == tail){
        newNode->prev = tail;
        tail = newNode;
    }
}

