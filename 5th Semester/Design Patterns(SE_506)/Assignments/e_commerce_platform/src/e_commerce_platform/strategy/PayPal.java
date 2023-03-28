package e_commerce_platform.strategy;

public class PayPal extends OnlinePayment{
    @Override
    public boolean makeOnlinePayment(double totalCost) {
        System.out.println("Starting online payment by \"PayPal\"");
        return super.makeOnlinePayment(totalCost);
    }
}
