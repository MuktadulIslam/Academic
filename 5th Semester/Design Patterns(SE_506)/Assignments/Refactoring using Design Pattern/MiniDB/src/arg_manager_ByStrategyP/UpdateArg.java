package arg_manager_ByStrategyP;

import command_line_files.CLI;
import minidb.xmlParser.DatabaseFile;

public class UpdateArg implements ArgumentStrategy{
    @Override
    public boolean isEqual(String arg) {
        return arg.equals("drop");
    }

    @Override
    public void executeCMD(String inputCMD) {
        DatabaseFile currentDb = CLI.getDBFile();
        // TODO
        if (currentDb != null) {
        }
    }
}
