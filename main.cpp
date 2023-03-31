#include <bits/stdc++.h>
#include "LinkedList.cpp"

using namespace std;

int main() {
    DLL newList;
    newList.sortedInsertion(10);
    newList.sortedInsertion(20);
    newList.sortedInsertion(30);
    newList.sortedInsertion(50);
    newList.sortedInsertion(16);
    newList.sortedInsertion(-2200);
    newList.printList();
    newList.reversePrint();
}
