package testing;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import testClasses.InvalidNumberException;
import testClasses.ResultCalculator;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

public class JUnitTestForResultCalculator {
    ResultCalculator resultCalculator = null;

    @BeforeEach
    void beforeEach() {
        resultCalculator = new ResultCalculator();
    }

    @AfterEach
    void afterEach() {
        resultCalculator = null;
    }

    @Test
    @DisplayName("Test with boundary value for getGPA() in MyNumber")
    void getGPATest_ResultCalculator() {
        assertEquals(3.50, resultCalculator.getGPA(73,100));
    }

    @Test
    @DisplayName("Robustness for getGPA() in MyNumber")
    void getGPARobustnessTest_ResultCalculator() {
        InvalidNumberException exception = assertThrows(InvalidNumberException.class, () -> resultCalculator.getGPA(102,100));
        assertEquals("Invalid Score or Total Marks: Score cannot be greater than Total Marks.", exception.getMessage());
    }

    @Test
    @DisplayName("Test with boundary value for getGPA() in MyNumber")
    void getGradeTest_ResultCalculator() {
        assertEquals("A-", resultCalculator.getGrade(73,100));
    }

    @Test
    @DisplayName("Robustness for getGPA() in MyNumber")
    void getGradeRobustnessTest_ResultCalculator() {
        InvalidNumberException exception = assertThrows(InvalidNumberException.class, () -> resultCalculator.getGrade(50.2,50));
        assertEquals("Invalid Score or Total Marks: Score cannot be greater than Total Marks.", exception.getMessage());
    }
}
