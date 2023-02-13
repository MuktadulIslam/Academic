package Abs_factory;

public class MotifWidgetFactory extends WidgetFactory{

    @Override
    public MotifScrollBar CreateScrollBar() {
        System.out.println("Scroll Bar has been created for Motif");
        return new MotifScrollBar();
        //System.out.println("Scroll Bar has been created for Motif");
    }

    @Override
    public  MotifWindow CreateWindow() {
        System.out.println("Window has been created for Motif");
        return new MotifWindow();
        //System.out.println("Window has been created for Motif");
    }
}
