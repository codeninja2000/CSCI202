// Program name: romantype.h
// Author: Grant Simpson
// Date last updated: 03/22/2025
// Purpose: RomanType class declaration.


#ifndef ROMANTYPE
#define ROMANTYPE

#include <string>

class RomanType
{
public:
    // Constructor.
    // Throws an invalid argument exception if it is passed
    // an ill-formed roman numeral
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

    // Function to print decimal
    void printDecimal() const;
    // Function to print roman numeral
    void printRomanNumeral() const;

    // Function to indicate if there was a conversion error
    bool conversionError() const;
    // Function to reset error flag
    void resetConversionError();


private:
    std::string m_roman; // stores roman numeral
    int m_decimal;       // stores decimal
    bool m_conversionError; // indicates an error
    bool isValidRomanNumeral(std::string_view roman); // validates roman numeral
};

#endif // ROMANTYPE_H