#ifndef HEAP_H
#define HEAP_H

#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>  // for std::swap

using namespace std;

template <typename T, typename PComparator = std::less<T>>
class Heap {
public:
  Heap(int m = 2, PComparator c = PComparator()) : m(m), c(c) {}

  ~Heap() {}

  void push(const T& item) {
    heap.push_back(item);
    trickleUp(heap.size() - 1);
  }

  T const& top() const {
    if (empty()) {
      throw std::underflow_error("Heap is empty");
    }
    return heap.front();
  }

  void pop() {
    if (empty()) {
      throw std::underflow_error("Heap is empty");
    }
    std::swap(heap.front(), heap.back());
    heap.pop_back();

    if (!empty()) {
      trickleDown(0);
    }
  }

  bool empty() const {
    return heap.empty();
  }

  size_t size() const {
    return heap.size();
  }

private:
  vector<T> heap;
  int m;
  PComparator c;

  void trickleUp(size_t loc) {
    if (loc == 0) return;
    size_t parentIdx = (loc - 1) / m;
    if (c(heap[loc], heap[parentIdx])) {  
      std::swap(heap[parentIdx], heap[loc]);
      trickleUp(parentIdx);
    }
  }

  void trickleDown(size_t loc) {
    size_t bestIndex = loc;
    for (int i = 1; i <= m; i++) {
      size_t childIdx = loc * m + i;
      if (childIdx < heap.size() && c(heap[childIdx], heap[bestIndex])) {
        bestIndex = childIdx;
      }
    }
    if (bestIndex != loc) {
      std::swap(heap[bestIndex], heap[loc]);
      trickleDown(bestIndex);
    }
  }
};

#endif