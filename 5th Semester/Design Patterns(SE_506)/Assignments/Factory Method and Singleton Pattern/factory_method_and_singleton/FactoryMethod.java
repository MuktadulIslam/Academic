package factory_method_and_singleton;

public class FactoryMethod {
    public static void main(String[] args) {
        ChildEmployeeFactory childEmployeeFactory = new ChildEmployeeFactory();
        Employee employee = childEmployeeFactory.createEmployee("staff");
        employee.work();
    }
}


//Factory Method example
abstract class Employee {
    public abstract void work();
}


class Staff extends Employee {
    @Override
    public void work(){
        System.out.println("Staff start working");
    }
}


class MarketingManager extends Employee {
    @Override
    public void work(){
        System.out.println("Marketing Manager start working");
    }
}


class SecurityGuard extends Employee {
    @Override
    public void work(){
        System.out.println("Security Guard start working");
    }
}


class Cleaner extends Employee {
    @Override
    public void work(){
        System.out.println("Cleaner start working");
    }
}

class EmployeeFactory{
    public Employee createEmployee(String type){
        if(type == "staff") {
            return new Staff();
        }
        else if(type == "marketing manager") {
            return new MarketingManager();
        }
        else if(type == "security guard") {
            return new SecurityGuard();
        }
        else return null;
    }
}

class ChildEmployeeFactory extends EmployeeFactory {
    @Override
    public Employee createEmployee(String type) {
        if(type == "cleaner"){
            return new Cleaner();
        }
        else {
            return super.createEmployee(type);
        }
    }
}
