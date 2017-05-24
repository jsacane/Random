package Sort;

public class BubbleSort extends Sorter {

    public BubbleSort(int[] data) {
        super(data);
    }

    public void sortAscending() {
        for (int i=0; i < data.length-1; i++) {
            for (int j=i+1; j < data.length; j++) {
                if (data[j] < data[i]) {
                    int temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
            }
        }
    }

    public void sortDescending() {
        for (int i=0; i < data.length-1; i++) {
            for (int j=i+1; j < data.length; j++) {
                if (data[j] > data[i]) {
                    int temp = data[i];
                    data[i] = data[j];
                    data[j] = temp;
                }
            }
        }
    }

}
