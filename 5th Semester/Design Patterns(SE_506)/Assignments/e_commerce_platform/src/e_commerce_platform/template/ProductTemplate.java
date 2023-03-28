package e_commerce_platform.template;

import e_commerce_platform.strategy.OnlinePayment;

public abstract class ProductTemplate {
    private String productName;
    private String description;
    private double price;
    private String image;
    private String inventory;
    protected int availableQuantity;
    public ProductTemplate(String productName, String description, double price, String image, String inventory, int availableQuantity) {
        this.productName = productName;
        this.description = description;
        this.price = price;
        this.image = image;
        this.inventory = inventory;
        this.availableQuantity = availableQuantity;
    }

    public final void display(){
        boolean inStock;
        double discountPrice;

        inStock = isProductAvailable(1);

        if(inStock){
            discountPrice = price * getDiscount();
            if(discountPrice == price){
                System.out.println("Product Name: " + productName + "   Image: " + image
                        + "   Description: " + description + "     Price: " + price);
            }
            else {
                System.out.println("Product Name: " + productName + "   Image: " + image
                        + "   Description: " + description + "     Price: " + price + "    Discount Price: " + discountPrice);
            }
        }
        else {
            System.out.println("Product is not available!!!");
        }
    }

    public final void makeOrder(int totalProduct, OnlinePayment onlinePayment) {
        if(isProductAvailable(totalProduct)) {
            processPayment(totalProduct*price, onlinePayment);
            wrap();
        }
        else{
            System.out.println( totalProduct + " this amount of product is not currently available!!!");
        }
    }

    protected abstract boolean isProductAvailable(int totalProduct);
    protected abstract double getDiscount();
    protected abstract void processPayment(double totalCost, OnlinePayment onlinePayment);
    protected abstract void wrap();





    // getter & setter
    public String getProductName() {
        return productName;
    }

    public String getDescription() {
        return description;
    }

    public double getPrice() {
        return price;
    }

    public String getImage() {
        return image;
    }

    public String getInventory() {
        return inventory;
    }

    public void setProductName(String productName) {
        this.productName = productName;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public void setImage(String image) {
        this.image = image;
    }

    public void setInventory(String inventory) {
        this.inventory = inventory;
    }
}
