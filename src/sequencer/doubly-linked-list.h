#include <iostream>
#include "doubly-linked-item.h"

using namespace std;

namespace SequencerNative {
    class DoublyLinkedList {

    private: 
        DoublyLinkedItem* head;
        DoublyLinkedItem* tail;

    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        
        void insertFront(Track newData);
        void insertBack(Track newData);
        void removeFront();
        void removeBack();
        void removeAt(int index);
        bool isEmpty();
        Track& getDataAt(int index);
        int size();
    };
}