package observerPattern;

public class DigitalClock implements Observer{
    @Override
    public void update(int hour, int min, int sec) {
        System.out.println("Time: " + hour + " H    " + min + " Min     " + sec + " sec");
    }
}
