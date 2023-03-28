package e_commerce_platform.mediator;

public interface MediatorUser {
    private String name;
    private ChatMediator chatMediator;

    public User(String name, ChatMediator chatMediator) {
        this.name = name;
        this.chatMediator = chatMediator;
    }

    public void sendMessage(String message) {
        this.chatMediator.sendMessage(message, this);
    }

    public void receiveMessage(String message) {
        System.out.println(name + " received message: " + message);
    }
}







//// Mediator interface
//public interface ChatMediator {
//    public void sendMessage(String message, User user);
//    public void addUser(User user);
//}
//
//// Concrete mediator class
//public class ChatMediatorImpl implements ChatMediator {
//    private List<User> users;
//
//    public ChatMediatorImpl() {
//        this.users = new ArrayList<>();
//    }
//
//    @Override
//    public void sendMessage(String message, User user) {
//        for (User u : users) {
//            // Send the message to all users except the sender
//            if (u != user) {
//                u.receiveMessage(message);
//            }
//        }
//    }
//
//    @Override
//    public void addUser(User user) {
//        this.users.add(user);
//    }
//}
//
//// User class
//public class User {
//    private String name;
//    private ChatMediator chatMediator;
//
//    public User(String name, ChatMediator chatMediator) {
//        this.name = name;
//        this.chatMediator = chatMediator;
//    }
//
//    public void sendMessage(String message) {
//        this.chatMediator.sendMessage(message, this);
//    }
//
//    public void receiveMessage(String message) {
//        System.out.println(name + " received message: " + message);
//    }
//}
//
//// Example usage
//public class Main {
//    public static void main(String[] args) {
//        ChatMediator mediator = new ChatMediatorImpl();
//        User user1 = new User("Alice", mediator);
//        User user2 = new User("Bob", mediator);
//        User user3 = new User("Charlie", mediator);
//        mediator.addUser(user1);
//        mediator.addUser(user2);
//        mediator.addUser(user3);
//        user1.sendMessage("Hello everyone!");
//    }
//}
