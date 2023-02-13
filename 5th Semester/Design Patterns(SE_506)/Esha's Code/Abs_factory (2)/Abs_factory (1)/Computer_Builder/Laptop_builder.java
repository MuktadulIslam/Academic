package Computer_Builder;

public class Laptop_builder implements Computer_Builder{

    private Computer computer;
    public  Laptop_builder()
    {
        this.computer=new Computer();
    }
    @Override
    public void build_ram() {
       computer.set_ram("8gb");
    }

    @Override
    public void build_hdd() {
       computer.set_hdd("512 gb");
    }

    @Override
    public void build_cpu() {
     computer.set_cpu("core i7");
    }

    @Override
    public void build_monitor() {
     computer.set_monitor("LED");
    }

    @Override
    public Computer  get_computer() {
        System.out.println("laptop created");
        return this.computer;
    }
}
