import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class p2798 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int cardCount = Integer.parseInt(st.nextToken());
		int targetNum = Integer.parseInt(st.nextToken());

		int[] cardNum = new int[cardCount];

		st = new StringTokenizer(br.readLine());

		for(int i = 0; i < cardCount; i++) cardNum[i] = Integer.parseInt(st.nextToken());

		ArrayList<Integer> arrayList = new ArrayList<>();

		for(int i = 0; i < cardCount - 2; i++) {
			for(int j = i + 1; j < cardCount - 1; j++) {
				for(int k = j + 1; k < cardCount; k++) {
					if(cardNum[i] + cardNum[j] + cardNum[k] <= targetNum) arrayList.add(targetNum - (cardNum[i] + cardNum[j] + cardNum[k]));
				}
			}
		}

		Collections.sort(arrayList);

		bw.write(String.valueOf(targetNum - arrayList.get(0)));
		br.close();
		bw.close();
	}
}
