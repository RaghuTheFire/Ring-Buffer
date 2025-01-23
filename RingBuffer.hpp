#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <cstdint>
#include <vector>

/* Defines: */
/** Size of each ring buffer, in data elements - must be between 1 and 255. */
constexpr size_t BUFFER_SIZE = 255;

/* Class Definition: */
class RingBuffer 
{
  public:
      RingBuffer(uint8_t* dataPtr, const uint16_t size) 
      {
          InitBuffer(dataPtr, size);
      }
  
      void InitBuffer(uint8_t* const dataPtr, const uint16_t size);
      uint16_t GetCount() const;
      uint16_t GetFreeCount() const;
      bool IsEmpty() const;
      bool IsFull() const;
      void Insert(const uint8_t data);
      uint8_t Remove();
      uint8_t Peek() const;
  
  private:
      uint8_t* In;                     // Current storage location in the circular buffer.
      uint8_t* Out;                    // Current retrieval location in the circular buffer.
      uint8_t* Start;                  // Pointer to the start of the buffer's underlying storage array.
      uint8_t* End;                    // Pointer to the end of the buffer's underlying storage array.
      uint16_t Size;                   // Size of the buffer's underlying storage array.
      uint16_t Count;                  // Number of bytes currently stored in the buffer.
};

#endif /* RINGBUFFER_H */

