import java.util.PriorityQueue;

public class Solution {
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        // Define a max-heap with custom comparator for highest gain
        PriorityQueue<double[]> maxHeap = new PriorityQueue<>((a, b) -> Double.compare(b[0], a[0]));

        // Add each class to the heap with its initial gain
        for (int[] cls : classes) {
            int passi = cls[0];
            int totali = cls[1];
            double gain = gainAfterAddingStudent(passi, totali);
            maxHeap.offer(new double[]{gain, passi, totali});
        }

        // Assign extra students to the classes
        while (extraStudents > 0) {
            double[] top = maxHeap.poll();
            double currentGain = top[0];
            int passi = (int) top[1];
            int totali = (int) top[2];

            // Update the class with one extra student
            passi++;
            totali++;
            extraStudents--;

            // Calculate new gain and push back to the heap
            double newGain = gainAfterAddingStudent(passi, totali);
            maxHeap.offer(new double[]{newGain, passi, totali});
        }

        // Calculate the final average pass ratio
        double totalRatio = 0.0;
        while (!maxHeap.isEmpty()) {
            double[] cls = maxHeap.poll();
            int passi = (int) cls[1];
            int totali = (int) cls[2];
            totalRatio += (double) passi / totali;
        }

        return totalRatio / classes.length;
    }

    // Helper method to calculate gain after adding one student
    private double gainAfterAddingStudent(int passi, int totali) {
        double currentRatio = (double) passi / totali;
        double newRatio = (double) (passi + 1) / (totali + 1);
        return newRatio - currentRatio;
    }

    public static void main(String[] args) {
        Solution solver = new Solution();
        int[][] classes1 = {{1, 2}, {3, 5}, {2, 2}};
        int extraStudents1 = 2;
        System.out.println(solver.maxAverageRatio(classes1, extraStudents1)); // Output: 0.78333

        int[][] classes2 = {{2, 4}, {3, 9}, {4, 5}, {2, 10}};
        int extraStudents2 = 4;
        System.out.println(solver.maxAverageRatio(classes2, extraStudents2)); // Output: 0.53485
    }
}
