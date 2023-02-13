package Abs_factory;

public class Client {
    public static void main(String args[])
    {
       WidgetFactory widgetFactory=new MotifWidgetFactory();

       widgetFactory.CreateScrollBar().show_scrollBar();
    }
}
