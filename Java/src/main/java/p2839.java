import java.io.*;

public class p2839 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int kilogram = Integer.parseInt(br.readLine());
		int result = -1;

		if(kilogram % 3 == 0) result = kilogram / 3;

		for(int i = 1; i <= kilogram / 5; i++) {
			for(int j = 1; j <= kilogram / 3; j++) {
				if(kilogram % (5 * i + 3 * j) == 0) result = i + j;
			}
		}

		if(kilogram % 5 == 0) result = kilogram / 5;

		bw.write(String.valueOf(result));
		br.close();
		bw.close();
	}
}
