#ifndef ROMANTYPE
#define ROMANTYPE

#include <string>

class RomanType
{
public:
    RomanType(std::string romanNumeral = "");
    ~RomanType() {};

    // Getter for m_decimal.
    int decimal() const { return m_decimal; }
    // Getter for m_roman.
    std::string roman() const { return m_roman; }
    // Setter for m_roman
    void setRoman(std::string &romanNumeral);

    // Function to convert roman numerals to decimal.
    // A return code of -1 indicates a failure in parsing the roman numeral
    void convertToDecimal();

    void printDecimal() const;
    void printRomanNumeral() const;


private:
    std::string m_roman;
    int m_decimal;
    bool isValidRomanNumeral(std::string_view roman);
};

#endif // ROMANTYPE_H