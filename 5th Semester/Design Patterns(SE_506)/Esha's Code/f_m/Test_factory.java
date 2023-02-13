package FactoryPattern;

public class Test_factory {
    public static void main(String[] args) {

        Computer_factory laptop= new Laptop_creator();
        Computer dell_laptop= laptop.get_pc();
        System.out.println(dell_laptop.get_build_notification());
        Computer_factory desktop=new Desktop_creator();
        Computer dell_desktop=desktop.get_pc();
       // System.out.println(desktop);
//        System.out.println(desktop.do_something());
        System.out.println(dell_desktop.get_build_notification());

        }
    }

