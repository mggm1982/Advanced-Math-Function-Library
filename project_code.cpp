#include <iostream>
using namespace std;

// ---------------------------------------------------------
// 1. Basic helpers
// ---------------------------------------------------------
double absolute(double x) {
    return (x < 0) ? -x : x;
}

// Square root using Newton-Raphson (no <cmath>)
double squareRoot(double x) {
    if (x == 0) return 0;
    double guess = x / 2.0;
    for (int i = 0; i < 50; i++) {                // first 50 terms
        guess = (guess + x / guess) / 2.0;
    }
    return guess;
}

// ---------------------------------------------------------
// 2. Factorial, permutation, combination
// ---------------------------------------------------------
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) result *= i;
    return result;
}

long long permutation(int n, int r) {
    // nPr = n * (n-1) * ... * (n-r+1)  (avoids computing full factorials)
    long long result = 1;
    for (int i = 0; i < r; i++) result *= (n - i); //  == result*(n-i)
    return result;
}

long long combination(int n, int r) {
    if (r > n - r) r = n - r;          // nCr = nC(n-r)
    long long result = 1;
    for (int i = 0; i < r; i++) {  // nCr == n!/r!*(n-r)! == n*(n-1).....(n+1-r)/r!
        result = result * (n - i) / (i + 1);   // stays an exact integer each step
    }
    return result;
}

// ---------------------------------------------------------
// 3. Sequences
// ---------------------------------------------------------
long long fibonacci(int n) {
    long long a = 0, b = 1;
    for (int i = 0; i < n; i++) { // in the Tn = Tn-1 + Tn-2
        long long next = a + b;
        a = b;
        b = next;
    }
    return a;
}

// ---------------------------------------------------------
// 4. Powers and modular arithmetic
// ---------------------------------------------------------
long long power(long long base, int exp) {
    long long result = 1;
    while (exp > 0) {    // after the division by 2 it became <1
        if (exp % 2 == 1) result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}

long long modPower(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// ---------------------------------------------------------
// 5. GCD, LCM, primes
// ---------------------------------------------------------
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;  // a>b   then 2b>a then the reminder will be a-b
        a = t;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;  // a*b == p*k*c^2 if i want lcm then a*b/c and you c = gcd
}

bool isPrime(long long n) {
    if (n < 2) return false;
    if (n < 4) return true;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void printPrimesUpTo(int n) {
    int count = 0;

    for (int i = 2; i <= n; i++) {
        bool prime = true;

        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                prime = false;
                break;
            }
        }

        if (prime) {
            cout << i << " ";
            count++;
        }
    }

    cout << "\n(" << count << " primes found)\n";
}

