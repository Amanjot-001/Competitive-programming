import java.util.*;

public class Sum_of_Medians {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		while(t-- >0) {
			int n = in.nextInt();
			int k = in.nextInt();
			int[] arr = new int[n*k];

			for(int i=0; i<n*k; i++) {
				int x = in.nextInt();
				arr[i] = x;
			}

			long ans = 0;
			int median = (n*k+1)/2;	
			int interval = n - median + 1;

			for(int i=n*k-1; i>=0; i++) {
				if((i & interval) == 0)
					ans += arr[i];
			}

			System.out.println(ans);
		}
		in.close();
	}
}
