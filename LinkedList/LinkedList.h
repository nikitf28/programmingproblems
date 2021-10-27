//
// Created by nikita on 28.10.2021.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <iostream>
#include <typeinfo>

using namespace std;

class LinkedListException{};

template <class T> class LinkedListElem{
    T data;
    LinkedListElem* next;
public:
    LinkedListElem(const T& adata, LinkedListElem* anext);
    const T& getData() const;
    LinkedListElem* getNext();

    template <class TT> friend class LinkedList;
};

template <class T> class LinkedList{
    LinkedListElem<T>* start;
    int size = 0;
    LinkedList(const LinkedList& list);

public:
    LinkedList();
    ~LinkedList();
    LinkedListElem<T>* getStart();
    void deleteFirst();
    void deleteAfter(LinkedListElem<T>* ptr);
    void insertFirst(const T& data);
    void insertAfter(LinkedListElem<T>* ptr, const T& data);

    int getSize();

    LinkedListElem<T>* get(int index);
    void getAll(T* arr);
    template<class TT> friend ostream& operator <<(ostream& out, LinkedList& list);
};

template<class T>
void LinkedList<T>::deleteFirst() {
    if (start){
        LinkedListElem<T>* temp = start->next;
        delete start;
        start = temp;
        size--;
    }
    else{
        throw LinkedListException();
    }
}

template<class T>
LinkedList<T>::LinkedList() {
    start = 0;
}

template<class T>
LinkedList<T>::~LinkedList() {
    while(start){
        deleteFirst();
        size--;
    }
}

template<class T>
void LinkedList<T>::insertFirst(const T &data) {
    LinkedListElem<T>* second = start;
    start = new LinkedListElem<T>(data, second);
    size++;
}

template<class T>
void LinkedList<T>::deleteAfter(LinkedListElem<T> *ptr) {
    if (ptr && ptr->next){
        //cout <<"PTR NEXT: " <<ptr->data <<" " <<ptr->next->data <<endl;
        LinkedListElem<T>* temp = ptr->next;
        ptr->next = ptr->next->next;
        delete temp;
        size--;
    }
    else{
        throw LinkedListException();
    }
}

template<class T>
void LinkedList<T>::insertAfter(LinkedListElem<T> *ptr, const T &data) {
    if (ptr){
        LinkedListElem<T>* temp = ptr->next;
        ptr->next = new LinkedListElem<T>(data, temp);
        size++;
    }
}

template<class T>
ostream &operator<<(ostream &out, LinkedList<T> &list) {
    LinkedListElem<T>* ptr = list.getStart();
    if (!ptr){
        out <<"EMPTY: ";
    }
    else while (ptr){
        out <<ptr->getData()<<' ';
        ptr = ptr->getNext();
    }
    return out;
}

template<class T>
LinkedListElem<T> *LinkedList<T>::getStart() {
    return start;
}

template<class T>
LinkedListElem<T> *LinkedList<T>::get(int index) {
    LinkedListElem<T>* temp = start;
    if (index >= size){
        throw LinkedListException();
    }
    for (int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp;
}



template<class T>
int LinkedList<T>::getSize() {
    return size;
}

template<class T>
void LinkedList<T>::getAll(T *arr) {
    LinkedListElem<T>* temp = start;
    for (int i = 0; i < size; i++){
        arr[i] = temp->data;
        temp = temp->next;

    }
}

template <class T> LinkedListElem<T>::LinkedListElem(const T &adata, LinkedListElem<T> *anext) {
    data = adata;
    next = anext;
}





template<class T>
LinkedListElem<T> *LinkedListElem<T>::getNext() {

    if (this){
        return next;
    } else{
        return 0;
    }



}

template<class T>
const T &LinkedListElem<T>::getData() const {
    return data;
}


#endif //LINKEDLIST_LINKEDLIST_H
