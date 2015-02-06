#include "llistdbl.h"
#include <cstdlib>

LListDbl::LListDbl()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListDbl::~LListDbl()
{
  clear();
}

bool LListDbl::empty() const
{
  return size_ == 0;
}

int LListDbl::size() const
{
  return size_;
}

/**
 * Complete the following function
 */
void LListDbl::insert(int loc, const double& val)
{
  if (loc < 0 || loc > size_) return;
  
  Item *temp = new Item;
  temp->val = val;
  if (empty()){
    head_ = temp;
    tail_ = temp;
    size_++;
  }

  else if (loc == size_){
    tail_->next = temp;
    temp->prev = tail_;
    temp->next = NULL;
    tail_ = temp;
    size_++;
    return;
  }
  else if (loc == 0){
    head_->prev = temp;
    temp->next = head_;
    temp->prev = NULL;
    head_ = temp;
    size_++;
    return;
  }
  else {
    Item *temp2 = getNodeAt(loc-1);
    temp->prev = temp2;
    temp->next = temp2->next;
    temp2->next->prev = temp;
    temp2->next = temp;
    return;
    size_++;
  }
 
}

/**
 * Complete the following function
 */
void LListDbl::remove(int loc)
{
 if (loc < 0 || loc >= size_) return;
 Item *temp = getNodeAt(loc);
 if (loc == (size_-1)){
   tail_ = temp->prev;
   tail_->next = NULL;
   delete temp;
   return;
 }
 else if (loc == 0){
   head_ = temp->next;
   head_->prev = NULL;
   delete temp;
   return;
 }
 else {
   temp->prev->next = temp->next;
   temp->next->prev = temp->prev;
   delete temp;
   return;
 }

}

void LListDbl::set(int loc, const double& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

double& LListDbl::get(int loc)
{
  Item *temp = getNodeAt(loc);
  return temp->val;
}

double const & LListDbl::get(int loc) const
{
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListDbl::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


LListDbl::Item* LListDbl::getNodeAt(int loc) const
{
  Item *temp = head_;
  if(loc >= 0 && loc < size_){
    while(temp != NULL && loc > 0){
      temp = temp->next;
      loc--;
    }
    return temp;
  }
  else {
    //throw std::invalid_argument("bad location");
    return NULL;
  }
}
