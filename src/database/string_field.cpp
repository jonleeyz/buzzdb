#include <iostream>
#include <string_field.h>

namespace buzzdb {
StringField::StringField(std::string s) : value(s) {
}

StringField::StringField(const StringField & string_field) { 
  value = string_field.get_value();
}

std::string StringField::get_value() const {
  return this->value;
}

Type::FieldType StringField::get_type() const {
  return Type::FieldType::STRING;
}

bool StringField::Compare(Predicate::OpType op_type, Field * operand) {
  StringField * operand_value_pointer = static_cast<StringField *>(operand);
  std::string operand_value = operand_value_pointer->get_value();
  switch (op_type) {
    case Predicate::OpType::EQUALS:
      return this->value == operand_value;
      break;
    case Predicate::OpType::NOT_EQUALS:
      return this->value != operand_value;
      break;
    case Predicate::OpType::GREATER_THAN:
      return this->value > operand_value;
      break;
    case Predicate::OpType::LESS_THAN:
      return this->value < operand_value;
      break;
    case Predicate::OpType::GREATER_THAN_OR_EQUAL:
      return this->value >= operand_value;
      break;
    case Predicate::OpType::LESS_THAN_OR_EQUAL:
      return this->value <= operand_value;
      break;
    default:
      return false; // should throw an exception instead of returning false
      break;
  }
}

void StringField::Print() const {
  std::cout << value << " \n";
}

bool StringField::operator==(StringField other) {
  return this->value == other.get_value();
}
}
