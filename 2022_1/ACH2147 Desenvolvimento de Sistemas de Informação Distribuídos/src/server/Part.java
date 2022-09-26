package server;

import java.rmi.server.UnicastRemoteObject;
import java.rmi.RemoteException;
import java.util.HashMap;

import interfaces.*;

public class Part extends UnicastRemoteObject implements InterfacePart {
    private int code;
    private String name, description, repositoryName;
    private HashMap<InterfacePart, Integer> subcomponents;

    public Part (int code, String name, String desc, HashMap<InterfacePart, Integer> subcomponents, String repName) throws RemoteException {
        super();
        this.code = code;
        this.name = name;
        this.description = desc;
        this.subcomponents = new HashMap<InterfacePart, Integer>();
        this.subcomponents.putAll(subcomponents);
        this.repositoryName = repName;
    }

    public int getCode() throws RemoteException {
        return code;
    }

    public String getName() throws RemoteException {
        return name;
    }

    public String getDescription() throws RemoteException {
        return description;
    }

    public String getRepositoryName() throws RemoteException {
        return repositoryName;
    }

    public HashMap<InterfacePart, Integer> getSubComponents() throws RemoteException {
        return subcomponents;
    }

    public int getTotalSubComponents() throws RemoteException {
        return subcomponents.size();
    }

    public boolean isPrimitive() throws RemoteException {
        return subcomponents.isEmpty();
    }
}
