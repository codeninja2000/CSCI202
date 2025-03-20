# roman2decimal 

## Description
Conversion utility program to convert a roman numeral to decimal. The program's input is 
case insensitive, for example "MMXXV" and "mmxxv" are equivalent representations of the number 2025.

### Conversion Rules
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