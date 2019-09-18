import java.io.*;

public class p2581 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int min = Integer.parseInt(br.readLine());
		int max = Integer.parseInt(br.readLine());

		int sum = 0;
		int minNum = 0;

		for(int i = max; i >= min; i--) {
			if(checkPrimeNumber(i)) {
				sum += i;
				minNum = i;
			}
		}

		if(minNum == 0) bw.write(String.valueOf(-1));
		else bw.write(sum + "\n" + minNum);

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
