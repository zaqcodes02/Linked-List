#include "List.h"
#include <iostream>

template <typename T>
List<T>::List()
{
    head = nullptr;
}

template <typename T>
List<T>::List(T data)
{
    head = new Node<T>;
    head->data = data;
    head->next = nullptr;
}

template <typename T>
List<T>::~List()
{
    while (!isEmpty())
    {
        remove(0);
    }
}

template <typename T>
void List<T>::add(T data)
{
    if (isEmpty())
    {
        head = new Node<T>;
        head->data = data;
        head->next = nullptr;
    }
    else
    {
        Node<T> *currNode = head;
        while (currNode->next)
        {
            currNode = currNode->next;
        }
        Node<T> *newNode = new Node<T>;
        newNode->data = data;
        newNode->next = nullptr;
        currNode->next = newNode;
    }
}

template <typename T>
void List<T>::removeByData(T data)
{
    if (isEmpty())
    {
        std::cout << "No elements present in List!" << std::endl;
    }
    else if (head->data == data) // Correct the assignment to comparison
    {
        Node<T> *toDelete = head;
        head = head->next;
        delete toDelete;
    }
    else
    {
        Node<T> *currNode = head;
        while (currNode->next && currNode->next->data != data)
        {
            currNode = currNode->next;
        }

        if (currNode->next) // If data was found in the list
        {
            Node<T> *toDelete = currNode->next;
            currNode->next = currNode->next->next;
            delete toDelete;
        }
        else
        {
            std::cout << "Data not found in the list!" << std::endl;
        }
    }
}

template <typename T>
void List<T>::removeByPosition(int position)
{
    if (position < 0)
    {
        std::cout << "Invalid position!" << std::endl;
        return;
    }

    if (position == 0 && !isEmpty())
    {
        Node<T> *toDelete = head;
        head = head->next;
        delete toDelete;
    }
    else
    {
        Node<T> *currNode = head;
        int i = 0;
        while (currNode && i < position - 1)
        {
            currNode = currNode->next;
            i++;
        }

        if (currNode && currNode->next) // Ensure position is valid
        {
            Node<T> *toDelete = currNode->next;
            currNode->next = currNode->next->next;
            delete toDelete;
        }
        else
        {
            std::cout << "Position out of bounds!" << std::endl;
        }
    }
}

template <typename T>
void List<T>::clear()
{
    while (!isEmpty())
    {
        removeByPosition(0);
    }
}

template <typename T>
void List<T>::printList()
{
    if (isEmpty())
    {
        std::cout << "List is Empty!" << std::endl;
    }
    else
    {
        Node<T> *currNode = head;
        while (currNode)
        {
            std::cout << currNode->data << " ";
            currNode = currNode->next;
        }
        std::cout << std::endl;
    }
}

template <typename T>
bool List<T>::isEmpty() const
{
    return head == nullptr;
}

template class List<int>;
template class List<char>;
template class List<float>;
template class List<double>;
