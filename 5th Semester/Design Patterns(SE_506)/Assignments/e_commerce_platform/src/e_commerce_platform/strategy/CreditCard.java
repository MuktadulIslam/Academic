package e_commerce_platform.strategy;

public class CreditCard extends OnlinePayment{
    @Override
    public boolean makeOnlinePayment(double totalCost) {
        System.out.println("Starting online payment by \"Credit Card\"");
        return super.makeOnlinePayment(totalCost);
    }
}
