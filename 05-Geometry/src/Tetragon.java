public abstract class Tetragon extends  GeometricFigure {
    public Tetragon() {
        super();
    }

    public Tetragon(String name) {
        super(4, name);
    }

    public Tetragon(String name, float[] dimensions) {
        super(4, name, dimensions);
    }

    public Tetragon(String name, float a, float b, float c, float d){
        super( 4, name);
        this.setDimensions(new float[]{a, b, c, d});
    }

    @Override
    public void setNumSides(int numSides) {
        if (numSides == 4) {
            super.setNumSides(numSides);
            return;
        }
        System.out.println("Um quadrilátero precisa ter quatro lados!");
    }

    @Override
    public void setDimensions(float[] dimensions) {
        if (dimensions.length != 4){
            System.out.println("Um quadrilátero precisa ter quatro lados!");
            return;
        }
        super.setDimensions(dimensions);
    }

    public void setDimensions(float a, float b, float c, float d) {
        this.setDimensions(new float[]{a, b, c, d});
    }
}
