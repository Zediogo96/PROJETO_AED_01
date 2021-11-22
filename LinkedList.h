//
// Created by zedio on 22/11/2021.
//

#ifndef PROJETO_LINKEDLIST_H
#define PROJETO_LINKEDLIST_H


#include <cstdlib>
#include <iostream>

/**
 * Implementation of LinkedList
 *
 * @tparam T
 */

template <class T>
class LinkedList {

    class Node;

private:

    class Node {
        friend class LinkedList<T>;
    public:
        Node(const T& info);

    private:
        T*    info;
        Node* next;
    };

    Node* head; // first Element of LinkedList
    Node* tail; // last Element of LinkedList

public:

    int length;

    LinkedList();
    ~LinkedList();

    LinkedList(const LinkedList<T>& list) = delete;
    /*const LinkedList<T> operator=(const LinkedList<T>& list) = delete;
    */
    void addAtBeginning(const T& info);
    void removeElement(const T& info);
    bool contains(const T& info) const;

    /*
    template<class T>
    friend ostream& operator<<(ostream& os, const LinkedList<T>& list);*/
};

template<class T>
LinkedList<T>::LinkedList(): head(nullptr), tail(nullptr)
{
}

/** @brief: Method to erase a certain LinkedList */
template<class T>
LinkedList<T>::~LinkedList()
{
    Node* tmp1 = head;
    Node* tmp2;

    if (!head) return; // Return if head is null

    tmp2 = head->next;

    while (tmp1 != nullptr) {
        delete tmp1;
        tmp1 = tmp2;

        if (tmp1) { // If tmp1 is not null
            tmp2 = tmp2->next;
        }
    }

    std::cout << "List was deleted" << std::endl;
}

template <class T>
void LinkedList<T>::addAtBeginning(const T& info) {

    /** Create a new node to be added, with the desired information */
    Node* node = new Node();
    node->data = info;

    /** Move head to 2nd position of the LinkedList */
    node->next = this->head;
    /** Make new node be the head */
    this->head = node;

    this->length++;
}
template <class T>
void LinkedList<T>::removeElement(const T& info) {

    Node* prev = head;
    Node* current = head->next;

    if (this->length == 0) {
        std::cout << "Empty List" << std:: endl;
    }
    else if (this->head->data == info) {
        Node* current = head;
        this->head = this->head->next;
        delete current;
        this->length--;
    }
    else {
        Node* previous = this->head;
        Node* current = this->head->next;

        while (current != nullptr) {
            if (current-> data == info) {
                break;
            }
            else {
                previous = current;
                current = current->next;
            }
        }

        if (current == nullptr) {
            std::cout << "Can't remove a value that is not contained in the List" << std::endl;
        }
        previous->next = current->next;
        delete current;
        this->length--;
    }
}
template <class T>
bool LinkedList<T>::contains(const T& info) const {

    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == info) return true;

        temp = temp->next; // Will eventually turn into nullptr if info is not found, since this is not a circledList.
    }

    return false;
}


#endif //PROJETO_LINKEDLIST_H
