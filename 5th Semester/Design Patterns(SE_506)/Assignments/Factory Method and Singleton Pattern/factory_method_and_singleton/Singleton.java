package factory_method_and_singleton;

public class Singleton {
    public static void main(String[] args) {
        ReadFromDB reader = new ReadFromDB();
        WriteInDB writer = new WriteInDB();

        reader.read();
        writer.write();
    }
}


//Singleton example
class DB_Connection {
    private static DB_Connection obj;

    public static DB_Connection getInstance(){
        if(obj == null){
            obj = new DB_Connection();
        }
        return obj;
    }
}


class ReadFromDB{
    public void read(){
        DB_Connection obj = DB_Connection.getInstance();

        // Reading from DataBase
        System.out.println("Reading from database");
    }
}

class WriteInDB{
    public void write(){
        DB_Connection obj = DB_Connection.getInstance();

        // Writhing in DataBase
        System.out.println("Writing to database");
    }
}
