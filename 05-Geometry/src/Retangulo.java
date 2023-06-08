public class Retangulo extends  Tetragon{
    public Retangulo() {
        super();
    }

    public Retangulo(String name) {
        super(name);
    }

    public Retangulo(String name, float[] dimensions) {
        super(name, dimensions);
    }

    public Retangulo(String name, float a, float b, float c, float d) {
        super(name, a, b, c, d);
    }

    @Override
    public void setDimensions(float[] dimensions){
        // Checagem de igualdade entre lados paralelos e de congruência entre as suas diagonais
        // Lado 0 = cima, lado 1 = direita, lado 2 = baixo, lado 3 = esquerda
        if (dimensions[0] != dimensions[2] || dimensions[1] != dimensions[3]){
            System.out.println("Os lados opostos de todo retângulo regular devem ser iguais!");
            return;
        }
        double diag1 = Math.sqrt( Math.pow( dimensions[0], 2 ) + Math.pow(dimensions[1], 2) );
        double diag2 = Math.sqrt( Math.pow( dimensions[1], 2 ) + Math.pow(dimensions[2], 2) );
        if (diag1 != diag2){
            System.out.println("As diagonais de todo retângulo regular devem ser iguais!");
            return;
        }
        super.setDimensions(dimensions);
    }

    public void setDimensions(float a, float b, float c, float d) {
        this.setDimensions(new float[]{a, b, c, d});
    }

    @Override
    public float calculateArea() {
        return super.getDimensions()[0] * super.getDimensions()[1];
    }
}
