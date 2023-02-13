package FactoryPattern;

public abstract class Computer {



    public abstract String get_configuration();

    public abstract String get_build_notofication();

    @Override
    public String toString(){
        return  get_build_notofication()+ "RAM, HDD, CPU "+this.get_configuration();
    }
}
