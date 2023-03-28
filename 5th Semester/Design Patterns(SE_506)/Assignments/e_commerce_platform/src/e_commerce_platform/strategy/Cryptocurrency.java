package e_commerce_platform.strategy;

public class Cryptocurrency extends OnlinePayment{
    @Override
    public boolean makeOnlinePayment(double totalCost) {
        System.out.println("Starting online payment by \"Cryptocurrency\"");
        return super.makeOnlinePayment(totalCost);
    }
}
