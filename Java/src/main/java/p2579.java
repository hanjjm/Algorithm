import java.io.*;

public class p2579 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int testCase = Integer.parseInt(br.readLine());
		int[] eachStepNum = new int[testCase];
		int[] result = new int[testCase];

		for(int i = 0; i < testCase; i++) eachStepNum[i] = Integer.parseInt(br.readLine());

		result[0] = eachStepNum[0];
		result[1] = eachStepNum[0] + eachStepNum[1];
		result[2] = Math.max(eachStepNum[0] + eachStepNum[2], eachStepNum[1] + eachStepNum[2]);

		for(int i = 3; i < testCase; i++) {
			result[i] = Math.max(eachStepNum[i - 1] + result[i - 3], result[i - 2]) + eachStepNum[i];
		}

		bw.write(String.valueOf(result[testCase - 1]));
		bw.close();
		br.close();
	}
}
