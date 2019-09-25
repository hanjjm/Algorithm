import java.io.*;
		import java.util.StringTokenizer;

public class sampleTest {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		StringTokenizer st = new StringTokenizer(br.readLine());
		int squareSize = Integer.parseInt(st.nextToken());
		int rotationCount = Integer.parseInt(st.nextToken());

		String[][] matrix = new String[squareSize][squareSize];
		String[][] result = new String[squareSize][squareSize];

		for(int i = 0; i < squareSize; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < squareSize; j++) {
				matrix[i][j] = st.nextToken();
			}
		}

		int squareLength = squareSize;
		int direction = (rotationCount) / Math.abs(rotationCount);

		if(squareSize % 2 == 1) result[squareSize / 2][squareSize / 2] = matrix[squareSize / 2][squareSize / 2];

		for(int i = 0; i < squareSize / 2; i++) {
			int realRotation = Math.abs(rotationCount) % (squareLength * squareLength - (squareLength - 2) * (squareLength - 2));
			int xIndex = i, yIndex = i, index = 0;
			int rotationX = i, rotationY = i, rotationIndex = 0;

			if(direction < 0) {
				for(int k = 0; k < realRotation; k++) {
					if (rotationIndex < squareLength - 1) rotationX++;
					else if (rotationIndex < 2 * squareLength - 2) rotationY++;
					else if (rotationIndex < 3 * squareLength - 3) rotationX--;
					else if (rotationIndex < 4 * squareLength - 4) rotationY--;
					rotationIndex++;
				}
				for (int j = 0; j < (squareLength * squareLength - (squareLength - 2) * (squareLength - 2)); j++) {
					result[rotationX][rotationY] = matrix[xIndex][yIndex];
					if(index < squareLength - 1) xIndex++;
					else if(index < 2 * squareLength - 2) yIndex++;
					else if(index < 3 * squareLength - 3) xIndex--;
					else if(index < 4 * squareLength - 4) yIndex--;
					index++;

					if(rotationX == i && rotationY != i) rotationY--;
					else if(rotationX != i && rotationY == i + squareLength - 1) rotationX--;
					else if(rotationX == i + squareLength - 1 && rotationY != i + squareLength - 1) rotationY++;
					else if(rotationX != i + squareLength - 1  && rotationY == i) rotationX++;
				}
			} else {
				for(int k = 0; k < realRotation; k++) {
					if (rotationIndex < squareLength - 1) rotationY++;
					else if (rotationIndex < 2 * squareLength - 2) rotationX++;
					else if (rotationIndex < 3 * squareLength - 3) rotationY--;
					else if (rotationIndex < 4 * squareLength - 4) rotationX--;
					rotationIndex++;
				}
				for (int j = 0; j < (squareLength * squareLength - (squareLength - 2) * (squareLength - 2)); j++) {
					result[rotationX][rotationY] = matrix[xIndex][yIndex];
					if (index < squareLength - 1) yIndex++;
					else if (index < 2 * squareLength - 2) xIndex++;
					else if (index < 3 * squareLength - 3) yIndex--;
					else if (index < 4 * squareLength - 4) xIndex--;
					index++;

					if(rotationX == i && rotationY != i + squareLength - 1) rotationY++;
					else if(rotationX != i + squareLength - 1 && rotationY == i + squareLength - 1) rotationX++;
					else if(rotationX == i + squareLength - 1 && rotationY != i) rotationY--;
					else if(rotationX != i && rotationY == i) rotationX--;
				}
			}
			direction *= -1;
			squareLength -= 2;
		}

		for(int i = 0; i < squareSize; i++) {
			for(int j = 0; j < squareSize; j++) {
				bw.write(result[i][j]);
				if(j != squareSize - 1) bw.write(" ");
			}
			if(i != squareSize - 1) bw.write("\n");
		}
		bw.close();
		br.close();
	}
}
