#pragma once
#include "Queue.h"

/**
 * @brief Default constructor implementation.
 */
template <typename T>
Queue<T>::Queue() {}

/**
 * @brief Destructor implementation.
 * @note Deallocates the internal array, but not the objects pointed to by T*.
 */
template <typename T>
Queue<T>::~Queue() {
  delete[] _items;  // Note: T* pointers are managed by the caller (e.g., ModbusRTUMaster)
}

/**
 * @brief Initializes the queue with a specified size.
 * @param queueSize The maximum number of items the queue can hold.
 */
template <typename T>
void Queue<T>::init(uint8_t queueSize) {
  _queueSize = queueSize;
  _items = new T* [_queueSize] {};  // Allocate and initialize to nullptr
}

/**
 * @brief Adds an item to the queue.
 * @param item Pointer to the item to add.
 * @return True if the item was added successfully, false if the queue is full or item is nullptr.
 */
template <typename T>
bool Queue<T>::add(T* item) {
  if (_count >= _queueSize || item == nullptr) return false;
  _items[_tail] = item;
  _tail = (_tail + 1) % _queueSize;
  _count++;
  return true;
}

/**
 * @brief Peeks at the first item in the queue without removing it.
 * @param item Reference to a pointer where the item will be stored.
 * @return True if an item was peeked, false if the queue is empty.
 */
template <typename T>
bool Queue<T>::peek(T*& item) const {
  if (_count == 0) return false;
  item = _items[_head];
  return true;
}

/**
 * @brief Reads and removes the first item from the queue.
 * @param item Reference to a pointer where the item will be stored.
 * @return True if an item was read, false if the queue is empty.
 */
template <typename T>
bool Queue<T>::read(T*& item) {
  if (_count == 0 || !_items[_head]) return false;
  item = _items[_head];
  _items[_head] = nullptr;
  _head = (_head + 1) % _queueSize;
  _count--;
  return true;
}

/**
 * @brief Checks if the queue is empty.
 * @return True if the queue is empty, false otherwise.
 */
template <typename T>
bool Queue<T>::isEmpty() const {
  return _count == 0;
}

/**
 * @brief Clears all items from the queue.
 * @note Does not deallocate the objects pointed to by T*.
 */
template <typename T>
void Queue<T>::clear() {
  for (uint8_t i = 0; i < _queueSize; ++i) {
    if (_items[i]) {
      _items[i] = nullptr;
    }
  }
  _head = _tail = _count = 0;
}

/**
 * @brief Returns the current number of items in the queue.
 * @return The number of items in the queue.
 */
template <typename T>
uint8_t Queue<T>::count() const {
  return _count;
}