package arg_manager_ByStrategyP;
import Constants.Constants;
import minidb.xmlParser.DatabaseFile;
import command_line_files.CLI;

public class AddArg implements ArgumentStrategy{
    @Override
    public boolean isEqual(String arg) {
        return arg.equals("add");
    }

    @Override
    public void executeCMD(String inputCMD) {
        String[] cmdArgs = inputCMD.split(" ");

        DatabaseFile currentDb = CLI.getDBFile();
        if (currentDb != null) {
            currentDb.addData(cmdArgs[1]);
        } else {
            System.out.println(Constants.NO_DATABASE_SELECTED);
        }
    }
}
