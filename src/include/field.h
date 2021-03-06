#pragma once

namespace buzzdb {
/**
 * The Field abstract class is an interface for a field in a tuple.
 */
class Field {
 public:
  /**
   * Available field types.
   */
  enum Type {NO_TYPE, INTEGER, STRING};

  /**
   * Destructor.
   * It is necessary for an interface class to have a virtual destructor to
   * ensure correct polymorphic deletion.
   */
  virtual ~Field() = 0;

  /**
   * Returns the type of the Field.
   * 
   * Consider restructuring:
   * https://stackoverflow.com/questions/34516232/enum-as-class-member-function-with-return-value
   */
  virtual Type get_type() const = 0;

  /**
   * Write the bytes representing the field to the specified Stream.
   */
  /*
    virtual void serialize(DataOutputStream dos) = 0;
  */

  /**
   * Compares the value of the Field to the value of operand.
  virtual bool Compare(Predicate::OpType op_type, Field * operand) = 0;
   */

  /**
   * Prints the field's contents.
   */
  virtual void Print() const = 0;

  virtual bool operator==(const Field & other) = 0;

  virtual bool operator!=(const Field & other) = 0;

  /**
   * Returns the number of bytes required to store a field of the respective
   * type.
   */
  static int get_length(Type type);

 private:
  static const int integer_length_in_bytes = 4;

  static const int string_length_in_bytes = 128;
};
}
