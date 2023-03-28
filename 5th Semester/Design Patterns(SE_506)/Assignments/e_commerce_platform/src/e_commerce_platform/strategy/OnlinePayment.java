package e_commerce_platform.strategy;

import e_commerce_platform.template.OnlinePaymentTemplate;

public class OnlinePayment extends OnlinePaymentTemplate {
    @Override
    public void sendNotification(String notification) {
        System.out.println(notification);
    }

    public boolean makeOnlinePayment(double totalCost) {
        return this.makePayment(totalCost);
    }
}
