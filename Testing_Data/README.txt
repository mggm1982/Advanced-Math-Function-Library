ADVANCED MATH FUNCTION LIBRARY — TESTING DATA

Purpose:
This folder contains sample test cases for the 17 operations in the C++ project.

Files:
- CSV files 01–16 contain valid input values and expected outputs.
- 17_Invalid_Input_Tests.csv contains selected invalid-input checks.

How to use:
1. Open the CSV file for the function you want to test.
2. Enter the input values in your C++ program.
3. Compare the program's output with the expected output.
4. Record PASS if they match; otherwise record FAIL and investigate.

Important:
This is a testing dataset, not machine-learning training data. The expected outputs
are reference values for checking the program.

Notes:
- Square-root results are approximate; compare to a suitable decimal tolerance.
- Quadratic roots may be printed in a different order while still being correct.
- The code's prime-listing function uses trial division (not the Sieve of Eratosthenes),
  despite the menu label saying "Sieve".
- These cases do not test every possible input or integer-overflow condition.
