package sort;

import java.util.Random;

public class BogoSort extends Sorter {

    private int[] indices;
    private Random rand;

    public BogoSort(int[] data) {
        super(data);
        rand = new Random();
    }

    public void sortAscending() {
        while (!isSortedAscending()) {
            shuffle();
        }
    }

    public void sortDescending() {
        while (!isSortedDescending()) {
            shuffle();
        }
    }

    private void shuffle() {
        for (int i=data.length-1; i > 0; i--) {
            int index = rand.nextInt(i+1);
            int temp = data[index];
            data[index] = data[i];
            data[i] = temp;
        }
    }

    private boolean isSortedAscending() {
        for (int i=1; i < data.length; i++) {
            if (data[i-1] > data[i]) return false;
        }
        return true;
    }

    private boolean isSortedDescending() {
        for (int i=1; i < data.length; i++) {
            if (data[i-1] < data[i]) return false;
        }
        return true;
    }

}
