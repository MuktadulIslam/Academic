package Computer_Builder;

public class Computer implements Computer_design{

    private String ram;
    private String hdd;
    private String cpu;
    private String monitor;

    public void set_ram(String ram) {
        this.ram=ram;

    }


    public void set_hdd(String hdd) {
       this.hdd=hdd;
    }

    public void set_cpu(String cpu) {
       this.cpu=cpu;
    }

    public void set_monitor(String monitor) {
      this.monitor=monitor;
    }
}
