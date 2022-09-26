package interfaces;

import java.rmi.Remote;
import java.rmi.RemoteException;
import java.util.HashSet;
import java.util.HashMap;

public interface InterfacePartRepository extends Remote {
    public String getRepositoryName() throws RemoteException;
    public int countRepositoryParts() throws RemoteException;
    public void addPart(String name, String desc, HashMap<InterfacePart, Integer> subcomponents) throws RemoteException;
    public HashSet<InterfacePart> listParts() throws RemoteException;
    public InterfacePart getPart(int code) throws RemoteException;
}