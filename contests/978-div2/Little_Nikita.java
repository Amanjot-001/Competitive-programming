import java.util.Scanner;

public class Little_Nikita {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();

		while(t-- > 0) {
			int n = in.nextInt();
			int m = in.nextInt();

			if(n - m >= 0 && (n - m) % 2 == 0)
				System.out.println("YES");
			else
				System.out.println("NO");
		}
	}
}
