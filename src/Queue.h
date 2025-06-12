#pragma once
#include <stdint.h>

/**
 * @brief A generic circular queue implementation for storing pointers to objects of type T.
 * @tparam T The type of objects stored in the queue (pointers to T).
 */
template <typename T>
class Queue {
 private:
  uint8_t _head = 0;       ///< Index of the first item in the queue.
  uint8_t _tail = 0;       ///< Index where the next item will be added.
  uint8_t _count = 0;      ///< Number of items in the queue.
  uint8_t _queueSize = 0;  ///< Maximum queue capacity (set by init).
  T** _items = nullptr;    ///< Array of pointers to ADU objects.

 public:
  /**
   * @brief Default constructor for the Queue class.
   */
  Queue();

  /**
   * @brief Destructor for the Queue class.
   * @note Deallocates the internal array, but not the objects pointed to by T*.
   */
  ~Queue();

  /**
   * @brief Initializes the queue with a specified size.
   * @param queueSize The maximum number of items the queue can hold.
   */
  void init(uint8_t queueSize);

  /**
   * @brief Adds an item to the queue.
   * @param item Pointer to the item to add.
   * @return True if the item was added successfully, false if the queue is full or item is nullptr.
   */
  bool add(T* item);

  /**
   * @brief Reads and removes the first item from the queue.
   * @param item Reference to a pointer where the item will be stored.
   * @return True if an item was read, false if the queue is empty.
   */
  bool read(T*& item);

  /**
   * @brief Peeks at the first item in the queue without removing it.
   * @param item Reference to a pointer where the item will be stored.
   * @return True if an item was peeked, false if the queue is empty.
   */
  bool peek(T*& item) const;

  /**
   * @brief Checks if the queue is empty.
   * @return True if the queue is empty, false otherwise.
   */
  bool isEmpty() const;

  /**
   * @brief Clears all items from the queue.
   * @note Does not deallocate the objects pointed to by T*.
   */
  void clear();

  /**
   * @brief Returns the current number of items in the queue.
   * @return The number of items in the queue.
   */
  uint8_t count() const;
};

#include "Queue.tpp"