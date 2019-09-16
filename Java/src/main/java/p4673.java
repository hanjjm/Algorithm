import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;

public class p4673 {
	public static boolean selfNumber[] = new boolean[10000];

	public static void main(String[] args) throws IOException {
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		for(int i = 0; i < 10000; i++) selfNumber[i] = true;

		makeSelfNumber(selfNumber);

		for(int i = 0; i < 10000; i++) if(selfNumber[i] == true) sb.append(i + 1 + "\n");

		bw.write(sb.toString());
		bw.close();
	}

	public static void makeSelfNumber(boolean[] selfNumber) {
		for(int num = 1; num < 10001; num++) {
			int notSelfNum = num;

			for(int i = 0; i < String.valueOf(num).length(); i++) {
				notSelfNum += Character.getNumericValue(String.valueOf(num).charAt(i));
				if(notSelfNum > 10000) notSelfNum = 10000;
			}

			selfNumber[notSelfNum - 1] = false;
		}
	}
}
