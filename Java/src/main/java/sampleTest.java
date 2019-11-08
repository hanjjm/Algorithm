import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class sampleTest {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String s = br.readLine();
		StringBuilder sb = new StringBuilder(s);
		int n = Integer.parseInt(br.readLine());
		String result = "";

		for(int i = 0; i < s.length(); i++) {
			int tempNum = (int)s.charAt(i);
			if(tempNum >= 60 && tempNum <= 90) {
				tempNum += n;
				if(tempNum > 90) tempNum -= 26;
			} else if(tempNum >= 97) {
				tempNum += n;
				if(tempNum > 122) tempNum -= 26;
			}
			result += String.valueOf((char)tempNum);
		}

		System.out.println(result);

	}
}
