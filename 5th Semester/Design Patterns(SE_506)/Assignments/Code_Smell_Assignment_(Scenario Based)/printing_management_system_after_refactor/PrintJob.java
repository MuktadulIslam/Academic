package printing_management_system_after_refactor;

public class PrintJob {
    PrintRequest [] printRequests;
    Job job;

    public PrintJob(Job job){
        this.job = job;
    }

    public void getRenderPreview(){
        job.renderPreview();
    }
}

class PrintRequest{
    PrintMode printMode;
    public PrintRequest(PrintMode printMode){
        this.printMode = printMode;
    }

}

class Job {
    private int priority;

    public void setPriority(int priority) {
        this.priority = priority;
    }

    public int getPriority() {
        return priority;
    }

    public void changePriority(){
//        It should be in PrioritySetting Class
    }

    public void renderPreview(){
//        shows a preview of the updated document.
    }
    public void pullJob(){}
}