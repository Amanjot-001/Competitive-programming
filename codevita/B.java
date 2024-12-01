import java.util.*;

public class B {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int m = in.nextInt();

        List<Set<Integer>> f = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            f.add(new HashSet<>());
        }

        for (int i = 0; i < m; i++) {
            int u = in.nextInt();
            int v = in.nextInt();
            f.get(u).add(v);
            f.get(v).add(u);
        }

        int k = in.nextInt();
        int d = 1;
        int temp = n;

        boolean[] w = new boolean[n];
        Arrays.fill(w, true);

        while (temp < k) {
            boolean[] nw = new boolean[n];
            int newTemp = 0;

            for (int i = 0; i < n; i++) {
                int cnt = 0;
                for (int fr : f.get(i)) {
                    if (w[fr])
                        cnt++;
                }

                if (w[i] && cnt == 3) {
                    nw[i] = true;
                } else if (!w[i] && cnt < 3) {
                    nw[i] = true;
                }

                if (nw[i]) {
                    newTemp++;
                }
            }

            w = nw;
            temp += newTemp;
            d++;
        }

        System.out.print(d);
        in.close();
    }
}