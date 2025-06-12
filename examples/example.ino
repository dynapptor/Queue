/**
 * @file example.ino
 * @brief Example sketch demonstrating the usage of the Queue library.
 */

#include <Arduino.h>
#include <Queue.h>

/**
 * @brief Queue instance to store pointers to integers.
 */
Queue<int> queue;

/**
 * @brief Setup function to initialize the queue and demonstrate usage.
 */
void setup() {
  Serial.begin(125200);
  queue.init(5);  // Initialize queue with size 5

  // Add items to the queue
  int values[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++) {
    if (!queue.add(&values[i])) {
      Serial.println("Failed to add item");
    }
  }

  // Peek at the first item
  int* item;
  if (queue.peek(item)) {
    Serial.print("Peeked item: ");
    Serial.println(*item);
  }

  // Read and print all items
  while (queue.read(item)) {
    Serial.print("Read item: ");
    Serial.println(*item);
  }

  // Check if queue is empty
  Serial.print("Queue is empty: ");
  Serial.println(queue.isEmpty() ? "true" : "false");

  // Add one more item and clear the queue
  queue.add(&values[0]);
  queue.clear();
  Serial.print("Queue count after clear: ");
  Serial.println(queue.count());
}

/**
 * @brief Empty loop function.
 */
void loop() {}