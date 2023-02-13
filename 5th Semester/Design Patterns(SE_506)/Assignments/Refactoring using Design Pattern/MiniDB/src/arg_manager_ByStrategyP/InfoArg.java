package arg_manager_ByStrategyP;

public class InfoArg implements ArgumentStrategy{
    @Override
    public boolean isEqual(String arg) {
        return arg.equals("info");
    }

    @Override
    public void executeCMD(String inputCMD) {
        // For querying the meta info of the database
        // TODO
    }
}
