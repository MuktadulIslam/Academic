package Singleton;

public class Employee {
    private final String name;
    private final String post;
    private final String task;
    public Employee(String name, String post,String task) {
        this.name = name;
        this.task = task;
        this.post=post;
    }
    public void printCurrentAssignment(){
        Printer printer = Printer.getInstance();

        printer.print(name+ "("+post+")"+" : "+task);

    }
}
