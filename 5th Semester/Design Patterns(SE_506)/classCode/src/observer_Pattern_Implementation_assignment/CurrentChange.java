package observer_Pattern_Implementation_assignment;

public class CurrentChange extends Observer{
    private String currentChanges;
    @Override
    public void update(String information) {
        currentChanges = information;
        super.update(information);
    }

    public String getCurrentChanges() {
        return currentChanges;
    }
}
