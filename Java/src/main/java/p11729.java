import java.io.*;

public class p11729 {
	public static StringBuilder sb = new StringBuilder();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int testCase = Integer.parseInt(br.readLine());

		hanoi(testCase, 1, 3);

		sb.insert(0, (int)Math.pow(2, testCase) - 1 + "\n");
		bw.write(sb.toString());
		bw.flush();
		bw.close();
	}

	public static void hanoi(int testCase, int from, int to) throws IOException {
		if(testCase == 0) return;
		hanoi(testCase - 1, from, 6 - from - to);
		sb.append(from + " " + to + "\n");
		hanoi(testCase - 1, 6 - from - to, to);
	}
}
