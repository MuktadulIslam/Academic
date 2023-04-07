package command_line_files;

import java.util.ArrayList;
import java.util.Scanner;

import Constants.Constants;
import arg_manager_ByStrategyP.*;
import minidb.xmlParser.DatabaseFile;
import minidb.xmlParser.RegistryFile;

public class CLI {

    static DatabaseFile CurrentDb;
    static RegistryFile registry;
    ArrayList <ArgumentStrategy> strategies = new <ArgumentStrategy>ArrayList();
    {
        strategies.add(new AddArg());
        strategies.add(new DeleteArg());
        strategies.add(new DropArg());
        strategies.add(new HelpArg());
        strategies.add(new InfoArg());
        strategies.add(new ListArg());
        strategies.add(new NewArg());
        strategies.add(new ReadArg());
        strategies.add(new SchemaArg());
        strategies.add(new UpdateArg());
        strategies.add(new UseArg());
    }

    public void startCLI(){
        System.out.println(Constants.HEADING);
        registry = RegistryFile.getInstance();
        Scanner input = new Scanner(System.in);

        while (true) {
            System.out.print(Constants.CMD_PREFIX);

            String currentCmd = input.nextLine();

            // break if user wants to exit
            if (currentCmd.equals("exit;")) {
                break;
            }
            long startTime = System.nanoTime();
            clientInput(currentCmd);
            long endTime = System.nanoTime();

            long exeTime = (endTime - startTime) / 1000000;
            System.out.println("\nExecution Time: " + exeTime + "ms");
        }

        input.close();
    }



    void clientInput(String input) {

        String[] cmdArgs = input.split(" ");
        for (ArgumentStrategy strategy : strategies) {
            if (strategy.isEqual(cmdArgs[0])) {
                strategy.executeCMD(cmdArgs[1]);
                return;
            }
        }

        System.out.println("UNKNOWN COMMAND: " + cmdArgs[0] + "\nType `help;` for commands list");
    }

    public static void setDBFile(DatabaseFile database) {
        CurrentDb = database;
    }

    public static DatabaseFile getDBFile() {
        return CurrentDb;
    }



}

