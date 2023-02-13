package Singleton;

 public class Printer {
    private static Printer printer=null;
    private int nrOfPages;
    private Printer() {
    }
    public static Printer getInstance() {

        if(printer==null)
            printer= new Printer();

        return printer;
       // return printer == null ? printer = new Printer() : printer;
    }
    public void print(String text){
        // print something
        System.out.println(text);
    }
}
