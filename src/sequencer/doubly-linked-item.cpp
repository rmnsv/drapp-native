#include "doubly-linked-item.h"

namespace SequencerNative {
    DoublyLinkedItem::DoublyLinkedItem() {
        next = nullptr;
        prev = nullptr; 
    }

    DoublyLinkedItem::DoublyLinkedItem(DoublyLinkedItem &refNode) {
        data = refNode.data;
        next = refNode.next;
        prev = refNode.prev;
    }

    DoublyLinkedItem::~DoublyLinkedItem() {}

    DoublyLinkedItem& DoublyLinkedItem::operator=(DoublyLinkedItem &rvalueItem) {
        if (this != &rvalueItem) {
            this->data = rvalueItem.data;
            this->next = rvalueItem.next;
            this->prev = rvalueItem.prev;
        }

        return *this;
    }
}