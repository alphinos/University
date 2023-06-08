public class Equilatero extends Triangle {
    public Equilatero() {
        super();
    }

    public Equilatero(String name) {
        super(name);
    }

    public Equilatero(String name, float[] dimensions) {
        super(name);
        this.setDimensions(dimensions);
    }

    public Equilatero(String name, float a) {
        super(name, a, a, a);
    }

    @Override
    public void setDimensions(float[] dimensions){
        for (float d_1 : dimensions){
            for (float d_2 : dimensions){
                if (d_1 != d_2){
                    System.out.println("Há dimensões diferentes umas das outras!\nNão é equilátero!");
                    return;
                }
            }
        }
        super.setDimensions(dimensions);
    }

    public void setDimensions(float a){
        super.setDimensions(new float[]{a, a, a});
    }

    public void setDimensions(float a, float b, float c){
        if (a != b || a != c || b != c){
            System.out.println("Todos os lados de um triângulo equilátero devem ser iguais!");
            return;
        }
        super.setDimensions(new float[]{a, a, a});
    }
}
