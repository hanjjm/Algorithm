	import java.io.*;

	public class p10809 {

		public static void main(String[] args) throws IOException {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
			StringBuilder sb = new StringBuilder();

			String num = br.readLine();
			int[] result = new int[26];

			for(int i = 0; i < 26; i++) result[i] = -1;

			for(int i = num.length() - 1; i >= 0; i--) {
				for(int j = 97; j <= 122; j++) {
					if(num.charAt(i) == j) result[j - 97] = i;
				}
			}

			for(int i = 0; i < 26; i++) sb.append(result[i] + " ");

			bw.write(sb.toString());
			br.close();
			bw.close();
		}
	}
