package testClasses;

public class MyNumber {
    public boolean isPrime(int number) {
        // Handle special cases for numbers less than 2
        if (number < 2) {
            throw new InvalidNumberException("Invalid number: Number cannot be less than 2.");
        }
        // Check for divisibility from 2 to the square root of the number
        for (int i = 2; i <= Math.sqrt(number); i++) {
            if (number % i == 0) {
                return false; // It's divisible, so not prime
            }
        }
        return true; // It's prime
    }

    public long calculateFactorial(int num) {
        if (num < 0) {
            throw new InvalidNumberException("Invalid number: Number cannot be negative.");
        } else if (num <= 1) {
            return 1; // Factorial of 0 and 1 is 1
        }

        long factorial = 1;
        for (int i = 2; i <= num; i++) {
            factorial *= i;
        }

        return factorial;
    }

    public int calculateGCD(int num1, int num2) {
        if (num1 == 0) return num2;
        if (num2 == 0) return num1;

        int l, s, r;
        if (num1 < 0) num1 = -num1;
        if (num2 < 0) num2 = -num2;

        if (num1 > num2) {
            l = num1;
            s = num2;
        } else {
            l = num2;
            s = num1;
        }

        r = l % s;
        while (r != 0) {
            l = s;
            s = r;
            r = l % s;
        }
        return s; // Ensure the result is positive
    }

    public int calculateLCM(int num1, int num2) {
        int l, s, r;
        if (num1 < 0 || num2 < 0) {
            throw new InvalidNumberException("Invalid number: Numbers cannot be negative.");
        } else if (num1 == 0 || num2 == 0) return 0;

        if (num1 > num2) {
            l = num1;
            s = num2;
        } else {
            l = num2;
            s = num1;
        }

        r = l % s;
        while (r != 0) {
            l = s;
            s = r;
            r = l % s;
        }
        return num1 * num2 / s; // Ensure the result is positive
    }

    public int abs(int number) {
        if(number>=0) return number;
        else return -number;
    }

    public double roundUp(double num) {
        if (num > 0.0) {
            long num2 = (long) num;
            if (num - num2 == 0.0) return num;
            else return num2 + 1;
        } else {
            return (long) num;
        }
    }

    public double roundDown(double num) {
        long num2 = (long) num;
        if (num - num2 == 0.0) return num;
        if (num > 0.0) {
            return num2;
        } else {
            return ((long) num) - 1;
        }
    }

    public double round(double num) {
        long num2 = (long) num;
        if (num - num2 == 0.0) return num;
        else if (num > 0.0) {
            if (num - num2 >= 0.5) return num2 + 1;
            else return num2;
        } else {
            if (num2 - num >= 0.5) return num2 - 1;
            else return num2;
        }
    }
}






