import java.rmi.registry.Registry;
import java.rmi.registry.LocateRegistry;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;


public class Server implements medianService {
    public Server() {
    }


    @Override
    public List<Integer> generateRandom(int n) {
        Random rand = new Random();
        List<Integer> lst = new LinkedList();
        for (int i = 0; i < n; i++) {
            lst.add(rand.nextInt(n));
        }
        return lst;
    }


    @Override
    public List sortNum(List<Integer> lst) {
        Collections.sort(lst);
        return lst;
    }


    @Override
    public float findMedian(List<Integer> lst) {
        int len = lst.size();
        float res;
        if (len % 2 == 0) {
            res = lst.get(len / 2 - 1) + lst.get(len / 2);
            res /= 2;
        } else {
            res = lst.get(len / 2);
        }
        return res;
    }


    public static void main(String args[]) {
        try {
            Server obj = new Server();
            medianService stub = (medianService) UnicastRemoteObject.exportObject(obj, 0);
            // Bind the remote object's stub in the registry
            Registry registry = LocateRegistry.getRegistry();
            registry.bind("medianService", stub);
            System.err.println("Server ready");
        } catch (Exception e) {
            System.err.println("Server exception: " + e.toString());
            e.printStackTrace();
        }
    }
}
