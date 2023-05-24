public class Quadrado extends Tetragon{
    public Quadrado() {
        super();
    }

    public Quadrado(String name) {
        super(name);
    }

    public Quadrado(String name, float[] dimensions) {
        super(name);
        this.setDimensions(dimensions);
    }

    public Quadrado(String name, float a) {
        super(name);
        this.setDimensions(a, a, a, a);
    }

    public Quadrado(String name, float a, float b, float c, float d) {
        super(name);
        this.setDimensions(a, b, c, d);
    }

    @Override
    public void setDimensions(float[] dimensions){

        if (
                dimensions[0] != dimensions[1] || dimensions[0] != dimensions[2] || dimensions[0] != dimensions[3] ||
                        dimensions[1] != dimensions[2] || dimensions[1] != dimensions[3] ||
                            dimensions[2] != dimensions[3]
        ){
            System.out.println("Todos os lados do quadrado devem ser iguais!");
            return;
        }
        super.setDimensions(dimensions);
    }

    public void setDimensions(float a, float b, float c, float d) {
        this.setDimensions(new float[]{a, b, c, d});
    }

    @Override
    public float calculateArea() {
        return super.getDimensions()[0] * super.getDimensions()[0];
    }
}
