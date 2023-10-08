package testing;

import org.junit.jupiter.api.*;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;
import org.junit.jupiter.params.provider.ValueSource;
import testClasses.InvalidNumberException;

import java.math.BigInteger;

import static org.junit.jupiter.api.Assertions.*;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.junit.jupiter.api.DisplayName;
import testClasses.MyNumber;


@DisplayName("JUnitTestForMyNumber")
public class JUnitTestForMyNumber<num1, num2> {
    MyNumber myNumber = null;

    @BeforeEach
    void beforeEach() {
        myNumber = new MyNumber();
    }

    @AfterEach
    void afterEach() {
        myNumber = null;
    }

    @ParameterizedTest
    @ValueSource(ints = {2, 3, 37, Integer.MAX_VALUE})
    @DisplayName("Test with boundary value for isPrime() in MyNumber")
    void isPrimeTest_MyNumber(int number) {
        assertTrue(myNumber.isPrime(number));
    }

    @ParameterizedTest
    @DisplayName("Robustness testing for isPrime() in MyNumber")
    @ValueSource(ints = {1, Integer.MAX_VALUE + 1})
    void isPrimeRobustnessTest_MyNumber2(int number) {
        InvalidNumberException exception = assertThrows(InvalidNumberException.class, () -> myNumber.isPrime(number)); // Assuming -1 is an invalid number
        assertEquals("Invalid number: Number cannot be less than 2.", exception.getMessage());
    }

    @Test
    @DisplayName("Test for calculateFactorial() in MyNumber")
    void calculateFactorialTest_MyNumber() {
//        Boundary value checking
        assertEquals(1, myNumber.calculateFactorial(0));
        assertEquals(1, myNumber.calculateFactorial(1));
        assertEquals(39916800, myNumber.calculateFactorial(11));

//        Robustness testing
        InvalidNumberException exception = assertThrows(InvalidNumberException.class, () -> myNumber.calculateFactorial(-1));
        assertEquals("Invalid number: Number cannot be negative.", exception.getMessage());
    }

    @ParameterizedTest
    @CsvSource({"0,0", "0,1", "1,0", "367532,49376437", "353987,376", "2147483647,2783"})
    @DisplayName("Test for calculateGCD() in MyNumber")
    void calculateGCDTest_MyNumber(int num1, int num2) {
        BigInteger bigNum1 = new BigInteger(String.valueOf(num1));
        BigInteger bigNum2 = new BigInteger(String.valueOf(num2));

        BigInteger gcd = bigNum1.gcd(bigNum2);
        assertEquals(bigNum1.gcd(bigNum2).intValue(), myNumber.calculateGCD(num1, num2));
    }

    @ParameterizedTest
    @CsvSource({"1,1", "367532,49376437", "353987,376"})
    @DisplayName("Test with boundary value for calculateLCM() in MyNumber")
    void calculateLCMTest_MyNumber(int num1, int num2) {
        BigInteger bigNum1 = new BigInteger(String.valueOf(num1));
        BigInteger bigNum2 = new BigInteger(String.valueOf(num2));

        BigInteger gcd = bigNum1.gcd(bigNum2);
        assertEquals(num1*num2/(bigNum1.gcd(bigNum2).intValue()), myNumber.calculateLCM(num1, num2));
    }

    @ParameterizedTest
    @CsvSource({"-1,16", "10,-1", "2147483648,78","43,2147483648", "2147483648,2147483648"})
    @DisplayName("Robustness testing-1 for calculateLCM() in MyNumber")
    void calculateLCMRobustnessTest_MyNumber1(long num1, long num2) {
        InvalidNumberException exception = assertThrows(InvalidNumberException.class, () -> myNumber.calculateLCM((int)num1,(int)num2));
        assertEquals("Invalid number: Numbers cannot be negative.", exception.getMessage());
    }
    @ParameterizedTest
    @CsvSource({"0,0"})
    @DisplayName("Robustness testing-2 for calculateLCM() in MyNumber")
    void calculateLCMRobustnessTest_MyNumber2(int num1, int num2) {
        assertEquals(0, myNumber.calculateLCM(num1,num2));
    }


    @ParameterizedTest
    @ValueSource(ints = {-46543,1,0,Integer.MIN_VALUE,Integer.MAX_VALUE})
    @DisplayName("Test for abs() in MyNumber")
    void absTest_MyNumber(int number) {
        assertEquals(Math.abs(number), myNumber.abs(number));
    }

    @ParameterizedTest
    @ValueSource(doubles = {-46543.383, 46543.383, 46543.0, -46543.0, 125.745, -125.745})
    @DisplayName("Test for roundUp() in MyNumber")
    void roundUpTest_MyNumber(double number) {
        assertEquals(Math.ceil(number), myNumber.roundUp(number));
    }


    @ParameterizedTest
    @ValueSource(doubles = {-46543.383, 46543.383, 46543.0, -46543.0})
    @DisplayName("Test for roundDown() in MyNumber")
    void roundDownTest_MyNumber(double number) {
        assertEquals(Math.floor(number), myNumber.roundDown(number));
    }

    @ParameterizedTest
    @ValueSource(doubles = {-46543.383, 46543.383, 46543.0, -46543.0, 125.745, -125.745})
    @DisplayName("Test for round() in MyNumber")
    void roundTest_MyNumber(double number) {
        assertEquals(Math.round(number), myNumber.round(number));
    }

}