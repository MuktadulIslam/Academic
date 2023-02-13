package Singleton;

public class Main {
    public static void main(String[] args) {
        Employee Esha = new Employee("Esha", "Developer","Developing a banking app");
        Employee Tasnia= new Employee("Tasnia","Tester","Testing software for quality assurance");

        Esha.printCurrentAssignment();
        Tasnia.printCurrentAssignment();
    }
}
