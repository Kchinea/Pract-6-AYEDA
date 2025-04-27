#ifndef NIF_H_
#define NIF_H_

#include <iostream>
#include <iostream>
#include <stdexcept>
#include <cmath>

class NIF
{
public:
  NIF();
  NIF(const std::string &nif_str);

  long getNumber() const;

  long operator[](int) const;
  bool operator==(const NIF &) const;
  bool operator!=(const NIF &) const;
  bool operator<(const NIF &) const;
  bool operator>(const NIF &) const;
  long unsigned int size() const;

  operator long() const;

  friend std::istream &operator>>(std::istream &is, NIF &nif);

private:
  long nif_number_;
};

#endif