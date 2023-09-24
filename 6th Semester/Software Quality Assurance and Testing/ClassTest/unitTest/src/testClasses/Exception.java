package testClasses;

class InvalidNumberException extends RuntimeException {
    public InvalidNumberException(String message) {
        super(message);
    }
}