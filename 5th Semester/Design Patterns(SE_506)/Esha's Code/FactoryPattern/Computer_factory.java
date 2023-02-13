package FactoryPattern;

public class Computer_factory
{
    public static Computer get_computer(String type, String ram,String storage,String cpu)
    {
       switch (type)
       {
           case "Laptop" :
               return new Laptop(ram, storage, cpu);
           case "Desktop" :
               return new Desktop(ram, storage, cpu);
           case "Server" :
               return new Server(ram, storage, cpu);

           default:
               throw new IllegalArgumentException("Unknown type "+type);

       }
    }
}
