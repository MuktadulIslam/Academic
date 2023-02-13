package FactoryPattern;

public class Laptop extends Computer{

        private String ram;
        private String storage;
        private String cpu;

        Laptop(String ram, String storage,String cpu){
            this.ram=ram;
            this.storage=storage;
            this.cpu=cpu;
        }

        @Override
        public String  get_configuration()
        {
            return ram+" "+storage+" "+cpu;
        }

        @Override
        public String get_build_notofication()
        {
           return "Laptop has been built\n";
        }
    }


