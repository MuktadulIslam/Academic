package decoratorPattern_classwork;

public class BorderDecorator extends Decorator{
    public BorderDecorator(VisualComponent component) {
        super(component);
    }

    @Override
    public void draw() {
        super.draw();
        this.drawBorder();
    }

    private void drawBorder(){
        System.out.println("Drawing Border");
    }
}
