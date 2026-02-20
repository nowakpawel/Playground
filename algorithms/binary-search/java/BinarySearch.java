import java.util.Random;

public class BinarySearch {

    public static int binarySearch(int[] collection, int target) {
        int size = collection.length;
        int left = 0;
        int right = size - 1;


        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (collection[mid] == target) {
                return mid;
            }

            if (collection[mid] > target) {
                right = mid - 1;
            }

            if (collection[mid] < target) {
                left = mid +1;
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        int size = 10_000_000;
        int[] collection = new int[size];

        Random random = new Random();
        collection[0] = random.nextInt(10);

        for (int i = 1; i < size; i++) {
            collection[i] = collection[i - 1] + random.nextInt(10) + 1;
        }

        long start = System.nanoTime();
        for (int i = 0; i < 1000; i++) {
            int target = collection[random.nextInt(size)];
//            System.out.println("Iteracja " + i + ": " + target + '\n');
            binarySearch(collection, target);
        }

        long end = System.nanoTime();

        System.out.printf("1000 search time: %d ms", (end - start) / 1_000_000);
    }
}
