#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

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
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

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
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
    std::vector<T> myHeap;
    int arrayNess_;
    PComparator comp;

};

// Add implementation of member functions here

template<typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
{
  arrayNess_ = m;
  comp = c;
}

template<typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const 
{
  return myHeap.size();
}

template<typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const
{
  return (size() == 0);
}

template<typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{

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
    throw std::underflow_error("Empty heap");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return myHeap[0];
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
    throw std::underflow_error("empty heap");
  }

  std::swap(myHeap[0], myHeap[size() - 1]);
  myHeap.pop_back();

  //trickle down
  int index = 0;
  while (true)
  {
    int firstChildIndex = arrayNess_*index+1;
    if (firstChildIndex >= size()) break;
    int bestChildIndex = firstChildIndex;

    for (int i = 1; i < arrayNess_; i++)
    {
      int nextChildIndex = firstChildIndex + i;
      if (nextChildIndex >= size()) break;
      if (comp(myHeap[nextChildIndex], myHeap[bestChildIndex])) bestChildIndex = nextChildIndex;
    }

    if (comp(myHeap[bestChildIndex], myHeap[index])) 
    {
      std::swap(myHeap[bestChildIndex], myHeap[index]);
      index = bestChildIndex;
    }
    else
    {
      break;
    }
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  myHeap.push_back(item);
  int index = size() - 1;

  while (true)
  {
    int parentIndex = (index-1)/arrayNess_;
    if (comp(myHeap[index], myHeap[parentIndex]))
    {
      std::swap(myHeap[index], myHeap[parentIndex]);
      index = parentIndex;
    }
    else
    {
      break;
    }
    if (index == 0) break;
  }
}



#endif

