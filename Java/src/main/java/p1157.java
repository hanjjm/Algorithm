import java.io.*;

public class p1157 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int[] result = new int[26];
		String testCase = br.readLine();

		for(int i = 0; i < 26; i++) result[i] = 0;

		for(int i = 0; i < testCase.length(); i++) {
			for(int j = 65; j <= 90; j++) if(testCase.charAt(i) == j) result[j - 65]++;
			for(int j = 97; j <= 122; j++) if(testCase.charAt(i) == j) result[j - 97]++;
		}

		int whereChar = 0;
		for(int i = 0; i < 26; i++) {
			if(result[i] >= result[whereChar]) whereChar = i;
		}

		char resultChar = (char)(whereChar + 65);

		for(int i = 0; i < 26; i++) if(result[whereChar] == result[i] && i != whereChar) resultChar = '?';

		bw.write(resultChar);
		bw.flush();
		br.close();
		bw.close();
	}
}
