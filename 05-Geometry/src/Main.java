import java.util.ArrayList;
public class Main {
    public static void main(String[] args) {
        System.out.println("Faz o L!");

        Equilatero equilatero = new Equilatero("equilatero", 10);
        Isosceles isosceles = new Isosceles("isosceles", 10, 8, 10);
        Escaleno escaleno = new Escaleno("escaleno", 10, 11, 12);

        Quadrado quadrado = new Quadrado("quadrado", 10);
        Retangulo retangulo = new Retangulo("retangulo", 10, 20, 10, 20);

        ArrayList<GeometricFigure> figuras = new ArrayList<GeometricFigure>();

        figuras.add(equilatero);
        figuras.add(isosceles);
        figuras.add(escaleno);
        figuras.add(quadrado);
        figuras.add(retangulo);

        for (int i = 0; i < figuras.size(); i++) {
            for (int j = i; j < figuras.size(); j++) {
                System.out.println();

                GeometricFigure f1 = figuras.get(i);
                GeometricFigure f2 = figuras.get(j);

                System.out.println();

                compararPerimetro(f1, f2);
                compararArea(f1, f2);

                System.out.println();
            }
            System.out.println();
        }

    }

    public static void compararPerimetro(GeometricFigure a, GeometricFigure b) {
        System.out.println("Perímetro de " + a.getName() + ": " + a.calculateP2());
        System.out.println("Perímetro de " + b.getName() + ": " + b.calculateP2());

        if (a.calculateP2() > b.calculateP2()) {
            System.out.println("A figura de maior perímetro é a: " + a.getName());
        } else if (b.calculateP2() > a.calculateP2()) {
            System.out.println("A figura de maior perímetro é a: " + b.getName());
        } else {
            System.out.println("As figuras: " + a.getName() + ", " + b.getName() + " possuem o mesmo perímetro!");
        }
    }

    public static void compararArea(GeometricFigure a, GeometricFigure b) {
        System.out.println("Área de " + a.getName() + ": " + a.calculateArea());
        System.out.println("Área de " + b.getName() + ": " + b.calculateArea());

        if (a.calculateArea() > b.calculateArea()) {
            System.out.println("A figura de maior área é a: " + a.getName());
        } else if (b.calculateArea() > a.calculateArea()) {
            System.out.println("A figura de maior área é a: " + b.getName());
        } else {
            System.out.println("As figuras: " + a.getName() + ", " + b.getName() + " possuem a mesma área!");
        }
    }
}