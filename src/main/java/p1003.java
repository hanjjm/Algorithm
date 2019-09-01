import java.util.ArrayList;
import java.util.Scanner;

public class p1003 {
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int testCase = scanner.nextInt();
		int[] result = new int[testCase];
		ArrayList<Integer> zeroResult = new ArrayList<Integer>();
		ArrayList<Integer> oneResult = new ArrayList<Integer>();

		zeroResult.add(1);
		zeroResult.add(0);
		oneResult.add(0);
		oneResult.add(1);

		int setNum = 2;

		while(setNum != 41) {
			zeroResult.add(zeroResult.get(setNum - 1) + zeroResult.get(setNum - 2));
			oneResult.add(oneResult.get(setNum - 1) + oneResult.get(setNum - 2));
			setNum++;
		}

		for(int i = 0; i < testCase; i++) {
			result[i] = scanner.nextInt();
		}

		for(int i = 0; i < testCase; i++) {
			System.out.println(zeroResult.get(result[i]) + " " + oneResult.get(result[i]));
		}

		scanner.close();
	}
}
