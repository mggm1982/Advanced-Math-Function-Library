ADVANCED MATH FUNCTION LIBRARY — TRAINING DATA

Purpose
This folder contains example input-output records for demonstrating and practising
the 17 mathematical operations in the C++ project.

How to use
1. Open the CSV file for the operation you want to demonstrate.
2. Enter the input values into the corresponding menu option in the C++ program.
3. Compare the program's result with the expected output.
4. Use these examples to understand the input format and expected mathematical result.

Files
- Files 01–16 contain sample input values and expected outputs.
- Each CSV file has a header row describing its columns.

Important clarification
This C++ project is a deterministic mathematical program, not a machine-learning model.
Therefore, these files are example/reference data for demonstrations and practice;
they are not data used to train an AI model. The separate Testing_Data folder is for
checking program correctness with test cases.

Notes
- Square-root values are approximate; allow a small decimal tolerance.
- Quadratic roots may appear in a different order and still be correct.
- The program's menu says "Sieve" for prime listing, but its current implementation
  checks divisors directly rather than using the Sieve of Eratosthenes.
