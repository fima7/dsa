// Copyright 2016, Konstantin Pachuev
#ifndef COLORMOD_HPP
#define COLORMOD_HPP
#include <ostream>
namespace color {

enum class code {
    FG_RED      = 31,
    FG_GREEN    = 32,
    FG_BLUE     = 34,
    FG_DEFAULT  = 39,
    BG_RED      = 41,
    BG_GREEN    = 42,
    BG_BLUE     = 44,
    BG_DEFAULT  = 49
};

class modifier {
 public:
  explicit modifier(code c) : m_code(c) {}
  friend std::ostream & operator << (std::ostream & os, const modifier & mod) {
    return os << "\033[" << static_cast<int>(mod.m_code) << "m";
  }
 private:
  code m_code;
};
}  // namespace color
#endif
