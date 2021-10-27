#include <iostream>
#include "LinkedList.h"

int main() {

    int n, k;
    cin >>n >>k;
    LinkedList<int> list;
    list.insertFirst(1);
    LinkedListElem<int>* ptr = list.getStart();
    for (int i = 1; i < n; i++){
        list.insertAfter(ptr, i+1);
        ptr = ptr->getNext();
    }

    ptr = list.getStart();
    while (list.getSize() > 1){
        for (int i = 0; i < k - 2; i++){
            //cout <<ptr->getData() <<" " <<ptr->getNext()->getData() <<endl;
            if (!ptr->getNext()){
                ptr = list.getStart();
            }
            else{
                ptr = ptr->getNext();
            }
        }
        LinkedListElem<int>* temp;
        if (ptr->getNext() == 0){
            temp = list.getStart()->getNext();
            list.deleteFirst();
        }
        else{
            temp = ptr->getNext()->getNext();
            list.deleteAfter(ptr);
        }
        ptr = temp;

    }
    cout <<list.getStart()->getData();
}
