package decoratorPattern_classwork;

public class TextView implements VisualComponent{
    @Override
    public void draw() {
        System.out.println("Drawing textview");
    }

    @Override
    public void resize() {
        System.out.println("resizing textview");
    }
}
