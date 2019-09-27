import java.io.*;
import java.util.StringTokenizer;

public class p1149 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int testCase = Integer.parseInt(br.readLine());
		int[][] building = new int[testCase][3];
		int[][] minCost = new int[testCase][3];

		StringTokenizer st = new StringTokenizer(br.readLine());

		minCost[0][0] = Integer.parseInt(st.nextToken());
		minCost[0][1] = Integer.parseInt(st.nextToken());
		minCost[0][2] = Integer.parseInt(st.nextToken());

		for(int i = 1; i < testCase; i++) {
			st = new StringTokenizer(br.readLine());
			building[i][0] = Integer.parseInt(st.nextToken());
			building[i][1] = Integer.parseInt(st.nextToken());
			building[i][2] = Integer.parseInt(st.nextToken());
		}

		for(int i = 1; i < testCase; i++) {
			minCost[i][0] = Math.min(minCost[i - 1][1], minCost[i - 1][2]) + building[i][0];
			minCost[i][1] = Math.min(minCost[i - 1][0], minCost[i - 1][2]) + building[i][1];
			minCost[i][2] = Math.min(minCost[i - 1][0], minCost[i - 1][1]) + building[i][2];
		}

		bw.write(String.valueOf(Math.min(Math.min(minCost[testCase - 1][0], minCost[testCase - 1][1]), minCost[testCase - 1][2])));
		bw.close();
		br.close();
	}
}
