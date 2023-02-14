package observer_Pattern_Implementation_assignment;

import java.util.ArrayList;
public abstract class Subject {
    ArrayList<Observer> observerArray = new <Observer> ArrayList();
    public void attach(Observer observer) {
        observerArray.add(observer);
        System.out.println(observer.getClass().getName() + " is successfully attach in " + this.getClass().getName());
    }
    public void detach(Observer observer) {
        observerArray.remove(observer);
        System.out.println(observer.getClass().getName() + " is successfully attach in " + this.getClass().getName());
    }

    protected void notifyA(String information){
        System.out.println("\nNotifying all Clocks");
        for (Observer observer : observerArray){
            observer.update(information);
        }
    }
}
