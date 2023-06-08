public abstract class GeometricFigure implements FiguraPlanar {
    private int numSides;
    private String name;
    private float[] dimensions;

    public GeometricFigure(){
        this.dimensions = new float[this.numSides];
    }
    public GeometricFigure(int numSides, String name){
        this.setNumSides(numSides);
        this.name = name;
        this.dimensions = new float[this.numSides];
    }

    public GeometricFigure(int numSides, String name, float[] dimensions){
        this.setNumSides(numSides);
        this.name = name;
        this.setDimensions(dimensions);
    }

    public int getNumSides() {
        return numSides;
    }

    public String getName() {
        return name;
    }

    public float[] getDimensions() {
        return dimensions;
    }

    public void setNumSides(int numSides) {
        if (numSides > 2) {
            this.numSides = numSides;
        }
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setDimensions(float[] dimensions){
        if (dimensions.length == this.numSides){
            this.dimensions = dimensions;
        }
    }

    public void showDimensions(){
        for (float d : this.dimensions){
            System.out.println(d);
        }
    }

    public float calculateP2(){
        float perimeter = 0.0f;
        for (float d : this.dimensions){
            perimeter += d;
        }
        return perimeter;
    }
    public abstract float calculateArea();

}
