import java.io.*;
import java.util.Arrays;
import java.util.Collections;

public class p1427 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String testNum = br.readLine();

		Integer[] sort = new Integer[testNum.length()];

		for(int i = 0; i < testNum.length(); i++) sort[i] = Character.getNumericValue(testNum.charAt(i));

		Arrays.sort(sort, Collections.reverseOrder());

		for(int value : sort) bw.write(String.valueOf(value));

		bw.close();
		br.close();
	}
}
