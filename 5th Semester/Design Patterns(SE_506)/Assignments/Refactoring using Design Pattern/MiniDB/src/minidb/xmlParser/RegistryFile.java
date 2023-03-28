package minidb.xmlParser;

import java.io.File;
import java.util.Objects;
import javax.xml.parsers.*;
import org.w3c.dom.*;
import Constants.Constants;

/**
 * Contains the methods for performing CRUD operations on the registry file
 * 'minidb.xml'
 */
public class RegistryFile extends XMLFiles {
    private static RegistryFile registryFile = null;

    private RegistryFile(String path) {
        super(path);
    }

    public static RegistryFile getInstance(){
        if(registryFile == null) {
            registryFile = new RegistryFile(Constants.DATA_XML_PATH);
        }
        return registryFile;
    }

    void createFile() {
        Element rootElem = doc.createElement("root");
        Element emptyDb = this.addDbEntry("empty", "true");

        rootElem.appendChild(emptyDb);
        doc.appendChild(rootElem);

        new DatabaseFile(this.getDatabasePath("empty", true));
        this.updateFile();

        System.out.println("Intialized: " + xmlFile.getPath());
    }

    /**
     *
     * @param name     - Name of the database
     * @param disabled - Always false for user created databases
     * @return The XML Element which can be appended into the doc
     * @throws ParserConfigurationException
     */
    private Element addDbEntry(String name, String disabled) {
        DatabaseElementBuilder databaseElementFactory = new DatabaseElementBuilder();
        Element databaseElem = databaseElementFactory.createDatabaseElement(this, name, disabled);

        return databaseElem;
    }

    /**
     * Method for creating a new database. Which means both creating a entry in the
     * minidb.xml and A new database-xml file.
     *
     * @param name - The name of the database
     */
    public void createNewDatabase(String name) {
        try {
            if (!this.isDatabaseExists(name)) {
                Element dbEntry = addDbEntry(name, "false");
                this.doc.getDocumentElement().appendChild(dbEntry);
                this.updateFile();

                new DatabaseFile(this.getDatabasePath(name, true));
                System.out.println("Successfully created Database named: " + name);
            } else {
                System.out.println("Database already exists");
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * To list all the created databases in the register
     */
    public void listAllDatabases() {
        NodeList list = this.doc.getElementsByTagName("name");

        for (int i = 0; i < list.getLength(); i++) {
            Node dbNode = list.item(i);
            String name = dbNode.getTextContent();
            System.out.println(i + ". " + name);
        }
    }

    /**
     * Checks if the database name already exists in the register
     *
     * @param name - The name of the database
     * @return The index of the database in the register, if not found returns -1
     */
    public int checkDatabase(String name) {
        int x = -1;
        NodeList list = this.doc.getElementsByTagName("name");

        for (int i = 0; i < list.getLength(); i++) {
            Node dbNode = list.item(i);
            String dbName = dbNode.getTextContent();
            // System.out.println(dbName + " " + name);
            if (Objects.equals(dbName, name)) {
                x = i;
            }
        }

        return x;
    }

    private boolean isDatabaseExists(String name) {
        if (checkDatabase(name) != -1) {
            return true;
        } else
            return false;
    }

    /**
     * @param name   - Name of the Database
     * @param create - True only if you are creating a new database
     * @return The path of the database
     */
    public String getDatabasePath(String name, boolean create) {
        if(create | isDatabaseExists(name)) {
            return Constants.DB_DIR_PATH + "\\" + name + ".xml";
        }
        else {
            return null;
        }
    }

    public void deleteDatabase(String name) {
        int dbid = checkDatabase(name);

        if (dbid != -1) {
            String dbPath = getDatabasePath(name, false);

            NodeList list = this.doc.getElementsByTagName("database");
            Element dbEntry = (Element) list.item(dbid);
            dbEntry.getParentNode().removeChild(dbEntry);
            this.updateFile();

            File f = new File(dbPath);
            f.delete();
            print("Database deleted");

        } else {
            print("Database does not exist");
        }
    }
}
