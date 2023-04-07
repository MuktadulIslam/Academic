package observer_Pattern_Implementation_assignment;

public abstract class Observer {
    public void update(String information) {
        System.out.println(this.getClass().getSimpleName() + " is get updated by \"" + information + "\"");
    }
}
