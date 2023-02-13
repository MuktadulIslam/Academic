package arg_manager_ByStrategyP;
import minidb.xmlParser.DatabaseFile;
import minidb.xmlParser.RegistryFile;

public class NewArg implements ArgumentStrategy{
    @Override
    public boolean isEqual(String arg) {
        return arg.equals("new");
    }

    @Override
    public void executeCMD(String inputCMD) {
        String[] cmdArgs = inputCMD.split(" ");

        RegistryFile registry = RegistryFile.getInstance();
        registry.createNewDatabase(cmdArgs[1]);
    }
}
