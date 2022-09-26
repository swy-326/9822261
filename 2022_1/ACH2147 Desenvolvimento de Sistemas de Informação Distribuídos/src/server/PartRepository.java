package server;

import java.util.concurrent.atomic.AtomicInteger;
import java.rmi.server.UnicastRemoteObject;
import java.rmi.RemoteException;
import java.util.HashSet;
import java.util.HashMap;

import interfaces.*;

public class PartRepository extends UnicastRemoteObject implements InterfacePartRepository {
    private static final AtomicInteger count = new AtomicInteger(0);
    private HashSet<InterfacePart> repository;
    private String repositoryName;
    
    public PartRepository(String name) throws RemoteException {
        super();
        this.repository = new HashSet<InterfacePart>();
        this.repositoryName = name;
    }

    public String getRepositoryName() throws RemoteException {
        return repositoryName;
    }

    public int countRepositoryParts() throws RemoteException {
        return repository.size();
    }

    public void addPart(String name, String desc, HashMap<InterfacePart, Integer> subcomponents) throws RemoteException {
        int code = count.incrementAndGet();
        InterfacePart newPart = new Part(code, name, desc, subcomponents, repositoryName);
        repository.add(newPart);
    }

    public HashSet<InterfacePart> listParts() throws RemoteException {
        return repository;
    }

    public InterfacePart getPart(int code) throws RemoteException {
        for (InterfacePart part : repository) {
            if (part.getCode() == code) {
                return part;
            }
        }
        return null;
    }
}
