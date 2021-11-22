#include <iostream>

#include "Time.h"
#include "LinkedList.h"
int main() {

    LinkedList list = new LinkedList();

    for (int i = 0; i < 5; ++i)
    {
        if(i == 3){
            list->add(105);
            list->add(106);
        }
        list->add(rand() % 100);
    }

    list->print();
    list->size();

    list->remove(105);

    list->print();
    list->size();

    Node* node = list->search(106);
    node->print();

    delete list;
    return 0;



    return 0;
}
