import java.io.*;

public class p2292 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int targetRoom = Integer.parseInt(br.readLine());
		int result = 1;
		int compareNumber = 1;

		while(true) {
			if(compareNumber >= targetRoom) break;
			compareNumber += 6 * result;
			result++;
		}

		bw.write(String.valueOf(result));
		br.close();
		bw.close();
	}
}
