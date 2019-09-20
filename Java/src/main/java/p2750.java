import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

public class p2750 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		int testCase = Integer.parseInt(br.readLine());
		ArrayList<Integer> arrayList = new ArrayList<>();

		while(testCase --> 0) {
			arrayList.add(Integer.parseInt(br.readLine()));
		}

		Collections.sort(arrayList);

		for(int value : arrayList) sb.append(value + "\n");
		bw.write(sb.toString());
		bw.close();
		br.close();
	}
}
