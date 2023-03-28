package e_commerce_platform;

import e_commerce_platform.mediator.ChatMediator;
import e_commerce_platform.mediator.MediatorUser;
import e_commerce_platform.strategy.OnlinePayment;
import e_commerce_platform.template.ProductTemplate;

public class Book extends ProductTemplate implements MediatorUser {
    private String name = "Book";
    private ChatMediator chatMediator;

    public Book(String productName, String description, double price, String image, String inventory, int availableQuantity) {
        super(productName, description, price, image, inventory, availableQuantity);
    }

    @Override
    protected boolean isProductAvailable(int totalProduct) {
        if(totalProduct <= this.availableQuantity) return true;
        else return false;
    }

    @Override
    protected double getDiscount() {
        return 0.25;
    }

    @Override
    protected void processPayment(double totalCost, OnlinePayment onlinePayment) {
        onlinePayment.makeOnlinePayment(totalCost);
        System.out.println("Book payment is done!!!");
    }

    @Override
    protected void wrap() {
        System.out.println("Book is wrapped...");
    }



    public void setChatMediator(ChatMediator chatMediator) {
        this.chatMediator = chatMediator;
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
