import java.util.ArrayList;
import java.util.Scanner;

public class p1002 {

	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);

		int testCase = scanner.nextInt();

		ArrayList<Integer> result = new ArrayList<Integer>();

		while(testCase != 0){
			int x1 = scanner.nextInt();
			int y1 = scanner.nextInt();
			int r1 = scanner.nextInt();
			int x2 = scanner.nextInt();
			int y2 = scanner.nextInt();
			int r2 = scanner.nextInt();

			double distance = Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
			result.add(caculateResult(x1, y1, x2, y2, r1, r2, distance));

			testCase--;
		}

		for(int i = 0; i < result.size(); i++){
			System.out.println(result.get(i));
		}

		scanner.close();
	}

	private static int caculateResult(int x1, int y1, int x2, int y2, int r1, int r2, double distance) {
		int result = 0;

		if((r1 + r2 == distance && Math.abs(r1 - r2) < distance) || Math.abs(r1 - r2) == distance) {
			result = 1;
		}

		if (r1 + r2 > distance && Math.abs(r1 - r2) < distance) {
			result = 2;
		}

		if (r1 == r2 && distance == 0) {
			result = -1;
		}

		return result;
	}
}
