import java.io.*;

public class p4948 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int[] primeNumber = new int[123456 * 2 + 1];
		for(int i = 0; i <= 123456 * 2; i++) primeNumber[i] = 0;

		for(int i = 2; i * i <= 123456 * 2; i++) {
			for(int j = i * i; j <= 123456 * 2; j += i) {
				primeNumber[j] = 1;
			}
		}

		int index = -1, prime = 0;
		while(true) {
			index = Integer.parseInt(br.readLine());
			if(index == 0) break;
			for(int i = index + 1; i <= 2 * index; i++) {
				if(primeNumber[i] == 0) prime++;
			}
			bw.write(prime + "\n");
			prime = 0;
		}
		bw.close();
	}
}
