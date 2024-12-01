#include "13_1.h"

// Helper function to print results
void printTestResult(const Verylong& result, const wchar_t* expected, const wchar_t* testName) {
    wchar_t temp[SIZE];
    wcscpy(temp, L"");
    result.put();
    wcout << L" (" << testName << L") - Expected: " << expected << endl;
}

void testEdgeCases() {
    wcout << L"Testing edge cases:" << endl;

    // Test with very large numbers
    Verylong num1(L"999999999999999999999999999999");
    Verylong num2(L"1");
    Verylong sum = num1 + num2;
    printTestResult(sum, L"1000000000000000000000000000000", L"Very large addition");

    // Test subtraction that causes negative result
    Verylong num3(L"100");
    Verylong num4(L"200");
    Verylong diff = num3 - num4;
    printTestResult(diff, L"-100", L"Negative result subtraction");

    // Test multiplication by zero
    Verylong num5(L"12345678901234567890");
    Verylong zero(L"0");
    Verylong product = num5 * zero;
    printTestResult(product, L"0", L"Multiplication by zero");

    // Test division by a larger number
    Verylong num6(L"100");
    Verylong num7(L"1000");
    Verylong quotient = num6 / num7;
    printTestResult(quotient, L"0", L"Division by larger number");

    // Test division by zero (should handle gracefully)
    try {
        Verylong result = num6 / zero;
        wcout << L"Division by zero test failed (no exception thrown)" << endl;
    } catch (...) {
        wcout << L"Division by zero test passed (exception thrown)" << endl;
    }

    // Test leading zeros
    Verylong num8(L"0000123");
    Verylong num9(L"77");
    Verylong cleanSum = num8 + num9;
    printTestResult(cleanSum, L"200", L"Addition with leading zeros");

    // Test negative number multiplication
    Verylong negNum(L"-123456789");
    Verylong posNum(L"10");
    Verylong negProduct = negNum * posNum;
    printTestResult(negProduct, L"-1234567890", L"Negative number multiplication");

    // Test comparison of very large and very small numbers
    Verylong largeNum(L"123456789012345678901234567890");
    Verylong smallNum(L"1");
    int comparison = largeNum.compare(smallNum);
    wcout << L"Comparison test (1 if larger): " << comparison << L" - Expected: 1" << endl;

    // Test with single-digit numbers
    Verylong singleDigit1(L"5");
    Verylong singleDigit2(L"3");
    Verylong singleSum = singleDigit1 + singleDigit2;
    printTestResult(singleSum, L"8", L"Single-digit addition");
}

int main13_11() {
    wcout << L"Running stress tests for Verylong class:" << endl;
    testEdgeCases();
    return 0;
}
