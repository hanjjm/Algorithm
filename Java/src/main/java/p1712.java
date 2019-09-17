import java.io.*;
import java.util.StringTokenizer;

public class p1712 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());

		int fixedPrice = Integer.parseInt(st.nextToken());
		int changingPrice = Integer.parseInt(st.nextToken());
		int notebookPrice = Integer.parseInt(st.nextToken());
		int breakEvenPoint;

		if(changingPrice >= notebookPrice) breakEvenPoint = -2;
		else breakEvenPoint = fixedPrice / (notebookPrice - changingPrice);

		bw.write(String.valueOf(breakEvenPoint + 1));
		br.close();
		bw.close();
	}
}
