import java.io.*;
import java.math.BigInteger;

public class p11720 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int numCount = Integer.parseInt(br.readLine());
		String num = br.readLine();
		int result = 0;

		for(int i = 0; i < numCount; i++) {
			if(Character.getNumericValue(String.valueOf(num).charAt(i)) > 0)
				result += Character.getNumericValue(String.valueOf(num).charAt(i));
		}

		bw.write(String.valueOf(result));
		bw.flush();
		br.close();
		bw.close();
	}
}
