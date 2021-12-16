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

    int i = 0;
    while (list.getSize() > 1){
        if (k == 1){
            cout <<"Survived: " <<n <<endl;
            return 0;
        }
        //cout <<list <<" i=" <<i <<endl;
        i++;
        LinkedListElem<int>* next;
        if (i % k == k-1){
            if (ptr->getNext() == 0){
                next = list.getStart()->getNext();
                //cout <<"DELETE " <<list.getStart()->getData() <<endl;
                list.deleteFirst();
            }
            else{
                next = ptr->getNext()->getNext();
                //cout <<"DELETE "  <<ptr->getNext()->getData() <<endl;
                list.deleteAfter(ptr);
            }
            i++;
        }
        else{
            if (ptr->getNext() == 0){
                next = list.getStart();
            }
            else{
                next = ptr->getNext();
            }
        }
        if (next == 0){
            ptr = list.getStart();
        }
        else{
            ptr = next;
        }

    }
    cout <<"Survived: " <<list.getStart()->getData();
}
