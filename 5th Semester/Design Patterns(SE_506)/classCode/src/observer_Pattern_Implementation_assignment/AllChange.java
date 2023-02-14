package observer_Pattern_Implementation_assignment;

public class AllChange extends Observer{
    String allChanges = "";
    @Override
    public void update(String information) {
        this.storeInfo(information);
        super.update(information);
    }

    private void storeInfo(String info){
        allChanges = allChanges + info + "\n";
    }

    public String getAllChanges() {
        return allChanges;
    }
}
