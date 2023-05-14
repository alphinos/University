
class Formatter {
    public static void printNtimes(char c, int n, boolean jump) {
        for (int i = 0; i < n; i++) {
            System.out.print(c);
        }
        if (jump) {
            System.out.println("");
        }
    }
}
