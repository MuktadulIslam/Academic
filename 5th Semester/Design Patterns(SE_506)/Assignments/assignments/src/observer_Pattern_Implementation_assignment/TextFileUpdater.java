package observer_Pattern_Implementation_assignment;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class TextFileUpdater extends Subject{

    private String fileName;
    public TextFileUpdater(String fileName){
        this.fileName = fileName;
    }

    public void createFile(){
        try {
            File myObj = new File(fileName);
            if (myObj.createNewFile()) {
                this.notifyA("\"" + fileName + "\" is created.");
            } else {
                System.out.println("File already exists.");
            }
        } catch (IOException e) {
            System.out.println(e);
        }
    }
    public void updateFile(String appendedText){
        try {
            FileWriter myWriter = new FileWriter(fileName);
            myWriter.write(appendedText);
            myWriter.close();
            this.notifyA("\'" + appendedText + "\' add in file \'" + fileName + "\'");
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    public void deleteFile() {
        File myObj = new File(fileName);
        if (myObj.delete()) {
            this.notifyA("\"" + fileName + "\" deleted");
        } else {
            System.out.println("Failed to delete the file.");
        }
    }
}
