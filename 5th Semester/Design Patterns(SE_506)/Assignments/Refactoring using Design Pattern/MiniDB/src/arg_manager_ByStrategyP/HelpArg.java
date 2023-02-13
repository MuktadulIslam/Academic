package arg_manager_ByStrategyP;

import Constants.Constants;

public class HelpArg implements ArgumentStrategy{
    @Override
    public boolean isEqual(String arg) {
        return arg.equals("help");
    }

    @Override
    public void executeCMD(String inputCMD) {
        System.out.println(Constants.HELP_COMMANDS);
    }
}
