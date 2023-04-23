import java.util.HashMap;
import java.util.ArrayList;

class Seller {
    private int registration;
    private String name;
    private HashMap<Product, Integer> sells;

    public Seller() {
        this.sells = new HashMap<Product, Integer>();
    };
    public Seller(int registration, String name) {
        this.registration = registration;
        this.name = name;
        this.sells = new HashMap<Product, Integer>();
    }

    public int getRegistration() {
        return this.registration;
    }

    public String getName() {
        return this.name;
    }

    public HashMap<Product, Integer> getSells(){
        return this.sells;
    }

    public void setRegistration(int registration) {
        this.registration = registration;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSells(HashMap<Product, Integer> sells) {
        this.sells = sells;
    }

    public void addSell(Product p, int amount) {
        if (this.sells.containsKey(p)) {
            this.sells.put(p, this.sells.get(p) + amount);
            return;
        }
        this.sells.put(p, amount);
    }

    public int totalValueSells(ArrayList<Product> prods){
        int total = 0;

        for (Product p: prods) {
            if (this.sells.containsKey(p)) {
                total += this.sells.get(p)*p.getValue();
            }
        }

        return total;
    }

    public int totalQtdSells(ArrayList<Product> prods){
        int total = 0;

        for (Product p: prods) {
            if (this.sells.containsKey(p)) {
                total += this.sells.get(p);
            }
        }

        return total;
    }

    public void showReport(ArrayList<Product> prods) {
        for (Product p: prods) {
            if (this.sells.containsKey(p)) {
                Formatter.printNtimes('-', 60, true);
                System.out.println(p.getName() + " - " + p.getDescription() + " - " + "Vendas totais do produto: " + this.sells.get(p));
                System.out.println("Vendas totais: " + "R$" + this.totalValueSells(prods) + " - " + this.totalQtdSells(prods));
                Formatter.printNtimes('-', 60, true);
            }
        }
    }
}