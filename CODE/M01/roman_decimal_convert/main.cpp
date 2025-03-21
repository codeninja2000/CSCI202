// Program name: main.cpp
// Author: Grant Simpson
// Date last updated: 03/19/2025
// Purpose: Program to convert roman numerals to decimal. Makes use of the RomanType class.
#include "romantype.h"
#include <iostream>
#include <string>
#include <string_view>

using namespace std;

void printMenu();
void reset();
int readIntChoice(int upperBound);
void convertRomanToDecimal(RomanType &roman);
void displayRomanNumeral(const RomanType &roman);
void displayDecimal(const RomanType &roman);
int main()
{
    const int NUMBER_OF_MENU_ITEMS{3};
    RomanType romanNumeral{};

    printMenu();
    int choice{readIntChoice(NUMBER_OF_MENU_ITEMS)};
    cout << endl;
    while (true)
    {
        switch (choice)
        {
        case 1:
            convertRomanToDecimal(romanNumeral);
            break;
        case 2:
            displayRomanNumeral(romanNumeral);
            break;
        case 3:
            displayDecimal(romanNumeral);
            break;
        case -1:
            cout << "Goodbye." << endl;
            return 0;
        default:
            cout << "Not a valid choice." << endl;
            break;
        }
        printMenu();
        choice = readIntChoice(NUMBER_OF_MENU_ITEMS);
        cout << endl;
    }

    return 0;
}

void printMenu()
{
    cout << "1. Enter and Convert Roman Numeral to Decimal" << endl;
    cout << "2. Display Roman Numeral" << endl;
    cout << "3. Display Decimal" << endl;
    cout << "Choose an option (enter -1 to quit): ";
}

int readIntChoice(int upperBound)
{
    int choice{0};
    do
    {
        if (!cin)
            reset();
        cin >> choice;

        if ((!cin || choice < 1 || choice > upperBound) && choice != -1)
            cout << "Not a valid choice. Please try again." << endl;

    } while ((!cin || choice < 1 || choice > upperBound) && choice != -1);
    return choice;
}
void reset()
{
    cin.clear();
    cin.ignore(UINT_MAX, '\n');
}

void convertRomanToDecimal(RomanType &roman)
{
    try
    {
        string romanNum;
        cout << "Enter roman numeral: ";
        cin >> romanNum;
        roman.setRoman(romanNum);
    }
    catch (const invalid_argument &ia)
    {
        std::cerr << "Error - Invalid Argument: " << ia.what() << endl;
    }
    roman.convertToDecimal();
    if (roman.decimal() == -1)
        cout << "Error during conversion due to unknown symbol." << endl;
    else
        cout << roman.roman() << " = " << roman.decimal() << endl;
}

void displayRomanNumeral(const RomanType &roman)
{
    if (roman.decimal() == 0 || roman.decimal() == -1 || roman.roman() == "")
    {
        cout << "Nothing to display. Choose option 1 to convert a Roman Numeral." << endl
             << endl;
        return;
    }
    cout << roman.roman() << endl;
}

void displayDecimal(const RomanType &roman)
{
    if (roman.decimal() == 0 || roman.decimal() == -1 || roman.roman() == "")
    {
        cout << "Nothing to display. Choose option 1 to convert a Roman Numeral." << endl
             << endl;
        return;
    }
    cout << roman.decimal() << endl;
}