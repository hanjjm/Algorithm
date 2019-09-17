import java.io.*;
import java.util.StringTokenizer;

public class p2869 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int up = Integer.parseInt(st.nextToken());
		int down = Integer.parseInt(st.nextToken());
		int height = Integer.parseInt(st.nextToken());
		int day = (height - up) / (up - down);
		int remain = (height - up) % (up - down) + up;
		if(remain <= up) day++;
		else day += 2;

		bw.write(String.valueOf(day));
		br.close();
		bw.close();
	}
}
