import java.io.*;
import java.util.ArrayList;

public class p1436 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int num = Integer.parseInt(br.readLine());
		ArrayList<Integer> arrayList = new ArrayList<>();

		for(int i = 0; i < 10000000; i++) {
			String testNUm = String.valueOf(i);
			if(testNUm.contains("666")) arrayList.add(i);
			if(arrayList.size() == num) break;
		}

		bw.write(String.valueOf(arrayList.get(num - 1)));
		bw.close();
		br.close();
	}
}
