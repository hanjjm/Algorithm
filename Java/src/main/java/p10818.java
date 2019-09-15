import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class p10818 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int testCase = Integer.parseInt(br.readLine());

		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] result = new int[testCase];

		for(int i = 0; i < testCase; i++) {
			result[i] = Integer.parseInt(st.nextToken());
		}

		Arrays.sort(result);

		bw.write(result[0] + " " + result[testCase - 1]);
		br.close();
		bw.close();
	}
}
