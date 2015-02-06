#include "alistint.h"
#include <cstdlib>
#include <iostream>

using namespace std;

AListInt::AListInt()
{
  int *temp = new int[10];
  /* for (int i = 0; i < 10; i++){
    temp[i] = NULL;
    }*/
  array = temp;
  capacity = 10;
  size_ = 0;
}

AListInt::AListInt(int cap)
{
  int *temp = new int[cap];
  /* for (int i = 0; i < cap; i++){
    temp[i] = NULL;
    }*/
  array = temp;
  capacity = cap;
  size_ = 0;
}

AListInt::~AListInt()
{
  delete [] array;
}

int AListInt::size() const
{
  return size_;
}

bool AListInt::empty() const
{
  return size_ == 0;
}

void AListInt::insert(int pos, const int& val)
{
  if (size_ == capacity) resize();
  if (pos < 0 || pos > size_) return;
  else if (pos == 0){
    array[0] = val;
    size_++;
    return;
  }
  /*  else if ( (pos-1) > 0 && array[pos-1] == NULL){
    for (int k = 1; k < capacity, k++){
      if (array[k] == NULL){
	array[k] = val;
	return;
      }
    }  
    } */   
  else {
    for (int i = size_-1; i >= pos; i--){
      array[i] = array[i+1];
    }
    array[pos] = val;
    size_++;
    return;
  }


}

void AListInt::remove(int pos)
{
  if (pos < 0 || pos >= size_) return;
  else {
    for (int i = pos; i < size_; i++){
      array[i] = array[i+1];
    }
    /*array[size_] = NULL;*/
    size_--;
  }
}

void AListInt::set(int position, const int& val)
{
  array[position] = val;
  return;
}

int& AListInt::get(int position)
{
  return array[position];
}

int const & AListInt::get(int position) const
{
  return array[position];
}

void AListInt::print_capacity()
{
  cout << capacity << endl;
  return;
}

void AListInt::resize()
{
  capacity = capacity * 2;
  int *temp = new int [capacity];
  for (int i = 0; i < size_; i++){
    temp[i] = array[i];
  }
  /* for (int j = size_; j < capacity; j++){
    temp[j] = NULL;
    }*/
  delete [] array;
  array = temp;
  return; 
  
}
