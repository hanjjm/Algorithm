import java.io.*;

public class p9461 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		long[] result = new long[100];

		for(int i = 0; i <= 2; i++) result[i] = 1;
		result[3] = 2;
		result[4] = result[3];
		for(int i = 5; i < 100; i++) {
			result[i] = result[i - 1] + result[i - 5];
		}

		int testCase = Integer.parseInt(br.readLine());
		while(testCase --> 0) {
			int eachNum = Integer.parseInt(br.readLine());
			bw.write(result[eachNum - 1] + "\n");
		}
		bw.close();
		br.close();
	}
}
