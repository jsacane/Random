package sort;

import java.util.Arrays;

abstract class Sorter {

    protected int[] originalData;
    protected int[] data;

    public Sorter(int[] data) {
        this.originalData = Arrays.copyOf(data, data.length);
        this.data = data;
    }

    public String toString() {
        return Arrays.toString(data);
    }

    public int[] getOriginal() {
        return originalData;
    }

    abstract void sortAscending();
    abstract void sortDescending();
}
