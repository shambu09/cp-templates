import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Solution solution = new Solution();

        Scanner scanner = new Scanner(System.in);
        int poured = scanner.nextInt();
        int qr = scanner.nextInt();
        int qg = scanner.nextInt();
        scanner.close();

        System.out.println(solution.champagneTower(poured, qr, qg));
    }

    public double[][] cache = new double[105][105];

    public double champagneTower(int poured, int query_row, int query_glass) {
        for (double[] arr : cache) {
            Arrays.fill(arr, -1);
        }

        return Math.min(1, _deep(poured, query_row, query_glass));
    }

    public double _deep(int poured, int qr, int qg) {
        if (qr < 0 || qg < 0 || qg > qr)
            return 0;
        if (qr == 0)
            return poured;
        if (cache[qr][qg] != -1)
            return cache[qr][qg];

        double left = Math.max(_deep(poured, qr - 1, qg) - 1, 0);
        double right = Math.max(_deep(poured, qr - 1, qg - 1) - 1, 0);
        double res = (left + right) / 2;

        return cache[qr][qg] = res;
    }
}