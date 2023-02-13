package arg_manager_ByStrategyP;

import minidb.xmlParser.RegistryFile;

public class DropArg implements ArgumentStrategy{
    @Override
    public boolean isEqual(String arg) {
        return arg.equals("drop");
    }

    @Override
    public void executeCMD(String inputCMD) {
        String[] cmdArgs = inputCMD.split(" ");
        RegistryFile registry = RegistryFile.getInstance();
        registry.deleteDatabase(cmdArgs[1]);
    }
}
