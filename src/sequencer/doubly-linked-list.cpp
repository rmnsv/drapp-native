#include <iostream>
#include "doubly-linked-list.h"

using namespace std;

namespace SequencerNative {
    DoublyLinkedList::DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
        
    DoublyLinkedList::~DoublyLinkedList() {

        DoublyLinkedItem* item = head;

        while (item != nullptr) {
            DoublyLinkedItem* next = item->next;
            delete item;
            item = next;
        }
    }

    void DoublyLinkedList::insertFront(Track newData) {

        DoublyLinkedItem* newItem = new DoublyLinkedItem;
        newItem->data = newData;
        newItem->prev = nullptr;

        if (head == nullptr) {
            head = newItem;
            tail = newItem;
            newItem = nullptr;
        } else {
            head->prev = newItem;
            newItem->next = head;
            head = newItem;
        }
    }

    void DoublyLinkedList::insertBack(Track newData) {

        DoublyLinkedItem* newItem = new DoublyLinkedItem;
        newItem->data = newData;
        newItem->next = nullptr;

        if (head == nullptr) {
            head = newItem;
            tail = newItem;
            newItem = nullptr;
        } else {
            tail->next = newItem;
            newItem->prev = tail;
            tail = newItem;
        }
    }

    void DoublyLinkedList::removeFront() {
        if (size() == 0) {
            return;
        }

        if (size() == 1) {
            DoublyLinkedItem* itemToDelete = head;
            delete itemToDelete;
            head = nullptr;
            tail = nullptr;
        } else {
                DoublyLinkedItem* itemToDelete = head;
                head = head->next;
                head->prev = nullptr;
                delete itemToDelete;
            }
        }

        void DoublyLinkedList::removeBack() {
            if (size() == 0) {
                return;
            }

            if (size() == 1) {
                DoublyLinkedItem* itemToDelete = tail;
                delete itemToDelete;
                head = nullptr;
                tail = nullptr;
            } else {
                DoublyLinkedItem* itemToDelete = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete itemToDelete;
            }
        }

        void DoublyLinkedList::removeAt(int index) {
            if (size() == 0) {
                return;
            } else if (index > size() - 1) {
                cerr << "Out of range" << endl;
            }

            DoublyLinkedItem* curItem = head;

            if (curItem == head) {
                removeFront();
                return;
            }

            if (curItem == tail) {
                removeFront();
                return;
            }

            for (int i = 0; i < index; i++) {
                curItem = curItem->next;
            }

            curItem->prev->next = curItem->next;
            curItem->next->prev = curItem->prev;

            delete curItem;
        }

        bool DoublyLinkedList::isEmpty() {
            if (head == 0) {
                return true;
            }

            return false;
        }

        Track& DoublyLinkedList::getDataAt(int index) {
            if (index > size() - 1) {
                cerr << "Out of range!" << endl;
                exit(-1);
            }

            DoublyLinkedItem* curItem = head;
            for (int i = 0; i < index; i++) {
                curItem = curItem->next;
            }

            return curItem->data;
        }

        int DoublyLinkedList::size() {
            DoublyLinkedItem* curItem = head;
            int size = 0;

            while (curItem != nullptr) {
                size++;
                curItem = curItem->next;
            }

            return size;
        }
}