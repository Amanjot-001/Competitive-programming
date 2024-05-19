
import java.util.*;

public class blank_Space {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();

		while(t-->0) {
			int n = in.nextInt();
			int cnt=0, max=0;
			for(int i=0; i<n; i++) {
				int input = in.nextInt();
				if(input == 0)
					cnt++;
				else {
					max = Math.max(cnt, max);
					cnt = 0;
				}
			}

			max = Math.max(cnt, max);
			System.out.println(max);
		}
		in.close();
	}
}
