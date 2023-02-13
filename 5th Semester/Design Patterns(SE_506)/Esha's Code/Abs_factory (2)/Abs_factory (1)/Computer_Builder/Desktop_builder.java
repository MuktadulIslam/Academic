package Computer_Builder;

public class Desktop_builder implements Computer_Builder {

    private  Computer computer;

    public Desktop_builder()
    {
        this.computer=new Computer();
    }

    @Override
    public void build_ram() {
     computer.set_ram("12 gb");
    }

    @Override
    public void build_hdd() {
        computer.set_hdd("1 TB");

    }

    @Override
    public void build_cpu() {
        computer.set_cpu("core i5");
    }

    @Override
    public void build_monitor() {
       computer.set_monitor("LED");
    }

    @Override
    public Computer get_computer() {
        return this.computer;
    }
}
