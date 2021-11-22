//
// Created by zedio on 22/11/2021.
//

#ifndef PROJETO_LINKEDLIST_H
#define PROJETO_LINKEDLIST_H


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
    private:
        T* info;
        Node* next;
    public:
        Node(const T& info);
        /** @brief Returns Information contained in a certain node */
        const T& getInfo() const; // Returns
        /** @brief Return a pointer to the next node */
        const Node* getNext() const; // Return a pointer to the next node
    };

    Node* head; // First Element of the LinkedList
    Node* tail; // Last Element of the LinkedList
public:

    LinkedList();
    ~LinkedList();

    LinkedList(const LinkedList<T>& list) = delete;
    /*const LinkedList<T> operator=(const LinkedList<T>& list) = delete;
    */
    void addToTail(const T& info);
    void remove(const T& info);
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

        if (tmp1) {
            tmp2 = tmp2->next;
        }
    }
}

template <class T>
void LinkedList<T>::addToTail(const T& info) {

    if (head == nullptr) {
        head = new Node(info);
        tail = head;
    }
    else {
        tail->next = new Node(info);
        tail = tail->next;
    }
}
template <class T>
void LinkedList<T>::remove(const T& info) {

    Node* ptr1 = head;
    Node* ptr2 = head->next;

    /** brief: In case information is in the head Node of the Linked List */
    if(head->info == &info) {

        ptr1 = head;
        head = head->next;
        delete ptr1;
        return;
    }

    while(ptr2 != nullptr)
    {
        if (ptr2->info == &info) {
            if (ptr2 == tail) {
                tail = ptr1;
            }
        }
    }
}

template <class T>
bool LinkedList<T>::contains(const T& info) const {

    Node* tmp = head;
    while (tmp != nullptr) {
        if (tmp->info == info) return true; // Checks if the info is in the head Node.

        tmp = tmp->next; // Else, continues to the next node.
    }

    return false; // In case nothing was found.

}

#endif //PROJETO_LINKEDLIST_H
