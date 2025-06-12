# Queue Library API Documentation

## Class: `Queue<T>`

A generic circular queue implementation for storing pointers to objects of type `T`.

### Template Parameter
- `T`: The type of objects stored in the queue (pointers to `T`).

### Constructor
- `Queue()`
  - **Description**: Default constructor. Initializes an empty queue.
  - **Parameters**: None.

### Destructor
- `~Queue()`
  - **Description**: Deallocates the internal array of pointers. Does not deallocate the objects pointed to by `T*`.
  - **Parameters**: None.

### Methods
- `void init(uint8_t queueSize)`
  - **Description**: Initializes the queue with a specified size.
  - **Parameters**:
    - `queueSize`: The maximum number of items the queue can hold.
  - **Returns**: None.

- `bool add(T* item)`
  - **Description**: Adds an item to the queue.
  - **Parameters**:
    - `item`: Pointer to the item to add.
  - **Returns**: `true` if the item was added, `false` if the queue is full or `item` is `nullptr`.

- `bool read(T*& item)`
  - **Description**: Reads and removes the first item from the queue.
  - **Parameters**:
    - `item`: Reference to a pointer where the item will be stored.
  - **Returns**: `true` if an item was read, `false` if the queue is empty.

- `bool peek(T*& item) const`
  - **Description**: Peeks at the first item in the queue without removing it.
  - **Parameters**:
    - `item`: Reference to a pointer where the item will be stored.
  - **Returns**: `true` if an item was peeked, `false` if the queue is empty.

- `bool isEmpty() const`
  - **Description**: Checks if the queue is empty.
  - **Parameters**: None.
  - **Returns**: `true` if the queue is empty, `false` otherwise.

- `void clear()`
  - **Description**: Clears all items from the queue. Does not deallocate the objects pointed to by `T*`.
  - **Parameters**: None.
  - **Returns**: None.

- `uint8_t count() const`
  - **Description**: Returns the current number of items in the queue.
  - **Parameters**: None.
  - **Returns**: The number of items in the queue.