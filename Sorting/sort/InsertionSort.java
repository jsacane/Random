package sort;

public class InsertionSort extends Sorter {

    public InsertionSort(int[] data) {
        super(data);
    }

    public void sortAscending() {
        for (int i=1; i < data.length; i++) {
            int index = data[i];
            int j = i;
            while (j > 0 && data[j-1] > index) {
                data[j] = data[j-1];
                j--;
            }
            data[j] = index;
        }
    }

    public void sortDescending() {
        for (int i=1; i < data.length; i++) {
            int index = data[i];
            int j = i;
            while (j > 0 && data[j-1] < index) {
                data[j] = data[j-1];
                j--;
            }
            data[j] = index;
        }
    }

}
