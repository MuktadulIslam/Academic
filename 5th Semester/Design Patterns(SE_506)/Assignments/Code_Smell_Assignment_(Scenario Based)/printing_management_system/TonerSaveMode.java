package printing_management_system;

public class TonerSaveMode extends PrintMode{
    //        color intensity
//    Refused Bequest Smell (used only boost method)
//    Duplicated code Smell (used same types 3 algorithms)


    private double tonerSavingLevel;
    @Override
    public void saveToner() {
        if(tonerSavingLevel >= Constants.HIGH_TONE){
//            Reduce color intensity using algorithm-1
        }
        else if(tonerSavingLevel >=Constants.MEDIUM_TONE){
            //            Reduce color intensity using algorithm-2
        }
        else if(tonerSavingLevel < Constants.LOW_TONE){
            //            Reduce color intensity using algorithm-3
        }
    }

    @Override
    public void savePage() {

    }

    @Override
    public void boost() {

    }
}
