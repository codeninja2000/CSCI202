# roman_decimal_convert

## Description
Conversion utility program to convert a roman numeral to decimal. The program's input is
case sensitive, for example "MMXXV" is the correct representations of the number 2025 while "mmxxv" is not correct.


## Installation and Execution

### Prerequisites
- make 
- g++ 

On Windows, the prerequisites are available through MinGW or Cygwin. If you're on macOS or linux, the prerequisites are available through your favorite package manager.

1. Clone repository

     - Using https: `git clone https://github.com/codeninja2000/CSCI202.git`

     - Using ssh: `git@github.com:codeninja2000/CSCI202.git`

     - Using Github CLI: `gh repo clone codeninja2000/CSCI202`

2. Change to project folder
     - `cd <path/to/repo>/roman_decimal_convert`

3. Run make
     - `make`

4. Run executable


## Conversion Rules
- Due to the constraints below, the set of valid roman numerals is {1...3999}.
- When a symbol of smaller value appears after a symbol of greater value, its value will be added.
  - Example: XV = X + V = 10 + 5 = 15

- When a symbol of a smaller value appears before a symbol of greater value, its value will be subtracted.
  - Example: IV = V - I = 5 - 1 = 4

- A symbol can be repeated no more than three times.

- Symbols V, L, and D are never repeated.
  - Example of the number 15 incorrectly and correctly represented:
    - VVV &ensp; (incorrect)
    - XV &emsp; (correct)

- Symbols V, L, D are never subtracted since there is no scenario where that requires them to be written before a symbol with greater value.
  - Example of the number 45 incorrectly and correctly represented:
    - VL &emsp; (incorrect)
    - XLV &ensp; (correct)

- Symbol I can be subtracted from V and X only.

- Symbol X can be subtracted from L, M, and C only.

You can read more about the rules of roman numerals [here](https://www.cuemath.com/numbers/roman-numerals/)
## Author
Grant Simpson