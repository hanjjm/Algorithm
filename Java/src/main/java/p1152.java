import java.io.*;

public class p1152 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		String testCase = br.readLine();

		int wordCount = 1;
		for(int i = 0; i < testCase.length(); i++) {
			if(testCase.charAt(i) == ' ') wordCount++;
		}

		if(testCase.charAt(0) == ' ') wordCount--;
		if(testCase.charAt(testCase.length() - 1) == ' ') wordCount--;

		bw.write(String.valueOf(wordCount));
		bw.close();
		br.close();
	}
}
