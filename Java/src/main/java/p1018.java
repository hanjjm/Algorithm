import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class p1018 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int row = Integer.parseInt(st.nextToken());
		int column = Integer.parseInt(st.nextToken());

		ArrayList<Integer> arrayList = new ArrayList<>();
		char[][] matrix = new char[row][column];

		for(int i = 0; i < row; i++) {
			String line = br.readLine();
			for(int j = 0; j < column; j++) matrix[i][j] = line.charAt(j);
		}

		char[][] chessFirstW = {{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}, {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
				{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}, {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
				{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}, {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
				{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}, {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}};
		char[][] chessFirstB = {{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}, {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
				{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}, {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
				{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}, {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
				{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}, {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}};

		int resultW = 0, resultB = 0;

		for(int i = 0; i <= row - 8; i++) {
			for(int j = 0; j <= column - 8; j++) {
				int tempA = 0, tempB = 0;

				for(int k = i; k < i + 8; k++) {
					for(int l = j; l < j + 8; l++) {
						if (matrix[k][l] != chessFirstW[tempA][tempB]) resultW++;
						if (matrix[k][l] != chessFirstB[tempA][tempB]) resultB++;
						tempB++;
					}
					tempB = 0;
					tempA++;
				}
				tempA = 0;

				arrayList.add(resultB);
				arrayList.add(resultW);

				resultB = 0;
				resultW = 0;
			}
		}
		Collections.sort(arrayList);

		bw.write(String.valueOf(arrayList.get(0)));
		bw.close();
		br.close();
	}
}

/*
이렇게 하면 예외경우때문에 틀림..!
import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class p1018 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int row = Integer.parseInt(st.nextToken());
		int column = Integer.parseInt(st.nextToken());

		ArrayList<Integer> arrayList = new ArrayList<>();
		char[][] matrix = new char[row][column];

		for(int i = 0; i < row; i++) {
			String line = br.readLine();
			for(int j = 0; j < column; j++) matrix[i][j] = line.charAt(j);
		}

		int result = 0;

		for(int i = 0; i <= row - 8; i++) {
			for(int j = 0; j <= column - 8; j++) {
				result = 0;
				if(matrix[i][j] == 'B') {
					int temp = 0;
					for(int k = i; k < i + 8; k++) {
						if(temp == 0) {
							for (int l = j; l < j + 8; l += 2) {
								if (matrix[k][l] == 'W') result++;
							}
							temp = 1;
						} else {
							for (int l = j + 1; l < j + 8; l += 2) {
								if (matrix[k][l] == 'W') result++;
							}
							temp = 0;
						}
					}
					temp = 0;
					for(int k = i; k < i + 8; k++) {
						if(temp == 0) {
							for(int l = j + 1; l < j + 8; l += 2){
								if(matrix[k][l] == 'B') result++;
							}
							temp = 1;
						} else {
							for(int l = j; l < j + 8; l += 2){
								if(matrix[k][l] == 'B') result++;
							}
							temp = 0;
						}
					}
				} else {
					int temp = 0;
					for(int k = i; k < i + 8; k++) {
						if(temp == 0) {
							for (int l = j; l < j + 8; l += 2) {
								if (matrix[k][l] == 'B') result++;
							}
							temp = 1;
						} else {
							for (int l = j + 1; l < j + 8; l += 2) {
								if (matrix[k][l] == 'B') result++;
							}
							temp = 0;
						}
					}
					temp = 0;
					for(int k = i; k < i + 8; k++) {
						if(temp == 0) {
							for (int l = j + 1; l < j + 8; l += 2) {
								if (matrix[k][l] == 'W') result++;
							}
							temp = 1;
						} else {
							for (int l = j; l < j + 8; l += 2) {
								if (matrix[k][l] == 'W') result++;
							}
							temp = 0;
						}
					}
				}
				arrayList.add(result);
			}
		}

		Collections.sort(arrayList);

		bw.write(String.valueOf(arrayList.get(0)));
		br.close();
		bw.close();
	}
}
*/
