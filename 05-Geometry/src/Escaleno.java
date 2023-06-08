public class Escaleno extends Triangle{
    public Escaleno() {
        super();
    }

    public Escaleno(String name) {
        super(name);
    }

    public Escaleno(String name, float[] dimensions) {
        super(name);
        this.setDimensions(dimensions);
    }

    public Escaleno(String name, float a, float b, float c) {
        super(name);
        this.setDimensions(a, b, c);
    }

    @Override
    public void setDimensions(float[] dimensions){
        if (dimensions[0] != dimensions[1] && dimensions[0] != dimensions[2] && dimensions[1] != dimensions[2]){
            super.setDimensions(dimensions);
            return;
        }
        System.out.println("Todos os lados de um triângulo escaleno devem ser diferentes!");
    }

    public void setDimensions(float a, float b, float c){
        this.setDimensions(new float[]{a, b, c});
    }
}
