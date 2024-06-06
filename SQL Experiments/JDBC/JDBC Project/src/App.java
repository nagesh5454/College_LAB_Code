public class App {
    // Diamond Pattern Code
    public static void main(String[] args) throws Exception {
        int n = 6;
        for (int i = 0; i < n; i++) {
            // space
            for (int j = 0; j < n - i; j++) {
                System.out.print(" ");
            }
            for(int k=0;k<2*i-1;k++){
                System.out.print("*");
            }
            System.out.println();

        }
        for (int i = n-1; i >=0; i--) {
            // space
            for (int j = 0; j < n - i; j++) {
                System.out.print(" ");
            }
            for(int k=0;k<2*i-1;k++){
                System.out.print("*");
            }
            System.out.println();

        }

    }
}
