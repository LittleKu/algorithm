#include <iostream>

struct Node {
  int data;
  Node *next, *prev;
  Node() : data(0), next(nullptr), prev(nullptr) {}
  Node(int d) : data(d), next(nullptr), prev(nullptr) {}
};

class MyLinkedList {
  int size_ = 0;
  Node* head_ = nullptr;
  Node* tail_ = nullptr;

 public:
  MyLinkedList() {
    head_ = new Node(-1);
    tail_ = new Node(-1);
    head_->next = tail_;
    tail_->prev = head_;
  }

  int get(int index) {
    if (size_ == 0 || index < 0 || index >= size_) {
      return -1;
    }

    Node* node = nullptr;
    if (index < size_ - index) {
      /* 从前往后数 */
      node = head_;
      for (int i = 0; i <= index; i++) {
        node = node->next;
      }
    } else {
      /* 从后往前数 */
      node = tail_;
      for (int i = 0; i < size_ - index; i++) {
        node = node->prev;
      }
    }
    return node->data;
  }

  void addAtHead(int val) { addAtIndex(0, val); }

  void addAtTail(int val) { addAtIndex(size_, val); }

  void addAtIndex(int index, int val) {
    if (index < 0 || index > size_) {
      return;
    }

    index = std::max(0, index);

    Node* to_add_front = nullptr; /* 需要插入的节点的上一个节点 */
    Node* to_add_back = nullptr;  /* 需要插入的节点的下一个节点 */

    /* 开始定位插入节点的位置 */
    if (index < size_ - index) {
      /* 从前往后数 */
      to_add_front = head_;
      for (int i = 0; i < index; i++) {
        to_add_front = to_add_front->next;
      }
      to_add_back = to_add_front->next;
    } else {
      /* 从后往前数 */
      to_add_back = tail_;
      for (int i = 0; i < size_ - index; i++) {
        to_add_back = to_add_back->prev;
      }
      to_add_front = to_add_back->prev;
    }

    size_++; /* 更新链表长度 */

    /* 找到需要插入的前后节点后，就把新节点插入即可 */
    Node* node = new Node(val);
    node->prev = to_add_front;
    node->next = to_add_back;
    to_add_front->next = node;
    to_add_back->prev = node;
  }

  void deleteAtIndex(int index) {
    if (size_ == 0 || index < 0 || index >= size_) {
      return;
    }

    Node* node = nullptr;
    if (index < size_ - index) {
      /* 从前往后数 */
      node = head_;
      for (int i = 0; i <= index; i++) {
        node = node->next;
      }
    } else {
      /* 从后往前数 */
      node = tail_;
      for (int i = 0; i < size_ - index; i++) {
        node = node->prev;
      }
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;

    delete node;
    size_--;
  }
};

int main(int argc, char** argv) {
  MyLinkedList linked_list;
  linked_list.addAtHead(1);
  linked_list.addAtIndex(1, 2);
  linked_list.addAtIndex(0, 3);
  linked_list.deleteAtIndex(1);
  linked_list.deleteAtIndex(1);
  return EXIT_SUCCESS;
}