
class Product {
    private String name;
    private String description;
    private float value;
    private int stock;

    public Product() {};
    public Product(String name, String description, float value, int stock) {
        this.name = name;
        this.description = description;
        this.setValue(value);
        this.setStock(stock);
    }

    public String getName() {
        return this.name;
    }

    public String getDescription() {
        return this.description;
    }

    public float getValue() {
        return this.value;
    }

    public int getStock() {
        return this.stock;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public void setValue(float value) {
        if (value < 0)
            return;
        this.value = value;
    }

    public void setStock(int stock) {
        if (stock < 0)
            return;
        this.stock = stock;
    }
}