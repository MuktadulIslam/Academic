package arg_manager_ByStrategyP;

import minidb.xmlParser.RegistryFile;

public class ListArg implements ArgumentStrategy{
    @Override
    public boolean isEqual(String arg) {
        return arg.equals("list");
    }

    @Override
    public void executeCMD(String inputCMD) {
        RegistryFile registry = RegistryFile.getInstance();
        registry.listAllDatabases();
    }
}
