import java.util.Arrays;
import sort.*;

public class Test {

    public static void main(String[] args) {

        int[] data = {5, 22, 9, -10, 0, 7, 4, 8, 0, 4};

        sort.BogoSort sorter = new sort.BogoSort(data);

        System.out.println("Original: " + Arrays.toString(data));
        sorter.sortAscending();
        System.out.println("Ascending: " + sorter);
        sorter.sortDescending();
        System.out.println("Descending: " + sorter);

    }

}
