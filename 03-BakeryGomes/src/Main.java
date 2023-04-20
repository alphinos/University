public class Main {

    public static void main(String[] args) {
        System.out.println("Faz o L");

        Store manoel = new Store("Papelaria Gomes");

        Product caneta = new Product("Caneta", "Azul", 3, 25);
        Product caderno = new Product("Caderno", "96 folhas", 25, 20);
        Product lapis = new Product("Lápis", "HB", 1, 5);

        manoel.addProduct(caneta);
        manoel.addProduct(caderno);
        manoel.addProduct(lapis);

        Seller manoelG = new Seller(1, "Manoel Gomes");
        Seller joaoG = new Seller(2, "João Gomes");
        Seller ciroG = new Seller(3, "Ciro Gomes");

        manoel.addSeller(manoelG);
        manoel.addSeller(joaoG);
        manoel.addSeller(ciroG);

        manoel.registerSell(1, "Caneta", 5);
        manoel.registerSell(1, "Caderno", 2);
        manoel.registerSell(2, "Lápis", 3);
        manoel.registerSell(3, "Lápis", 2);
        manoel.registerSell(1, "Caneta", 10);
        manoel.registerSell(2, "Caderno", 9);
        manoel.registerSell(1, "Lápis", 1);
        manoel.registerSell(3, "Caderno", 2);
        manoel.registerSell(3, "Caneta", 2);

        manoel.showStock();
        manoel.showFullReport();

    }
}