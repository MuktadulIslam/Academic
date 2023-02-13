package Computer_Builder;

public class Builder_test {
    public static void main(String args[]) {

        Computer_Builder laptop = new Laptop_builder();
        Engineer engineer = new Engineer(laptop);

        engineer.construct();
        engineer.get_final_pc();

    }


}
