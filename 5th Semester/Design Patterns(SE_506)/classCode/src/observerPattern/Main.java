package observerPattern;

public class Main {
    public static void main(String[] args) {
        Subject subject = new ClockTimer();
        DigitalClock digitalClock = new DigitalClock();
        subject.attach(digitalClock);
        subject.notifyA();
    }
}
