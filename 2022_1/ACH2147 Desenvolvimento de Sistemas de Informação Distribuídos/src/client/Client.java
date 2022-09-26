package client;

import java.io.Console;
import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Map;
import java.util.HashMap;
import java.util.HashSet;

import interfaces.*;

public class Client {
    public InterfacePartRepository currentRepository;
    public InterfacePart currentPart;
    public HashMap<InterfacePart, Integer> subcomponents;

    public Client() {
        currentRepository = null;
        currentPart = null;
        subcomponents = new HashMap<InterfacePart, Integer>();
    }

    public void init() {
        int opt = 0;
        String repName = "";
        try {
            do {
                System.out.println("### Menu do Gerenciador de Pecas ###");
                System.out.println("     ================================");
                System.out.println("   |   1 - Abrir/Mudar de repositorio |");
                System.out.println("   |   2 - Criar peca no repositorio  |");
                System.out.println("   |   3 - Lista pecas do repositorio |");
                System.out.println("   |   4 - Buscar peca por codigo     |");
                System.out.println("   |   5 - Detalhes da peca atual     |");
                System.out.println("   |   6 - Adicionar peca na lista    |");
                System.out.println("   |   7 - Limpar a lista de subpecas |");
                System.out.println("   |   0 - Finalizar aplicacao        |");
                System.out.println("     ================================");
                if (currentRepository != null) {
                    System.out.println("Repositorio atual: " + repName);
                }
                Console scan = System.console();
                opt = Integer.parseInt(scan.readLine());
                switch (opt) {
                    case 1:
                        System.out.println("Escreva o endereco IP do repositorio (padrao: localhost): ");
                        String repHost = scan.readLine();
                        System.out.println("Escreva a porta do repositorio: ");
                        int repPort = Integer.parseInt(scan.readLine());
                        System.out.println("Escreva o nome do repositorio: ");
                        repName = scan.readLine();
                        if (repHost.isBlank()) {
                            currentRepository = (InterfacePartRepository) Naming.lookup("//localhost:" + repPort + "/" + repName);
                        } else {
                            Registry registry = LocateRegistry.getRegistry(repHost, repPort);
                            currentRepository = (InterfacePartRepository) registry.lookup(repName);
                        }
                        break;
                    case 2:
                        if (currentRepository == null) {
                            System.out.println("Nenhum repositorio foi aberto");
                            break;
                        }
                        System.out.println("Coloque o nome da peca: ");
                        String partName = scan.readLine();
                        System.out.println("Coloque uma descricao da peca: ");
                        String partDesc = scan.readLine();
                        currentRepository.addPart(partName, partDesc, subcomponents);
                        break;
                    case 3:
                        if (currentRepository == null) {
                            System.out.println("Nenhum repositorio foi aberto");
                            break;
                        }
                        System.out.printf("\n%-6s %-15s %-20s", "Codigo", "Nome", "Descricao");
                        for (InterfacePart part : currentRepository.listParts()) {
                            System.out.printf("\n%-6s %-15s %-20s", part.getCode(), part.getName(),
                                    part.getDescription());
                        }
                        System.out.println("\nTotal: " + currentRepository.countRepositoryParts());
                        break;
                    case 4:
                        if (currentRepository == null) {
                            System.out.println("Nenhum repositorio foi aberto");
                            break;
                        }
                        System.out.println("Digite o codigo da peca que deseja buscar: ");
                        int code = Integer.parseInt(scan.readLine());
                        currentPart = (InterfacePart) currentRepository.getPart(code);
                        if (currentPart == null) {
                            System.out.println("Nenhuma peca com o codigo "+ code +" foi encontrado no repositorio atual");
                            break;
                        }
                        showPartDetails(currentPart);
                        break;
                    case 5:
                        showPartDetails(currentPart);
                        break;
                    case 6:
                        if (currentPart == null) {
                            System.out.println("Nenhuma peca foi selecionada do repositorio");
                            break;
                        }
                        System.out
                                .println("Digite a quantidade da peca " + currentPart.getName() + " para adicionar: ");
                        int quant = Integer.parseInt(scan.readLine());
                        subcomponents.put(currentPart, quant);
                        break;
                    case 7:
                        subcomponents.clear();
                        break;
                    case 0:
                        System.out.println("Aplicacao finalizada.");
                        break;
                    default:
                        System.out.println("Opcao invalida");
                }
            } while (opt != 0);
        } catch (MalformedURLException murle) {
            System.out.println("MalformedURLException");
            System.out.println(murle);
        } catch (RemoteException re) {
            System.out.println("RemoteException");
            System.out.println(re);
        } catch (NotBoundException nbe) {
            System.out.println("NotBoundException");
            System.out.println(nbe);
        } catch (Exception e) {
            System.out.println("Exception");
            System.out.println(e);
        }
    }

    public void showPartDetails(InterfacePart part) {
        if (part == null) {
            System.out.println("Nenhuma peca foi selecionada do repositorio");
        } else {
            try {
                System.out.println("Nome da peca: " + part.getName());
                System.out.println("Descricao: " + part.getDescription());
                System.out.println("Repositorio: " + part.getRepositoryName());
                if (part.isPrimitive()) {
                    System.out.println("Primitiva: Sim");
                } else {
                    System.out.println("Primitiva: Nao");
                    System.out.println("Lista de subcomponentes: ");
                    System.out.printf("\n%-6s %-25s %-6s %-15s", "Cod.", "Nome", "Quant.", "Repositorio");
                    for (Map.Entry<InterfacePart, Integer> subcomponent : part.getSubComponents().entrySet()) {
                        System.out.printf("\n%-6s %-25s %-6s %-15s", subcomponent.getKey().getCode(), subcomponent.getKey().getName(), subcomponent.getValue(), subcomponent.getKey().getRepositoryName());
                    }
                    System.out.println("\nTotal: " + part.getTotalSubComponents());
                }
            } catch (Exception e) {
                System.out.println("Error showing part details " + e);
            }

        }
    }

    public static void main(String[] args) {
        Client newCliente = new Client();
        newCliente.init();
    }
}
