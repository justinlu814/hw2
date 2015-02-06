#include "stackdbl.h"
#include "cstdlib"

StackDbl::StackDbl()
{
  LListDbl * temp = new LListDbl();
  list_ = temp;
}

StackDbl::~StackDbl()
{
  delete list;
}

bool StackDbl::empty() const
{
  return list_->empty();
}

void StackDbl::push(const double& val)
{
  list_->insert(0,val);
  return;
}

double const & StackDbl::top() const
{
  return list_->get(0);
}

void StackDbl::pop()
{
  list_->remove(0);
  return;
}
