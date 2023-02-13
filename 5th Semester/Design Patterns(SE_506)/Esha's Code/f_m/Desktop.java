package FactoryPattern;

public class Desktop extends Computer{

        private String ram;
        private String storage;
        private String cpu;

    public Desktop() {
    }

//    @Override
//        public Computer get_pc(){
//            return new Desktop();
//        }
        @Override
        public String  get_configuration()
        {
            return ram+" "+storage+" "+cpu;
        }

        @Override
        public String get_build_notification()
        {
            return "Desktop has been built\n" ;
        }
    }




