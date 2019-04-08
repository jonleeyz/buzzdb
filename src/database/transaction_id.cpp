#include "transaction_id.h"

// tests not written

namespace emerald {
/**
 * Initialization of private static member in TransactionId class
 */ 
std::atomic_long TransactionId::counter = 1;

TransactionId::TransactionId() {
  id_value = counter.fetch_add(1);
}

TransactionId::TransactionId(long id) {
  this->id_value = id;
}

long TransactionId::get_id_value() {
  return id_value;
}

bool TransactionId::operator==(TransactionId & other) {
  return id_value == other.id_value; 
}

int HashCode() {
  return (int)id_value;
}
}
