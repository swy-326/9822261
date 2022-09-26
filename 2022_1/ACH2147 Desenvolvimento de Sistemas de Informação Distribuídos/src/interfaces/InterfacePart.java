package interfaces;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.HashMap;

public interface InterfacePart extends Remote {    

    public int getCode() throws RemoteException;
    public String getName() throws RemoteException;
    public String getDescription() throws RemoteException;
    public String getRepositoryName() throws RemoteException;
    public HashMap<InterfacePart, Integer> getSubComponents() throws RemoteException;
    public int getTotalSubComponents() throws RemoteException;
    public boolean isPrimitive() throws RemoteException;
}
