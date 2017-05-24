import java.util.Arrays;
import Sort.*;

public class Test {

    public static void main(String[] args) {

        int[] data = {5, 22, 9, -10, 0, 7, 4, 8, 0, 4};

        Sort.InsertionSort sorter = new Sort.InsertionSort(data);

        System.out.println("Original: " + Arrays.toString(data));
        sorter.sortAscending();
        System.out.println("Ascending: " + sorter);
        sorter.sortDescending();
        System.out.println("Descending: " + sorter);

    }

}
