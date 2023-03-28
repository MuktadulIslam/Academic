package e_commerce_platform.template;

public abstract class OnlinePaymentTemplate {
    protected double balance = 0.0;

    protected final boolean makePayment(double totalCost) {
        if(totalCost > balance) {
            sendNotification("Currently you do not have sufficient balance!!!");
            return false;
        }
        else{
            balance -= totalCost;
            return true;
        }
    }

    public abstract void sendNotification(String notification);
}
