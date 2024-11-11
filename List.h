#ifndef List_H
#define List_H
#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node *next;
};

template <typename T>
class List
{
private:
    Node<T> *head;

public:
    List();
    List(T data);
    ~List();
    void add(T data);
    void clear();
    void removeByData(T data);
    void removeByPosition(int position);
    void printList();
    bool isEmpty() const;
};

#endif