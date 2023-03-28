package e_commerce_platform.mediator;

import java.util.ArrayList;
import java.util.List;

public class Messenger implements ChatMediator{
    private List<MediatorUser> users;

    public Messenger() {
        this.users = new ArrayList<MediatorUser>();
    }
    @Override
    public void sendMessage(String message, MediatorUser user) {
        for (MediatorUser u : users) {
            // Send the message to all users except the sender
            if (u != user) {
                u.receiveMessage(message);
            }
        }
    }

    @Override
    public void addUser(MediatorUser user) {
        this.users.add(user);
    }
}

