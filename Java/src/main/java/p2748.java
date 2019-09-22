import java.io.*;

public class p2748 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int testNum = Integer.parseInt(br.readLine());

		long[] resultNum = new long[testNum + 1];

		for(int i = 0; i <= testNum; i++) {
			if (testNum == 0) resultNum[0] = 0;
			else if (testNum == 1) resultNum[1] = 1;
			else {
				if(i == 0 || i == 1) continue;
				resultNum[0] = 0;
				resultNum[1] = 1;
				resultNum[i] = resultNum[i - 1] + resultNum[i - 2];
			}
		}

		bw.write(String.valueOf(resultNum[testNum]));
		bw.close();
		br.close();
	}
}
