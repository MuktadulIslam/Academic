package printing_management_system;

public class PrintJob {
//    Black Sheep (pullJob, changePriority methods)
//    lazy class smell (PrioritySetting class)

    PrintRequest [] printRequests;
    PrioritySetting prioritySetting;

    public void pullJob(){}
    public void changePriority(){
//        It should be in PrioritySetting Class
    }
}

class PrintRequest{
    PrintMode printMode;
    public PrintRequest(PrintMode printMode){
        this.printMode = printMode;
    }

}

class PrioritySetting{

}