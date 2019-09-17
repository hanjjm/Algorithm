import java.io.*;
import java.util.StringTokenizer;

public class p10250 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();

		int testCase = Integer.parseInt(br.readLine());

		while(testCase --> 0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			Hotel hotel = new Hotel(st.nextToken(), st.nextToken(), Integer.parseInt(st.nextToken()));
			String right = null;
			String up = null;
			if(hotel.guestNum > Integer.parseInt(hotel.height)) {
				if(hotel.guestNum % Integer.parseInt(hotel.height) == 0) {
					right = String.valueOf(hotel.guestNum / Integer.parseInt(hotel.height));
					up = hotel.height;
				} else {
					right = String.valueOf(hotel.guestNum / Integer.parseInt(hotel.height) + 1);
					up = String.valueOf(hotel.guestNum % Integer.parseInt(hotel.height));
				}

				if (right.length() == 1) right = "0" + right;

				/* 이렇게 또한 가능하다!!
				right = hotel.guestNum % Integer.parseInt(hotel.height) == 0 ?
						String.valueOf(hotel.guestNum / Integer.parseInt(hotel.height)) :
						String.valueOf(hotel.guestNum / Integer.parseInt(hotel.height) + 1);
				up = hotel.guestNum % Integer.parseInt(hotel.height) == 0 ?
						hotel.height : String.valueOf(hotel.guestNum % Integer.parseInt(hotel.height));

				right = right.length() == 1 ? "0" + right : right;*/
			} else {
				up = String.valueOf(hotel.guestNum);
				right = "01";
			}

			sb.append(up.concat(right) + "\n");
		}

		bw.write(sb.toString());
		br.close();
		bw.close();
	}
}

class Hotel {
	String height, width;
	int guestNum;

	public Hotel(String height, String width, int guestNum) {
		this.height = height;
		this.width = width;
		this.guestNum = guestNum;
	}
}
