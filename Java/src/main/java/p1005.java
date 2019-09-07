import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class p1005 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int testCase = scanner.nextInt();
		int timer = 0;

		Queue<Integer> queue = new LinkedList<Integer>();
		ArrayList<Integer> delay = new ArrayList<Integer>();
		ArrayList<Integer> result = new ArrayList<Integer>();
		ArrayList<Integer> building = new ArrayList<Integer>();

		for(int i = 0; i < testCase; i++) {
			int buildingCount = scanner.nextInt();
			int ruleCount = scanner.nextInt();

			for(int j = 0; j < buildingCount; j++) {
				int eachDelay = scanner.nextInt();
				delay.add(eachDelay);
			}

			int[][] order = new int[ruleCount][2];

			for(int k = 0; k < ruleCount; k++) {
				int firstBuilding = scanner.nextInt();
				int secondBuilding = scanner.nextInt();

				order[k][0] = firstBuilding;
				order[k][1] = secondBuilding;
			}

			int finalBuilding = scanner.nextInt();




		}


	}
}
