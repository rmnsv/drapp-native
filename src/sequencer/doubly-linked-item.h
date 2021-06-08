#include "track.h"

namespace SequencerNative {
    class DoublyLinkedItem {
    public: 
        Track data;

        DoublyLinkedItem* next;
        DoublyLinkedItem* prev;

        DoublyLinkedItem();
        DoublyLinkedItem(DoublyLinkedItem &refNode);
        ~DoublyLinkedItem();
        
        DoublyLinkedItem& operator=(DoublyLinkedItem &rvalueItem);
    };
}