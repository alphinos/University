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
    public void setDimensions(float[] dimensions) {
        if (dimensions.length != 4){
            return;
        }
        super.setDimensions(dimensions);
    }
}
