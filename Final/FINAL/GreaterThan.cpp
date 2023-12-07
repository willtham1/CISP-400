#include "GreaterThan.h"

#include <memory>

using std::shared_ptr;

bool GreaterThan::operator()(shared_ptr<UserAccount> &a,
                             shared_ptr<UserAccount> &b) {
  // Sort by account number
  return a->getAccountNumber() < b->getAccountNumber();
}
