package decoratorPattern_classwork;

public abstract class Decorator implements VisualComponent {
    private VisualComponent visualComponent;
    public Decorator(VisualComponent component){
        visualComponent = component;
    }

    @Override
    public void draw() {
        visualComponent.draw();
    }

    @Override
    public void resize() {
        visualComponent.resize();
    }
}
