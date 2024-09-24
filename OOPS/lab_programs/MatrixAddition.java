import java.util.Scanner;

public class MatrixAddition {
    public static void main(String[] args) {
        // Ensure that the user provides the value of N as a command-line argument
        if (args.length != 1) {
            System.out.println("Please provide the value of N as a command line argument.");
            return;
        }

        int N = Integer.parseInt(args[0]); // Get matrix size N from command-line argument
        int[][] matrix1 = new int[N][N];
        int[][] matrix2 = new int[N][N];
        Scanner scanner = new Scanner(System.in);

        // Reading Matrix 1
        System.out.println("Enter the elements of Matrix 1:");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrix1[i][j] = scanner.nextInt();
            }
        }

        // Reading Matrix 2
        System.out.println("Enter the elements of Matrix 2:");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrix2[i][j] = scanner.nextInt();
            }
        }

        // Perform matrix addition
        int[][] result = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }

        // Display Matrix 1, Matrix 2, and their sum
        System.out.println("Matrix 1:");
        printMatrix(matrix1);
        System.out.println("Matrix 2:");
        printMatrix(matrix2);
        System.out.println("Sum of the matrices:");
        printMatrix(result);
    }

    // Helper method to print a matrix
    private static void printMatrix(int[][] matrix) {
        for (int[] row : matrix) {
            for (int num : row) {
                System.out.print(num + "\t");
            }
            System.out.println();
        }
        System.out.println();
    }
}
