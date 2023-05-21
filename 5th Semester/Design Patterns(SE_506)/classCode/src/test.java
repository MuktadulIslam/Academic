// Abstract Factory Interface
public interface GUIFactory {
    public Button createButton();
    public TextBox createTextBox();
}

// Concrete Factory 1
public class WindowsGUIFactory implements GUIFactory {
    public Button createButton() {
        return new WindowsButton();
    }
    public TextBox createTextBox() {
        return new WindowsTextBox();
    }
}

// Concrete Factory 2
public class MacGUIFactory implements GUIFactory {
    public Button createButton() {
        return new MacButton();
    }
    public TextBox createTextBox() {
        return new MacTextBox();
    }
}

// Abstract Product Interface
public interface Button {
    public void click();
}

// Concrete Product 1
public class WindowsButton implements Button {
    public void click() {
        System.out.println("Windows button clicked.");
    }
}

// Concrete Product 2
public class MacButton implements Button {
    public void click() {
        System.out.println("Mac button clicked.");
    }
}

// Abstract Product Interface
public interface TextBox {
    public void input(String text);
}

// Concrete Product 1
public class WindowsTextBox implements TextBox {
    public void input(String text) {
        System.out.println("Windows text box: " + text);
    }
}

// Concrete Product 2
public class MacTextBox implements TextBox {
    public void input(String text) {
        System.out.println("Mac text box: " + text);
    }
}

// Client Code
public class Application {
    private GUIFactory guiFactory;
    private Button button;
    private TextBox textBox;

    public Application(GUIFactory guiFactory) {
        this.guiFactory = guiFactory;
        this.button = guiFactory.createButton();
        this.textBox = guiFactory.createTextBox();
    }

    public void run() {
        button.click();
        textBox.input("Hello, world!");
    }
}

// Usage
public class Main {
    public static void main(String[] args) {
        GUIFactory factory;
        String osName = System.getProperty("os.name").toLowerCase();

        if (osName.contains("windows")) {
            factory = new WindowsGUIFactory();
        } else {
            factory = new MacGUIFactory();
        }

        Application app = new Application(factory);
        app.run();
    }
}
