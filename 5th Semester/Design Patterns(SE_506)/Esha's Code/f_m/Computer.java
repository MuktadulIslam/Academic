package FactoryPattern;

public abstract class Computer {



    public abstract String get_configuration();

    public abstract String get_build_notification();

//    public abstract Computer get_pc();

    @Override
    public String toString(){
        return  get_build_notification()+ "RAM, HDD, CPU "+this.get_configuration();
    }
}
