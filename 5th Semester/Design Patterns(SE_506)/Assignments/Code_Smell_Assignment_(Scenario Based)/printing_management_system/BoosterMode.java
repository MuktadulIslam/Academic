package printing_management_system;

public class BoosterMode extends PrintMode{
//    color intensity
//    Refused Bequest Smell (used only boost method)
    private double intensityThreshold;

    @Override
    public void saveToner() {

    }

    @Override
    public void savePage() {

    }

    @Override
    public void boost() {
//        increases the color intensity up to a maximum acceptable level that is set via its intensityThreshold field.
    }
}
