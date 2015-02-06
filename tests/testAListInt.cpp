#include "../alistint.h"
#include <iostream>

using namespace std;

int main(){
  AListInt * list = new AListInt();

  // Check if the list is initially empty.
  if (list->empty()) {
    cout << "SUCCESS: List is empty initially." << endl;
  } else {
    cout << "FAIL: List is not empty initially when it should be." << endl;
  }

  // Insert an int
  list->insert(0, 5);

  // Check if the list is still empty.
  if (!list->empty()) {
    cout << "SUCCESS: List is not empty after one insertion." << endl;
  } else {
    cout << "FAIL: List is empty after one insertion." << endl;
  }

  if (list->size() == 1) {
    cout << "SUCCESS: List has size 1 after one insertion." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after one insertion.";
    cout << endl;
  }

  // Check if the value is correct.
  if (list->get(0) == 5) {
    cout << "SUCCESS: 5 is at the 0th index of the list." << endl;
  } else {
    cout << "FAIL: 5 is not at the 0th index of the list, " << list->get(0);
    cout << " is instead." << endl;
  }

  // Clean up memory.
  delete list;

  list = new AListInt (1);
  list->insert(0,5);
  list->insert(1,2);
  
  // Check is list is correct.
  if (list->get(0) == 5 && list->get(1) == 2){
    cout << "SUCCESS: 5 is at the 0th index and 2 is at the";
    cout << " 1st index of the list." << endl;
    cout << "Capacity was ... ";
    list->print_capacity(); 
  }
  else {
    cout << "FAIL: at the 0th index " << list->get(0);
    cout << " and at the 1st index " << list->get(1);
    cout << "Capacity was ... ";
    list->print_capacity();
  }

  delete list;
}
