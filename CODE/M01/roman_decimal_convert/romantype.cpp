#include "romantype.h"

#include <iostream>
#include <regex>
#include <stdexcept>
#include <string_view>

RomanType::RomanType(std::string romanNumeral)
    : m_roman{romanNumeral}, m_decimal{0} {
  if (!isValidRomanNumeral(romanNumeral))
    throw std::invalid_argument("Non roman symbol encountered.");
}

void RomanType::setRoman(std::string &romanNumeral) {
  if (!isValidRomanNumeral(romanNumeral))
    throw std::invalid_argument("Non roman symbol encountered.");
}

void RomanType::romanToDecimal() {
  std::string romanNum{m_roman};
  std::reverse(romanNum.begin(), romanNum.end());
  int dec{0};
  for (auto &c : romanNum) {
    switch (c) {
      case 'I':
        dec += (dec >= 5 ? -1 : 1);
        break;
      case 'V':
        dec += dec + 5;
        break;
      case 'X':
        dec += 10 * (dec >= 50 ? -1 : 1);
        break;
      case 'L':
        dec += 50;
        break;
      case 'C':
        dec += 100 * (dec >= 500 ? -1 : 1);
        break;
      case 'D':
        dec += 500;
        break;
      case 'M':
        dec += 1000;
        break;
      default:
        dec = -1;  //
        break;
    }
  }
  m_decimal = dec;
}

void RomanType::printDecimal() const { std::cout << m_decimal << std::endl; }
void RomanType::printRomanNumeral() const { std::cout << m_roman << std::endl; }

bool RomanType::isValidRomanNumeral(std::string_view roman) {
  static const std::regex pattern(
      R"((^(?=[MDCLXVI])M*(C[MD]|D?C{0,3})(X[CL]|L?X{0,3})(I[XV]|V?I{0,3})$))");
  return std::regex_match(roman.data(), pattern);
}