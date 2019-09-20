import java.io.*;

public class p10989 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int testCase = Integer.parseInt(br.readLine());
		int[] entireArray = new int[testCase];

		for(int i = 0; i < entireArray.length; i++) entireArray[i] = Integer.parseInt(br.readLine());

		int[] beforeSort = new int[10000];
		int[] afterSort = new int[testCase];

		for(int i = 0; i < beforeSort.length; i++) beforeSort[i] = 0;

		for(int i = 0; i < entireArray.length; i++) beforeSort[entireArray[i] - 1]++;

		for(int i = 1; i < beforeSort.length; i++) beforeSort[i] += beforeSort[i - 1];

		for(int i = entireArray.length - 1; i >= 0; i--) {
			afterSort[beforeSort[entireArray[i] - 1] - 1] = entireArray[i];
			beforeSort[entireArray[i] - 1]--;
		}

		for(int value : afterSort) bw.write(value + "\n");
		bw.close();
		br.close();
	}
}
