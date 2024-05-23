import java.util.*;

public class Make_it_Beautiful {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();

		while(t-->0) {
			int n = in.nextInt();
			int[] arr = new int[n];

			for(int i=0; i<n; i++) {
				int x = in.nextInt();
				arr[i] = x;
			}

			if(arr[0] != arr[n-1]) {
				int temp = arr[0];
				arr[0] = arr[n-1];
				arr[n-1] = arr[1];
				arr[1] = temp;

				System.out.println("YES");
				for(int i=0; i<n; i++)
					System.out.print(arr[i] + " ");
				System.out.println("");
			}
			else {
				System.out.println("NO");
			}
		}
		in.close();
	}
}
