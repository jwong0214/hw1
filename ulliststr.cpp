#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
// PLEASE WORK
void ULListStr::push_back(const std::string& val) {
  if (empty()) {
    head_ = tail_ = new Item();
    head_->val[0] = val;
    head_->first = 0;
    head_->last = 1;
  }
  else if (tail_->last < ARRSIZE) {
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  else {
    Item* node = new Item();
    node->val[0] = val;
    node->first = 0;
    node->last = 1;
    node->prev = tail_;
    tail_->next = node;
    tail_ = node;
  }
  size_++;
}

void ULListStr::pop_back() {
  if (empty()) return;

  tail_->last--;
  size_--;

  if (tail_->first == tail_->last) {
    Item* temp = tail_;
    tail_ = tail_->prev;
    if (tail_ != NULL) tail_->next = NULL;
    else head_ = NULL;
    delete temp;
  }
}
  
void ULListStr::push_front(const std::string& val) {
    if (empty()) {
    head_ = tail_ = new Item();
    head_->val[ARRSIZE-1] = val;
    head_->first = ARRSIZE-1;
    head_->last = ARRSIZE;
  }
  else if (head_->first > 0) {
    head_->first--;
    head_->val[head_->first] = val;
  }
  else {
    Item* node = new Item();
    node->val[ARRSIZE-1] = val;
    node->first = ARRSIZE-1;
    node->last = ARRSIZE;
    node->next = head_;
    head_->prev = node;
    head_ = node;
  }
  size_++;
}

void ULListStr::pop_front() {
  if (empty()) return;

  head_->first++;
  size_--;

  if (head_->first == head_->last) {
    Item* temp = head_;
    head_ = head_->next;
    if (head_ != NULL) head_->prev = NULL;
    else tail_ = NULL;
    delete temp;
  }
}
  
std::string const & ULListStr::back() const {
  if (empty()) {
    throw std::invalid_argument("empty list");
  }
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const {
  if (empty()) {
    throw std::invalid_argument("empty list");
  }
  return head_->val[head_->first];
}
  
std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_) return NULL;
  Item* curr = head_;
  while (curr != NULL) {
    size_t count = curr->last - curr->first;
    if (loc < count) {
      return &curr->val[curr->first + loc];
    }
    else {
      loc -= count;
      curr = curr->next;
    }
  }
  return NULL;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
