import java.io.*;

public class p1065 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		bw.write(countHansu(Integer.parseInt(br.readLine())));
		
		bw.flush();
		br.close();
		bw.close();
	}

	public static String countHansu(int num) {
		int count = 0;

		if(num < 100) count = num;
		else if (num < 1000) {
			count = 99;
			for(int i = 100; i <= num; i++) {
				if (Character.getNumericValue(String.valueOf(i).charAt(0)) +
						Character.getNumericValue(String.valueOf(i).charAt(2)) ==
						2 * Character.getNumericValue(String.valueOf(i).charAt(1)))
					count++;
			}
		} else if (num == 1000) count = 144;

		return String.valueOf(count);
	}
}
