import java.io.*;
import java.util.StringTokenizer;

public class p1011 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		int testCase = Integer.parseInt(br.readLine());

		while(testCase --> 0) {
			int result = 1;
			long compareNumber = 1;
			long temp = 2;

			StringTokenizer st = new StringTokenizer(br.readLine());

			long distance = -1 * (Integer.parseInt(st.nextToken()) - Integer.parseInt(st.nextToken()));

			for(long i = 1; i <= distance; i++) {
				if(i % 2 == 0) compareNumber++;
				if(temp <= distance) result++;
				temp += compareNumber;
				if(temp > distance) break;
			}

			sb.append(result + "\n");
		}

		bw.write(sb.toString());
		bw.flush();
		br.close();
		bw.close();
	}
}
