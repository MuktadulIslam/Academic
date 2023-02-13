package arg_manager_ByStrategyP;

import Constants.Constants;
import command_line_files.CLI;
import minidb.xmlParser.DatabaseFile;

public class ReadArg implements ArgumentStrategy{
    @Override
    public boolean isEqual(String arg) {
        return arg.equals("read");
    }

    @Override
    public void executeCMD(String inputCMD) {
        String[] cmdArgs = inputCMD.split("");

        DatabaseFile currentDb = CLI.getDBFile();
        if (currentDb != null) {
            if (cmdArgs.length == 1) {
                currentDb.readData();
            } else {
                currentDb.readData(cmdArgs[1]);
            }
        } else {
            System.out.println(Constants.NO_DATABASE_SELECTED);
        }
    }
}
