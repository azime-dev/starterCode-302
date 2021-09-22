#include "linked_list.hpp"
#include "Node.hpp"
#include <algorithm>

template <typename T>
LinkedList<T>::LinkedList()
{
  head->next = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  Node<T>* current = new Node<T>;
  while(current != nullptr)
  {
    Node<T>* next = new Node<T>{current->next};
    delete current;
    current = next;
  }
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  Node<T>* current = new Node<T>;
  Node<T>* current_x = new Node<T>;
  current = this.head;
  current_x = x.head;

  if(head == nullptr)
  {
    x.head.item = head.item;
    return;
  }

  while(current != nullptr)
  {
    current = current -> next;
    current_x -> next = new Node<T>{current->item};
  }
}

template <typename T>
void LinkedList<T>::swap(LinkedList<T>& x, LinkedList<T>& y)
{
  std::swap(x.head, y.head);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
  LinkedList<T> temp(x);
  std::swap(temp.head, head);
  return *this;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
  if(head == nullptr)
    return true;
  else
    return false;
}

template <typename T>
std::size_t LinkedList<T>::getLength() const
{
  int count = 0;
  Node<T>* temp = new Node<T>{head};
  while(temp != nullptr)
  {
    temp = temp->next;
    count++;
  }
  return count;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  Node<T>* current = new Node<T>;
  Node<T>* slack = new Node<T>;
  current = head;
  int count{0};

  while(count < position && slack != nullptr)
  {
    slack = current;
    current = current -> next;
    count++;
  }

  if(slack != nullptr)
  {
    Node<T> newNode = new Node<T>;
    newNode.item = item;
    slack -> next = newNode;
    newNode -> next = current;
    return true;
  }else
  {
    return false;
  }

}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  Node<T>* current = new Node<T>;
  Node<T>* slack = new Node<T>;
  Node<T>* next_node = new Node<T>;
  current = head;
  int count{0};

  while(count < position)
  {
    slack = current;
    current = current -> next;
  }

  next_node = current ->next;
  delete current;
  slack -> next = next_node;

  return true;
}

template <typename T>
void LinkedList<T>::clear()
{
  LinkedList::~LinkedList();
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  //TODO Not quiet sure what the purpose of this is? return head?
  return T();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  //TODO
}
