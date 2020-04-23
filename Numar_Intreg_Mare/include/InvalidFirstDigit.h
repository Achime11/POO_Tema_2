#include <exception>

class InvalidFirstDigit : public std::exception {
public:
  InvalidFirstDigit () noexcept {}
  InvalidFirstDigit (const InvalidFirstDigit&) noexcept = default;
  InvalidFirstDigit& operator= (const InvalidFirstDigit&) noexcept = default;
  virtual ~InvalidFirstDigit() noexcept = default;
  virtual const char* what() const noexcept {
    return "Invalid First Digit\n";
  }
};
