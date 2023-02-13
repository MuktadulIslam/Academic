package observerPattern;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Random;

public class ClockTimer implements Subject {
    ArrayList <Observer> observerArray = new <Observer> ArrayList();
    Random random = new Random();
    @Override
    public void attach(Observer observer) {
        observerArray.add(observer);
        System.out.println(observer.getClass().getName() + " is successfully attach in " + this.getClass().getName());
    }

    @Override
    public void detach(Observer observer) {
        observerArray.remove(observer);
        System.out.println(observer.getClass().getName() + " is successfully attach in " + this.getClass().getName());
    }

    @Override
    public void notifyA() {
        int hour = getHour();
        int min = getMin();
        int sec = getSec();

        System.out.println("Notifying all Clocks");
        for (Observer observer : observerArray){
            observer.update(hour,min,sec);
        }
    }

    private int getMin() {
        return random.nextInt(60);
    }
    private int getSec() {
        return random.nextInt(60);
    }
    private int getHour() {
        return random.nextInt(24);
    }
}
