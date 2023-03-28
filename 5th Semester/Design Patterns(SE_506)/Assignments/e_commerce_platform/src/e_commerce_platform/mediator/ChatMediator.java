package e_commerce_platform.mediator;

public interface ChatMediator {
    void sendMessage(String message, MediatorUser user);
    void addUser(MediatorUser user);
}
