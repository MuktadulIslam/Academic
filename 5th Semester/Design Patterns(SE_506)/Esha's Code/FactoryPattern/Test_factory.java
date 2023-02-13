package FactoryPattern;

public class Test_factory {
    public static void main(String[] args) {

        Computer laptop= Computer_factory.get_computer("Laptop", "8 GB","500 GB internal storage drive","Intel Core i5 (sixth generation)");
        System.out.println(laptop);
        //laptop.get_build_notofication();
        Computer desktop=Computer_factory.get_computer("Desktop","16 GB","1 TB internal HDD","Intel Core i5 (sixth generation or newer)");
        System.out.println(desktop);
        }
    }

