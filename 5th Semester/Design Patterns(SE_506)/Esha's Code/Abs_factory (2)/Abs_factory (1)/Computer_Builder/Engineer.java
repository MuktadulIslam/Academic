package Computer_Builder;

public class Engineer {
    private Computer_Builder computer_builder;

    public  Engineer(Computer_Builder computer_builder)
    {
        this.computer_builder= computer_builder;
    }

    public Computer get_final_pc()
    {

        return this.computer_builder.get_computer();
    }

    public void construct ()
    {
        this.computer_builder.build_ram();
       this.computer_builder.build_hdd();
        this. computer_builder.build_cpu();
       this. computer_builder.build_monitor();
    }
}
