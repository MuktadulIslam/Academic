package arg_manager_ByStrategyP;

public interface ArgumentStrategy {
    boolean isEqual(String arg);
    void executeCMD(String inputCMD);
}
