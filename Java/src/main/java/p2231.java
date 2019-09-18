import java.io.*;

public class p2231 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int num = Integer.parseInt(br.readLine());
		int result = 0;

		for(int i = num; i >= 1; i--) {
			int testNum = i;
			for(int j = 0; j < String.valueOf(i).length(); j++) {
				testNum += Character.getNumericValue(String.valueOf(i).charAt(j));
			}
			if(testNum == num) result = i;
		}

		bw.write(String.valueOf(result));
		br.close();
		bw.close();
	}
}
