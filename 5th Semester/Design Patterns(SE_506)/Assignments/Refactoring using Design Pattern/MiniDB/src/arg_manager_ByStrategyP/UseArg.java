package arg_manager_ByStrategyP;

import command_line_files.CLI;
import minidb.xmlParser.DatabaseFile;
import minidb.xmlParser.RegistryFile;

public class UseArg implements ArgumentStrategy{
    @Override
    public boolean isEqual(String arg) {
        return arg.equals("default");
    }

    @Override
    public void executeCMD(String inputCMD) {
        String[] cmdArgs = inputCMD.split(" ");
        RegistryFile registry = RegistryFile.getInstance();
        String path = registry.getDatabasePath(cmdArgs[1], false);

        if (path != null) {
            DatabaseFile currentDb = new DatabaseFile(path);
            currentDb.EditMode();

            CLI.setDBFile(currentDb);
            System.out.println("Successfully loaded Database named: " + cmdArgs[1]);
        } else {
            System.out.println("Database not found");
        }
    }
}
