import java.io.*;
import java.util.StringTokenizer;

public class p1929 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		StringTokenizer st = new StringTokenizer(br.readLine());

		int min = Integer.parseInt(st.nextToken());
		int max = Integer.parseInt(st.nextToken());

		for(int i = min; i <= max; i++) {
			if(checkPrimeNumber(i)) sb.append(i + "\n");
		}

		bw.write(sb.toString());
		br.close();
		bw.close();
	}

	public static boolean checkPrimeNumber(int num) {
		int checkNumber = 0;
		if(num == 1) return false;
		for(int i = 2; i <= Math.sqrt(num); i++) {
			if(num % i == 0) checkNumber = 1;
		}

		return checkNumber == 0 ? true : false;
	}
}
