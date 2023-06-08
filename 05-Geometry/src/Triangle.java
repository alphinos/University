public abstract class Triangle extends GeometricFigure{

    public Triangle(){
        super();
    }

    public Triangle(String name){
        super(3, name);
    }

    public Triangle(String name, float[] dimensions){
        super( 3, name );
        this.setDimensions(dimensions);
    }

    public Triangle(String name, float a, float b, float c){
        super( 3, name);
        this.setDimensions(a, b, c);
    }

    @Override
    public void setNumSides(int numSides) {
        if (numSides == 3) {
            super.setNumSides(numSides);
            return;
        }
        System.out.println("Um triângulo precisa ter três lados!");
    }

    @Override
    public void setDimensions(float[] dimensions) {
        if (dimensions.length != 3){
            System.out.println("Um triângulo precisa ter três lados!");
            return;
        }
        if ( dimensions[0] < dimensions[1] + dimensions[2] &&
             dimensions[1] < dimensions[0] + dimensions[2] &&
             dimensions[2] < dimensions[0] + dimensions[1]){
            super.setDimensions(dimensions);
        }
    }

    public void setDimensions(float a, float b, float c) {
        this.setDimensions(new float[]{a, b, c});
    }

    @Override
    public float calculateArea() {
        float area = 0.0f;
        float s = super.calculateP2() / 2;

        area = (float) Math.sqrt( s * (s - super.getDimensions()[0] ) * ( s - super.getDimensions()[1] ) * ( s - super.getDimensions()[2] ) );

        return area;
    }

    public boolean compararArea(GeometricFigure a, GeometricFigure b){
        return true;
    }

    public int compararArea(GeometricFigure a, GeometricFigure b, GeometricFigure c){
        return 1;
    }
}
