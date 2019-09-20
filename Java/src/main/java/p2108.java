import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class p2108 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int testCase = Integer.parseInt(br.readLine());
		int[] testNum = new int[testCase];

		for(int i = 0; i < testCase; i++) {
			testNum[i] = Integer.parseInt(br.readLine());
		}

		double avg = 0;
		for(int i = 0; i < testCase; i++) avg += testNum[i];

		bw.write(String.valueOf(Math.round(0.1 * (avg * 10 / testCase))) + '\n');

		Arrays.sort(testNum);
		bw.write(testNum[testCase / 2] + "\n");

		HashMap<Integer, Integer> hashMap = new HashMap<>();

		for(int i = -4000; i <= 4000; i++) hashMap.put(i, 0);
		for(int i = 0; i < testCase; i++) {
			int temp = hashMap.get(testNum[i]);
			hashMap.replace(testNum[i], temp + 1);
		}

		ArrayList<Integer> arrayList = new ArrayList<>();

		int max = 0;
		for(int i = -4000; i <= 4000; i++) {
			if(max < hashMap.get(i)) max = hashMap.get(i);
		}
		for(int i = -4000; i <= 4000; i++) {
			if(hashMap.get(i) == max) arrayList.add(i);
		}

		int maxCount = arrayList.size() == 1 ? arrayList.get(0) : arrayList.get(1);
		bw.write(maxCount + "\n");

		int down = 0;
		for(int i = -4000; i < 4000; i++) {
			if(hashMap.get(i) != 0) {
				down = i + 1;
				break;
			}
		}

		int up = 0;
		for(int i = 4000; i > -4000; i--) {
			if(hashMap.get(i) != 0) {
				up = i + 1;
				break;
			}
		}

		if(testCase == 1) up = down;
		bw.write(String.valueOf(up - down));
		bw.close();
		br.close();
	}
}
