import java.io.*;

public class p1904 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int testCase = Integer.parseInt(br.readLine());
		int[] resultNum = new int[testCase];

		resultNum[0] = 1;
		if(testCase >= 2) resultNum[1] = 2;
		for(int i = 2; i < testCase; i++) {
			resultNum[i] = (resultNum[i - 1] + resultNum[i - 2]) % 15746;
		}

		bw.write(String.valueOf(resultNum[testCase - 1] % 15746));
		bw.close();
		br.close();
	}
}
