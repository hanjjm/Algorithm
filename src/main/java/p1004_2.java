import java.io.*;
import java.util.StringTokenizer;

public class p1004_2 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		int testCase = Integer.parseInt(br.readLine());

		while(testCase --> 0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int[] start = {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};
			int[] end = {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())};

			int planetCount = Integer.parseInt(br.readLine());
			int resultCount = 0;

			while(planetCount --> 0) {
				st = new StringTokenizer(br.readLine());
				Planet planet = new Planet(Integer.parseInt(st.nextToken())
						, Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));

				double distanceStart = Math.sqrt(Math.pow(start[0] - planet.cx, 2) + Math.pow(start[1] -planet.cy, 2));
				double distanceArrive = Math.sqrt(Math.pow(end[0] - planet.cx, 2) + Math.pow(end[1] - planet.cy, 2));

				if((planet.r > distanceArrive && planet.r < distanceStart)
						|| (planet.r < distanceArrive && planet.r > distanceStart)) {
					resultCount++;
				}
			}

			sb.append(resultCount).append("\n");
		}

		wr.write(sb.toString());
		wr.close();
		br.close();
	}
}

class Planet {
	int cx, cy, r;

	public Planet(int cx, int cy, int r) {
		this.cx = cx;
		this.cy = cy;
		this.r = r;
	}
}
