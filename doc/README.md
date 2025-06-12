# Queue Library

The Queue library provides a generic, circular queue implementation in C++ for Arduino and other embedded platforms. It uses templates to support any data type and is designed for memory-constrained environments.

## Features
- Generic, template-based queue for any data type.
- Circular buffer for efficient memory usage.
- FIFO (First-In, First-Out) operation.
- Lightweight and suitable for embedded systems.

## Installation
1. Download the library from the repository.
2. Extract the folder to your Arduino `libraries` directory.
3. Include the library in your sketch with `#include <Queue.h>`.

## File List
- `Queue.h`: Header file with the Queue class declaration and Doxygen comments.
- `Queue.tpp`: Template implementation of the Queue class methods.
- `keywords.txt`: Syntax highlighting for the Arduino IDE.
- `library.properties`: Metadata for the Arduino library manager.
- `README.adoc`: AsciiDoc overview of the library.
- `API.md`: Detailed API documentation.
- `examples/example.ino`: Example sketch demonstrating queue usage.

## Example
See the `examples/example.ino` file for a complete example. A snippet is shown below:
```cpp
#include <Queue.h>

Queue<int> queue;

void setup() {
  Serial.begin(9600);
  queue.init(5);  // Initialize queue with size 5

  int values[] = {1, 2, 3};
  for (int val : values) {
    queue.add(&val);
  }

  int* item;
  while (queue.read(item)) {
    Serial.println(*item);
  }
}

void loop() {}
```

## License
MIT License. See `LICENSE` for details.