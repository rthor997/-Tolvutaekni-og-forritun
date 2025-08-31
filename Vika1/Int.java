public class Int {
    public static void main(String[] args) {
        /// liður a
        int a = 50000;
        int b = 50000;
        int int_utkoma = a * b; 
        System.out.println("Int talan verður " + int_utkoma);

        float x = 1e20f;
        float y = -1e20f;
        float float_utkoma = x + (y + 3.14f);
        System.out.println("Float talan verður " + float_utkoma);
        /// liður b
        long p = 5000000000L;
        long o = 5000000000L;
        long long_utkoma = p * o;
        System.out.println("Long talan verður " + long_utkoma);

        double u = 1e20;
        double j = -1e20;
        double double_utkoma = u + (j + 3.14);
        System.out.println("Double talan verður " + double_utkoma);

    }

}
