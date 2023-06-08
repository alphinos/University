public class Isosceles extends Triangle{
    public Isosceles() {
        super();
    }

    public Isosceles(String name) {
        super(name);
    }

    public Isosceles(String name, float[] dimensions) {
        super(name);
        this.setDimensions(dimensions);
    }

    public Isosceles(String name, float a, float b, float c) {
        super(name);
        this.setDimensions(a, b, c);
    }

    @Override
    public void setDimensions(float[] dimensions){
        if (dimensions[0] == dimensions[1] || dimensions[1] == dimensions[2] || dimensions[0] == dimensions[2]){
            super.setDimensions(dimensions);
            return;
        }
        System.out.println("Ao menos dois lados de um triângulo isósceles devem ser iguais!");
    }

    public void setDimensions(float a, float b, float c){
        this.setDimensions(new float[]{a, b, c});
    }
}
