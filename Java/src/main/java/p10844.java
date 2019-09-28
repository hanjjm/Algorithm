import java.io.*;

public class p10844 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int testNum = Integer.parseInt(br.readLine());
		long[][] result = new long[testNum][9];

		for(int i = 0; i < 9; i++) result[0][i] = 1;
		if(testNum != 1) {
			for (int i = 0; i < 8; i++) result[1][i] = 2;
			result[1][8] = 1;
		}

		for(int i = 2; i < testNum; i++) {
			for(int j = 0; j < 9; j++) {
				if (j == 0) result[i][0] = (result[i - 2][0] + result[i - 1][1]) % 1000000000;
				else if (j == 8) result[i][8] = result[i - 1][7] % 1000000000;
				else result[i][j] = (result[i - 1][j - 1] + result[i - 1][j + 1]) % 1000000000;
			}
		}

		long resultNum = 0;
		for(long value : result[testNum - 1]) resultNum += value;

		bw.write(String.valueOf(resultNum % 1000000000));
		bw.close();
		br.close();
	}
}
