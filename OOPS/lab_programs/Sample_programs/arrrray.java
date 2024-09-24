import java.util.Scanner;

public class arrrray {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] numbers = new int[5];

        System.out.println("Enter 5 integers:");

        for (int i = 0; i < numbers.length; i++) {
            numbers[i] = scanner.nextInt();
        }

        System.out.println("Array elements are:");
        for (int i = 0; i < numbers.length; i++) {
            System.out.println(numbers[i]);
        }

        scanner.close();
    }
}
