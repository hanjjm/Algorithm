import java.io.*;
import java.util.StringTokenizer;

public class p1932 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int testCase = Integer.parseInt(br.readLine());
		int[][] testNum = new int[testCase][testCase];

		for(int i = 0; i < testCase; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j = 0; j < i + 1; j++) {
				testNum[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		testNum[1][0] += testNum[0][0];
		testNum[1][1] += testNum[0][0];

		for(int i = 2; i < testCase; i++) {
			for(int j = 0; j < i + 1; j++) {
				if(j == 0) testNum[i][j] += testNum[i -1][j];
				else if(j == i) testNum[i][j] += testNum[i -1][j - 1];
				else testNum[i][j] += Math.max(testNum[i - 1][j - 1], testNum[i -1][j]);
			}
		}

		int max = testNum[testCase - 1][0];
		for(int i = 1; i < testCase; i++) {
			if(max < testNum[testCase - 1][i]) max = testNum[testCase - 1][i];
		}

		bw.write(String.valueOf(max));
		bw.close();
		br.close();
	}
}