// ---------------------------------------------------------
// 6. Digit-based functions
// ---------------------------------------------------------
int sumOfDigits(long long n) {
    if (n < 0) n = -n;
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

long long reverseNumber(long long n) {
    long long rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

bool isPalindrome(long long n) { // 151 or 116911 this are the palindrome number 
    return n == reverseNumber(n);
}

bool isArmstrong(long long n) {
    long long original = n;
    int digits = 0;
    for (long long t = n; t > 0; t /= 10) digits++; //  153 == 1^3 + 5^3 + 3^3 == 153
    long long sum = 0;
    while (n > 0) {
        sum += power(n % 10, digits);
        n /= 10;
    }
    return sum == original;
}

// ---------------------------------------------------------
// 7. Other number properties
// ---------------------------------------------------------
bool isPerfect(int n) {
    if (n < 2) return false;
    int sum = 1;
    for (int i = 2; i * i <= n; i++) {  // 28 proper divisors are 1,2,4,7,14 
        if (n % i == 0) {
            sum += i;
            if (i != n / i) sum += n / i;
        }
    }
    return sum == n;
}

// Solve ax^2 + bx + c = 0
void solveQuadratic(double a, double b, double c) {
    if (a == 0) {
        cout << "Not a quadratic equation (a cannot be 0).\n";
        return;
    }
    double d = b * b - 4 * a * c;
    if (d > 0) {
        double s = squareRoot(d);
        cout << "Two real roots: " << (-b + s) / (2 * a)
             << " and " << (-b - s) / (2 * a) << endl;
    } else if (d == 0) {
        cout << "One repeated root: " << -b / (2 * a) << endl;
    } else {
        double real = -b / (2 * a);
        double imag = squareRoot(-d) / (2 * a);
        cout << "Complex roots: " << real << " + " << absolute(imag) << "i and "
             << real << " - " << absolute(imag) << "i\n";
    }
}

// ---------------------------------------------------------
// Menu and input helpers
// ---------------------------------------------------------
void showMenu() {
    cout << "\n===== ADVANCED MATH FUNCTION LIBRARY =====\n";
    cout << " 1. Factorial (n!)\n";
    cout << " 2. Permutation (nPr)\n";
    cout << " 3. Combination (nCr)\n";
    cout << " 4. Fibonacci (nth term)\n";
    cout << " 5. Power (base^exp)\n";
    cout << " 6. Modular Power (base^exp % mod)\n";
    cout << " 7. GCD\n";
    cout << " 8. LCM\n";
    cout << " 9. Prime Check\n";
    cout << "10. Primes up to N (Sieve)\n";
    cout << "11. Sum of Digits\n";
    cout << "12. Reverse Number\n";
    cout << "13. Palindrome Check\n";
    cout << "14. Armstrong Number Check\n";
    cout << "15. Perfect Number Check\n";
    cout << "16. Square Root\n";
    cout << "17. Quadratic Equation Solver\n";
    cout << " 0. Exit\n";
    cout << "Enter choice: ";
}

// Clears a bad input state (for example when the user types letters)
void clearBadInput() {
    cin.clear();
    cin.ignore(1000, '\n');
}

int main() {
    int choice;

    do {
        showMenu();
        if (!(cin >> choice)) {
            clearBadInput();
            cout << "Please enter a number from the menu.\n";
            choice = -1;
            continue;
        }

        switch (choice) {
        case 0:
            cout << "Goodbye!\n";
            break;

        case 1: {
            int n;
            cout << "Enter n (0 to 20): ";
            cin >> n;
            if (n < 0 || n > 20) cout << "Invalid: n must be between 0 and 20.\n";
            else cout << n << "! = " << factorial(n) << endl;
            break;
        }

        case 2: {
            int n, r;
            cout << "Enter n and r: ";
            cin >> n >> r;
            if (n < 0 || r < 0 || r > n || n > 20)
                cout << "Invalid: need 0 <= r <= n <= 20.\n";
            else cout << n << "P" << r << " = " << permutation(n, r) << endl;
            break;
        }

        case 3: {
            int n, r;
            cout << "Enter n and r: ";
            cin >> n >> r;
            if (n < 0 || r < 0 || r > n || n > 60)
                cout << "Invalid: need 0 <= r <= n <= 60.\n";
            else cout << n << "C" << r << " = " << combination(n, r) << endl;
            break;
        }

        case 4: {
            int n;
            cout << "Enter n (0 to 90): ";
            cin >> n;
            if (n < 0 || n > 90) cout << "Invalid: n must be between 0 and 90.\n";
            else cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
            break;
        }

        case 5: {
            long long base;
            int exp;
            cout << "Enter base and exponent (exponent >= 0): ";
            cin >> base >> exp;
            if (exp < 0) cout << "Invalid: exponent must be >= 0.\n";
            else cout << base << "^" << exp << " = " << power(base, exp)
                      << "  (may overflow for very large results)\n";
            break;
        }

        case 6: {
            long long base, exp, mod;
            cout << "Enter base, exponent, and modulus: ";
            cin >> base >> exp >> mod;
            if (exp < 0 || mod <= 0 || mod > 3000000000LL)
                cout << "Invalid: exponent >= 0 and 0 < modulus <= 3000000000.\n";
            else cout << "Result = " << modPower(base, exp, mod) << endl;
            break;
        }

        case 7: {
            long long a, b;
            cout << "Enter two numbers: ";
            cin >> a >> b;
            if (a < 0) a = -a;
            if (b < 0) b = -b;
            cout << "GCD = " << gcd(a, b) << endl;
            break;
        }

        case 8: {
            long long a, b;
            cout << "Enter two positive numbers: ";
            cin >> a >> b;
            if (a <= 0 || b <= 0) cout << "Invalid: both numbers must be positive.\n";
            else cout << "LCM = " << lcm(a, b) << endl;
            break;
        }

        case 9: {
            long long n;
            cout << "Enter a number: ";
            cin >> n;
            cout << n << (isPrime(n) ? " is prime.\n" : " is not prime.\n");
            break;
        }

        case 10: {
            int n;
            cout << "Enter N (2 to 10000): ";
            cin >> n;
            if (n < 2 || n > 10000) cout << "Invalid: N must be between 2 and 10000.\n";
            else printPrimesUpTo(n);
            break;
        }

        case 11: {
            long long n;
            cout << "Enter a number: ";
            cin >> n;
            cout << "Sum of digits = " << sumOfDigits(n) << endl;
            break;
        }

        case 12: {
            long long n;
            cout << "Enter a positive number: ";
            cin >> n;
            if (n < 0) cout << "Invalid: enter a non-negative number.\n";
            else cout << "Reversed = " << reverseNumber(n) << endl;
            break;
        }

        case 13: {
            long long n;
            cout << "Enter a non-negative number: ";
            cin >> n;
            if (n < 0) cout << "Invalid: enter a non-negative number.\n";
            else cout << n << (isPalindrome(n) ? " is a palindrome.\n" : " is not a palindrome.\n");
            break;
        }

        case 14: {
            long long n;
            cout << "Enter a positive number: ";
            cin >> n;
            if (n <= 0) cout << "Invalid: enter a positive number.\n";
            else cout << n << (isArmstrong(n) ? " is an Armstrong number.\n" : " is not an Armstrong number.\n");
            break;
        }

        case 15: {
            int n;
            cout << "Enter a positive number: ";
            cin >> n;
            if (n <= 0) cout << "Invalid: enter a positive number.\n";
            else cout << n << (isPerfect(n) ? " is a perfect number.\n" : " is not a perfect number.\n");
            break;
        }

        case 16: {
            double x;
            cout << "Enter a non-negative number: ";
            cin >> x;
            if (x < 0) cout << "Invalid: cannot take the square root of a negative number.\n";
            else cout << "Square root = " << squareRoot(x) << endl;
            break;
        }

        case 17: {
            double a, b, c;
            cout << "Enter a, b, c for ax^2 + bx + c = 0: ";
            cin >> a >> b >> c;
            solveQuadratic(a, b, c);
            break;
        }

        default:
            cout << "Invalid choice. Please pick 0 to 17.\n";
        }

        // If the user typed letters where a number was expected
        if (cin.fail()) {
            clearBadInput();
            cout << "Invalid input type. Please enter numbers only.\n";
        }

    } while (choice != 0);

    return 0;
}