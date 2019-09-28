import java.io.*;

public class p1463 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int testNum = Integer.parseInt(br.readLine());
		int[] result = new int[testNum];
		result[0] = 0;
		if(testNum != 1) result[1] = 1;

		for(int i = 2; i < testNum; i++) {
			if((i + 1) % 3 == 0) result[i] += Math.min(result[(i + 1) / 3 - 1] + 1, result[i - 1] + 1);
			else if((i + 1) % 2 == 0) result[i] += Math.min(result[(i + 1) / 2 - 1] + 1, result[i - 1] + 1);
			else result[i] += (result[i - 1] + 1);
		}

		bw.write(String.valueOf(result[testNum - 1]));
		bw.close();
		br.close();
	}
}
