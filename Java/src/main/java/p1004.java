import java.util.ArrayList;
import java.util.Scanner;

public class p1004 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		ArrayList<Integer> result = new ArrayList<Integer>();

		int x1, y1;
		int x2, y2;
		int x3, y3, r3;
		int planetCount;
		int resultCount = 0;
		double distanceStart, distanceArrive;
		int testCase = scanner.nextInt();

		while(testCase != 0) {
			x1 = scanner.nextInt();
			y1 = scanner.nextInt();
			x2 = scanner.nextInt();
			y2 = scanner.nextInt();

			planetCount = scanner.nextInt();

			for(int i = 0; i < planetCount; i++) {
				x3 = scanner.nextInt();
				y3 = scanner.nextInt();
				r3 = scanner.nextInt();

				distanceStart = Math.sqrt(Math.pow(x1 -x3, 2) + Math.pow(y1-y3, 2));
				distanceArrive = Math.sqrt(Math.pow(x2 -x3, 2) + Math.pow(y2-y3, 2));

				if((r3 > distanceArrive && r3 < distanceStart)
						|| (r3 < distanceArrive && r3 > distanceStart)) {
					resultCount++;
				}
			}

			result.add(resultCount);
			resultCount = 0;
			testCase--;
		}

		for(int i = 0; i < result.size(); i++) System.out.println(result.get(i));
	}
}
