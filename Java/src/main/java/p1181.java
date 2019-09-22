import java.io.*;
import java.util.Arrays;
import java.util.Comparator;

public class p1181 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int testCase = Integer.parseInt(br.readLine());
		String[] words = new String[testCase];

		for (int i = 0; i < testCase; i++) words[i] = br.readLine();

		Arrays.sort(words, new Comparator<String>() {
			@Override
			public int compare(String o1, String o2) {
				return Integer.compare(o1.length(), o2.length());
			}
		});

		/*
		https://hongku.tistory.com/254 참고하였음.
		*/

		int j;
		for(int i = 0; i < testCase; i++) {
			for(j = i + 1; j < testCase; j++) {
				if(words[i].length() != words[j].length()) break;
			}
			Arrays.sort(words, i, j);
			i = j - 1;
		}

		bw.write(words[0] + "\n");
		for(int i = 1; i < testCase; i++) {
			if(!words[i].equals(words[i - 1])) bw.write(words[i] + "\n");
		}

		bw.close();
		br.close();
	}
}
