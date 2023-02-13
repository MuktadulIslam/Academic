package arg_manager_ByStrategyP;

import Constants.Constants;
import minidb.xmlParser.DatabaseFile;
import command_line_files.CLI;

public class SchemaArg implements ArgumentStrategy{
    @Override
    public boolean isEqual(String arg) {
        return arg.equals("scheme");
    }

    @Override
    public void executeCMD(String inputCMD) {
        String[] cmdArgs = inputCMD.split(" ");

        DatabaseFile currentDb = CLI.getDBFile();

        if (currentDb != null) {
            String xy = cmdArgs[1];

            if (xy.equals("show")) {
                System.out.println(currentDb.getSchema());
            } else {
                String[] schemaVals = xy.split(",");
                if (schemaVals.length > 1) {
                    currentDb.createSchema(xy);
                } else {
                    System.out.println("There should be at least 2 columns of data");
                }
            }

        } else {
            System.out.println(Constants.NO_DATABASE_SELECTED);
        }
    }
}
