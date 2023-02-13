package Abs_factory;

public class PMWidgetFactory extends WidgetFactory{
    @Override
    public PMScrollBar CreateScrollBar() {
        System.out.println("Scroll Bar has been created for PM");
        return new PMScrollBar();
     //   System.out.println("Scroll Bar has been created for PM");
    }

    @Override
    public PMWindow CreateWindow() {
        System.out.println("Window has been created for PM");
        return new PMWindow();

    }
}
