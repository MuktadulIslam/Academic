package observer_Pattern_Implementation_assignment;

public class Main {
    public static void main(String[] args) {
        // ConcreteSubject class
        TextFileUpdater textFileUpdater = new TextFileUpdater("file1.txt");

        // ConcreteObserver class
        AllChange allChange = new AllChange();
        CurrentChange currentChange = new CurrentChange();

        textFileUpdater.attach(allChange);
        textFileUpdater.attach(currentChange);

        textFileUpdater.createFile();
        textFileUpdater.updateFile("abc");

        textFileUpdater.detach(allChange);
        textFileUpdater.deleteFile();


    }
}
