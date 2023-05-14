import java.util.ArrayList;

class Store {
    private String name;
    private ArrayList<Product> products;
    private ArrayList<Seller> sellers;

    public Store() {};
    public Store(String name) {
        this.name = name;
        this.products = new ArrayList<Product>();
        this.sellers = new ArrayList<Seller>();
    }

    public String getName() {
        return this.name;
    }

    public ArrayList<Product> getProducts(){
        return this.products;
    }

    public ArrayList<Seller> getSellers(){
        return this.sellers;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setProducts(ArrayList<Product> products) {
        this.products = products;
    }

    public void setSellers(ArrayList<Seller> sellers) {
        this.sellers = sellers;
    }

    public void addProduct(Product p) {
        if (this.name == null){
            System.out.println("Não é possível adicionar um produto a uma loja sem nome!");
            return;
        }
        if (this.products.contains(p)) {
            System.out.println("O produto " + p.getName() + " já está registrado na loja!");
            return;
        }
        this.products.add(p);
        System.out.println("O produto " + p.getName() + " foi registrado com sucesso!");
    }

    public void addSeller(Seller s) {
        if (this.sellers.contains(s)) {
            System.out.println("O vendedor " + s.getName() + " já está trabalhando na loja!");
            return;
        }
        this.sellers.add(s);
        System.out.println("O vendedor " + s.getName() + " foi contratado com sucesso!");
    }

    public Seller findRegistration(int registration) {
        for (Seller se: sellers) {
            if (se.getRegistration() == registration) {
                return se;
            }
        }
        System.out.println("Nenhum vendedor foi encontrado com esse registro!");
        return null;
    }

    public Product findProduct(String name) {
        for (Product p: products) {
            if (p.getName() == name) {
                return p;
            }
        }
        System.out.println("Nenhum produto foi encontrado com esse nome!");
        return null;
    }

    public void registerSell(Seller s, Product p, int amount) {
        if (p.getStock() < amount) {
            System.out.println("Não foi possível registrar a venda!");
            return;
        }
        s.addSell(p, amount);
        p.setStock(p.getStock() - amount);
        System.out.println("Venda do produto " + p.getName() + " registrada!");
    }

    public void registerSell(int registration, String name, int amount) {
        Seller s = new Seller();
        Product p = new Product();

        s = this.findRegistration(registration);
        p = this.findProduct(name);

        this.registerSell(s, p, amount);
    }

    public int totalSells() {
        int total = 0;

        for (Seller s: this.sellers) {
            total += s.totalValueSells(this.products);
        }

        return total;
    }

    public int totalStock() {
        int total = 0;

        for (Seller s: this.sellers) {
            total += s.totalQtdSells(this.products);
        }

        return total;
    }

    public void showFullReport() {
        Formatter.printNtimes('-', 60, true);
        int totChar = 0;
        int correction = 0;
        for (Seller s: this.sellers) {
            totChar = 44 + String.valueOf(s.getRegistration()).length() + s.getName().length() + 5;
            if ( totChar >= 60 ) {
                correction = totChar - 60;
            }

            Formatter.printNtimes('-', 22, false);
            System.out.print(" " + s.getRegistration() + " - " + s.getName() + " ");
            Formatter.printNtimes('-', 22 - correction, true);

            s.showReport(this.products);
        }
        System.out.println("Total de vendas da loja: " + "R$" + this.totalSells() + " - " + this.totalStock()) ;
        Formatter.printNtimes('-', 60, true);
    }

    public void showStock() {
        Formatter.printNtimes('-', 60, true);

        int totChar = 0;
        int correction = 0;

        Formatter.printNtimes('-', 9, false);
        System.out.print( " Produtos - Preço - Quantidade em estoque " );
        Formatter.printNtimes('-', 9, true);

        for (Product p: this.products) {

            totChar = 9 + p.getName().length() + 1 + 2;

            Formatter.printNtimes('-', 9, false);
            System.out.print(" " + p.getName());

            correction = 0;
            if ( totChar < 19 ) {
                correction = 19 - totChar;
            }

            Formatter.printNtimes(' ', 2 + correction, false);
            System.out.print("- " + p.getValue());

            totChar += String.valueOf(p.getValue()).length() + 2 + 2;

            correction = 0;
            if ( totChar < 27 ) {
                correction = 27 - totChar;
                correction /= 2;
            }

            Formatter.printNtimes(' ', 2 + correction, false);
            System.out.print("- ");

            correction = String.valueOf(p.getStock()).length() - 1;

            totChar += String.valueOf(p.getStock()).length() + 4 + 10;

            Formatter.printNtimes('-', 21/2 - correction, false);

            System.out.print(" " + p.getStock() + " ");
            Formatter.printNtimes('-', 18, true);
        }
        Formatter.printNtimes('-', 60, true);
    }
}