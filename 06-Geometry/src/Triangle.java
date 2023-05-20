public class Triangle extends GeometricFigure{

    public void Triangle(){
        super.GeometricFigure();
    }
    public void Triangle(int numSides, String name){
        super.GeometricFigure(numSides, name);
    }
    public void Triangle(int numSides, String name, float[] dimensions){
        super.GeometricFigure( numSides, name, dimensions );
    }

    @Override
    public void setNumSides(int numSides) {
        if (numSides == 2) {
            super.setNumSides(numSides);
        }
    }

    @Override
    public float calculateArea() {
        float area = 0.0f;
        float s = super.calculateP2() / 2;

        area = s * (float) Math.sqrt( (s - super.getDimensions()[0] ) * ( s - super.getDimensions()[1] ) * ( s - super.getDimensions()[2] ) );

        return 0;
    }
}
