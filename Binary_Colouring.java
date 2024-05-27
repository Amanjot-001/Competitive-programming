import java.util.Scanner;

public class Binary_Colouring {

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t-- > 0) {
            int x = in.nextInt();

            int[] ans = new int[32];
			// decimal to binary
            for (int i = 29; i >= 0; i--) {
                int c = 1 << i;
                if ((x & c) == c) {
                    ans[i] = 1;
                }
            }

			// if anywhere there are consecutive ones then just change like 1111 to 1000-1
            int i = 0;
            while (i <= 31) {
                if (ans[i] == 0) {
                    i++;
                } else {
                    int j = i + 1;
                    while (j <= 31 && ans[j] == 1) {
                        ans[j] = 0;
                        j++;
                    }

                    if (j != i + 1 && j <= 31) {
                        ans[j] = 1;
                        ans[i] = -1;
                        i = j;
                    } else {
                        i++;
                    }
                }
            }

			System.out.println(32);
			for(int it: ans)
				System.out.print(it + " ");
			System.out.println();
        }
        in.close();
    }
}
