package e_commerce_platform.strategy;

import e_commerce_platform.mediator.ChatMediator;
import e_commerce_platform.mediator.MediatorUser;

public class Payment implements MediatorUser {
    private OnlinePayment onlinePayment = null;
    private String name;
    private ChatMediator chatMediator;
    public Payment(OnlinePayment paymentMethod,ChatMediator chatMediator) {
        this.onlinePayment = paymentMethod;
        this.name = paymentMethod.getClass().getName();
        this.chatMediator = chatMediator;
    }

    public void makePayment(double totalCost) {
        if( onlinePayment.makeOnlinePayment(totalCost) ) {
            this.sendMessage("Payment successfully done by \"" + onlinePayment.getClass().getName() + "\" method");
        }
        else {
            this.sendMessage("Failed to make payment by \"" + onlinePayment.getClass().getName() + "\" method");
        }
    }


    // Implementing MediatorUser Interface methods
    @Override
    public void sendMessage(String message) {
        chatMediator.sendMessage(message, this);
    }

    @Override
    public void receiveMessage(String message) {
        System.out.println(name + " got message \"" + message  + "\"");
    }
}
