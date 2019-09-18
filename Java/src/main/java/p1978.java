import java.io.*;
import java.util.StringTokenizer;

public class p1978 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int testCase = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());

		int result = 0;

		for(int i = 0; i < testCase; i++) {
			if(checkPrimeNumber(Integer.parseInt(st.nextToken()))) result++;
		}

		bw.write(String.valueOf(result));
		br.close();
		bw.close();
	}

	public static boolean checkPrimeNumber(int num) {
		int checkNumber = 0;
		if(num == 1) return false;
		for(int i = 2; i < num; i++) {
			if(num % i == 0) checkNumber = 1;
		}

		return checkNumber == 0 ? true : false;
	}
}
