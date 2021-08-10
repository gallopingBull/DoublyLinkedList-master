/**
 * @file doublylinkedlist.h
 *
 * @brief
 *    Template for doubly linked list class.
 *
 * @author Judy Challinger & Joshua Salcido!
 * @date 2/5/16
 */

#ifndef CSCI_311_DOUBLYLINKEDLIST_H
#define CSCI_311_DOUBLYLINKEDLIST_H

template <class T>
class DoublyLinkedList {

 public:
   DoublyLinkedList();
   ~DoublyLinkedList();
   void append(T* data);
   bool empty() const { return (head == nullptr); }
   T* remove();
   T* first();
   T* next();

 private:
   class Node {
    public:
      Node();
      Node(T* data);
      Node *next; 
      Node *prev;
      T* data;
   };
   Node *head;
   Node *tail;
   Node *current;
};

/**
 * @brief   Node constructor.
 */
template <class T>
DoublyLinkedList<T>::Node::Node(T* data) {
   this->data = data; 
   this->next = nullptr;
   this->prev = nullptr;

}
/**
 * @brief   DoublyLinkedList constructor.
 */
template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
   
    head = nullptr;
    tail = nullptr;
    current = nullptr; 


}

/**
 * @brief   DoublyLinkedList destructor.
 */
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  Node *ptr = head;

  while(ptr != nullptr){
      Node *temp = ptr;
      ptr = ptr->next;
      delete temp;
  }
  delete ptr; 
}

/**
 * @brief   Appends a new Node at the end of the DoublyLinkedList.
 * @param   data A pointer to the data to be stored in the new Node.
 * @return  Nothing.
 *
 * Creates a new Node to hold the data and appends the Node at the end
 * of the list. The current Node pointer is set to point to the newly
 * appended Node.
 */
template <class T>
void DoublyLinkedList<T>::append(T* data) {
     
    if (empty()){
        
        current = head = tail = new Node(data);
        tail->next = nullptr;
        head->prev = nullptr; 

    }
    
    else{
        Node *temp = tail;
        current = tail = new Node(data); 
        temp->next = tail;
        tail->next = nullptr; 
        tail->prev = temp; 
    }
}

/**
 * @brief   Get the first thing on the list.
 * @return  A pointer to the data stored in the first Node on the list,
 *          or nullptr if the list is empty.
 *
 * The current pointer is set to point to the first Node in the list,
 * or nullptr if the list is empty.
 */
template <class T>
T* DoublyLinkedList<T>::first() {

  if(head ==  nullptr){
      return nullptr;

  }
 
  current = head;
  return current->data; 
   
}

/**
 * @brief   Get the next thing on the list.
 * @return  A pointer to the data stored in the next Node on the list. The next
 *          Node is the one following whatever the current pointer is pointing
 *          to. If there is no next Node then nullptr is returned.
 *
 * The current pointer is set to point to the next Node in the list,
 * or nullptr if there is no next Node.
 */
template <class T>
T* DoublyLinkedList<T>::next() {
    
    if(current->next == nullptr){
        return nullptr; 
    }
    else{
        current = current->next;
        return current->data; 
    }
}

/**
 * @brief   Remove the Node pointed to by the current pointer.
 * @return  A pointer to the data stored in the next Node on the list. The next
 *          Node is the one following the Node that was removed. If there is
 *          no next Node then nullptr is returned.
 *
 * The current pointer is set to point to the next Node in the list, following
 * the Node that was removed, or nullptr if there is no next Node.
 */
template <class T>
T* DoublyLinkedList<T>::remove() {
    
    if(current == nullptr){
        return nullptr; 
    }
 
    else if(current->next == nullptr && current->prev == nullptr){
        Node *temp = current;

        current = head = tail = nullptr; 
        delete temp; 

    }
    else if(current == head){
        Node *temp = head;
        head = head->next;
        current = head;
        head->prev = nullptr;

        delete temp; 
        return current->data;
    }
    
    else if(current == current->next->prev && current->prev->next){
        Node *temp;
        temp = current;
        current = current->next;
        current->prev = temp->prev; 
        delete temp; 

        return current->data;
    }
    else if (current == tail){
        Node *temp;
        temp = tail;
        tail = tail->prev; 
        tail->next = nullptr;
        
        current = tail; 
        delete temp;

        return current->data; 
    }
    
    return (empty()? nullptr : current->data);   
    
}


#endif // CSCI_311_DOUBLYLINKEDLIST_H
