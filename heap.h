#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <algorithm> // For std::swap
#include <vector>

using namespace std;

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()) : m(m), c(c) {}

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap() = default;

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item) {
    heap.push_back(item);
    trickleUp(heap.size() - 1);
  }

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const {
    return heap.empty();
  }

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const {
    heap.size();
  }

private:
  /// Add whatever helper functions and data members you need below
  vector<T> heap;
  int m;
  PComparator c;
  void trickleUp(int loc);
  void trickleDown(int loc);

};

// Add implementation of member functions here
template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown(int loc) {
  while (true) {
    int bestIndex = loc;
    for (int i = 1; i <= m; i++) {
      int childIdx = loc * m + i;
      if (childIdx < heap.size() && c(heap[childIdx], heap[bestIndex])) {
        bestIndex = childIdx;
      }
    }

    if (bestIndex == loc) {
      break;
    }
    std::swap(heap[bestIndex], heap[loc]);
    loc = bestIndex;
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int loc) {
  // parent index = m * loc
  
  while (loc > 0) {
    int parentIdx = (loc - 1) / m;
    if (c(heap[parentIdx], heap[loc])) { // first arg is better than the second
      break;
    } else {
      std::swap(heap[parentIdx], heap[loc]);
      loc = parentIdx;
    }
  }
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap[0];


}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");

  }
  std::swap(heap[0], heap.back());
  heap.pop_back();
  trickleDown(0);
}



#endif

