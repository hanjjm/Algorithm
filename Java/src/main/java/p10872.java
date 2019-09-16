import java.io.*;

public class p10872 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		bw.write(String.valueOf(factorial(Integer.parseInt(br.readLine()))));
		bw.flush();
		br.close();
		bw.close();
	}

	public static int factorial(int num) {
		if(num == 0) return 1;
		else if(num == 1) return 1;
		else return num * factorial(num - 1);
	}
}
