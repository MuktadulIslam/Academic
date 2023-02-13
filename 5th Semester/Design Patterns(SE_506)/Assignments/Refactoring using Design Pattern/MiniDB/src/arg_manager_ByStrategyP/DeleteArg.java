package arg_manager_ByStrategyP;

import Constants.Constants;
import command_line_files.CLI;
import minidb.xmlParser.DatabaseFile;

public class DeleteArg implements ArgumentStrategy{
    @Override
    public boolean isEqual(String arg) {
        return arg.equals("drop");
    }

    @Override
    public void executeCMD(String inputCMD) {
        DatabaseFile currentDb = CLI.getDBFile();
        String[] cmdArgs = inputCMD.split(" ");

        if (currentDb != null) {
            currentDb.deleteData(cmdArgs[1]);
        } else {
            System.out.println(Constants.NO_DATABASE_SELECTED);
        }
    }
}
