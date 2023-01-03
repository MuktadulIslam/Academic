package printing_management_system_after_refactor;

public class TonerSaveMode extends PrintMode {
    private double tonerSavingLevel;
    public void saveToner() {

        if(tonerSavingLevel >= Constants.HIGH_TONE){
            this.tonerSavingAlgorithm("high level");
        }
        else if(tonerSavingLevel >= Constants.MEDIUM_TONE){
            this.tonerSavingAlgorithm("medium level");
        }
        else {
            this.tonerSavingAlgorithm("low level");
        }
    }

    void tonerSavingAlgorithm(String level){
        // saving new toner using X algorithm
    }
}
